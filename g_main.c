
#include "g_local.h"
#include "g_pakread.h"
#include "warp.h"
/*
#ifdef WIN32   // Needed for non-Winblows compatibility
   #include <windows.h>
   #ifdef __GL__   // If OpenGL is enabled, then include the GL header file
      #include <gl.h>
   #endif
#endif
*/
game_locals_t	game;
level_locals_t	level;
game_import_t	gi;
game_export_t	globals;
spawn_temp_t	st;

int		sm_meat_index;
int		snd_fry;
int		meansOfDeath;

edict_t	*g_edicts;

cvar_t  *sv_autorestart;
cvar_t  *restartcfg;
cvar_t	*deathmatch;
cvar_t	*coop;
cvar_t	*dmflags;
cvar_t	*skill;
cvar_t	*fraglimit;
cvar_t	*timelimit;
cvar_t	*password;
cvar_t	*maxclients;
cvar_t	*maxentities;
cvar_t	*g_select_empty;
cvar_t	*dedicated;

cvar_t	*filterban;	// Expert - IP banning code from id sources

cvar_t	*sv_maxvelocity;
cvar_t	*sv_gravity;

cvar_t	*sv_rollspeed;
cvar_t	*sv_rollangle;
cvar_t	*gun_x;
cvar_t	*gun_y;
cvar_t	*gun_z;

cvar_t	*run_pitch;
cvar_t	*run_roll;
cvar_t	*bob_up;
cvar_t	*bob_pitch;
cvar_t	*bob_roll;

cvar_t	*sv_cheats;

/*
cvar_t *sv_fogenabled;
cvar_t *sv_fogclipping;
cvar_t *sv_fogred;
cvar_t *sv_foggreen;
cvar_t *sv_fogblue;
cvar_t *sv_fogdensity;
*/
void SpawnEntities (char *mapname, char *entities, char *spawnpoint);
void ClientThink (edict_t *ent, usercmd_t *cmd);
qboolean ClientConnect (edict_t *ent, char *userinfo);
void ClientUserinfoChanged (edict_t *ent, char *userinfo);
void ClientDisconnect (edict_t *ent);
void ClientBegin (edict_t *ent);
void ClientCommand (edict_t *ent);
void RunEntity (edict_t *ent);
void WriteGame (char *filename, qboolean autosave);
void ReadGame (char *filename);
void WriteLevel (char *filename);
void ReadLevel (char *filename);
void InitGame (void);
void G_RunFrame (void);


//===================================================================

//edict_t *player;
void ShutdownGame (void)
{	
	
	char command[64] = {0};

	// Expert: stop gibstats logging
	if ( (int)sv_utilflags->value & EXPERT_ENABLE_GIBSTAT_LOGGING)
			gsStopLogging();
	
	// Expert: Deallocate the teamplay stuff
	if (expflags & EXPERT_ENFORCED_TEAMS)
			shutdownTeamplay();
	
	gi.cprintf(NULL, PRINT_HIGH,"==== ShutdownGame ====\n");

	if(sv_autorestart->value == 1 && Q_stricmp(restartcfg->string, ""))
	{
		gi.FreeTags (TAG_LEVEL);
		gi.FreeTags (TAG_GAME);
		gi.cprintf(NULL, PRINT_HIGH,"==== Loading %s ====\n",restartcfg->string);
		Com_sprintf (command, sizeof(command), "exec \"%s\"\n",restartcfg->string);
		gi.AddCommandString(command);
		gi.cprintf(NULL, PRINT_HIGH,"==== Server restarted ====\n");
	}
	else
	{

		gi.cprintf(NULL, PRINT_HIGH,"autorestart must be set to 1 to enable auto restarting\n");
		gi.cprintf(NULL, PRINT_HIGH,"Check that the file \"%s\" is located in %s folder\n", restartcfg->string, gamedir->string);	
		gi.cprintf(NULL, PRINT_HIGH,"==== Server Shutdown ====\n");
		gi.FreeTags (TAG_LEVEL);
		gi.FreeTags (TAG_GAME);
	}

#ifdef _WIN32
	OutputDebugString("ShutdownGame() was called.\n");
	OutputDebugString("Memory stats since startup.\n");
	_CrtMemDumpStatistics(&startup1);
	_CrtDumpMemoryLeaks();
#endif

}

/*
=================
GetGameAPI

Returns a pointer to the structure with all entry points
and global variables
=================
*/
game_export_t *GetGameAPI (game_import_t *import)
{
	gi = *import;

	globals.apiversion = GAME_API_VERSION;
	globals.Init = InitGame;
	globals.Shutdown = ShutdownGame;
	globals.SpawnEntities = SpawnEntities;

	globals.WriteGame = WriteGame;
	globals.ReadGame = ReadGame;
	globals.WriteLevel = WriteLevel;
	globals.ReadLevel = ReadLevel;

	globals.ClientThink = ClientThink;
	globals.ClientConnect = ClientConnect;
	globals.ClientUserinfoChanged = ClientUserinfoChanged;
	globals.ClientDisconnect = ClientDisconnect;
	globals.ClientBegin = ClientBegin;
	globals.ClientCommand = ClientCommand;

	globals.RunFrame = G_RunFrame;

	globals.ServerCommand = ServerCommand;

	globals.edict_size = sizeof(edict_t);
/*
#ifdef __GL__ // Check if GL is enabled
	//BD 6/24/98 - Fog using OpenGL
	{
		GLfloat fogColor[] = {sv_fogred->value, sv_foggreen->value, sv_fogblue->value, 1}; // Setup array for fog color of grey
		//GLfloat fogColor[] = {0.2, 0.2, 0.2, 1}; // Setup array for fog color of grey

		glFogi (GL_FOG_MODE, GL_LINEAR);// Fog fade in is linear (this looks best IMHO)
		glFogfv (GL_FOG_COLOR, fogColor);// Set the fog color in GL
		glFogf (GL_FOG_DENSITY, sv_fogdensity->value);     // Set the default density
		glHint (GL_FOG_HINT, GL_DONT_CARE);// Set the default calculation mode to best possible
		glFogf (GL_FOG_START, 1);           // Start the near fog clipping plane to 1
		glFogf (GL_FOG_END, sv_fogclipping->value);// Set the far clipping plane to the server setting
		
	}
	glClearColor ( sv_fogred->value, sv_foggreen->value, sv_fogblue->value, 1.0); // Clear the background color to the fog color

#endif      // End of GL code
*/
	return &globals;

}

#ifndef GAME_HARD_LINKED
// this is only here so the functions in q_shared.c and q_shwin.c can link
void Sys_Error (char *error, ...)
{
	va_list		argptr;
	char		text[1024];

	va_start (argptr, error);
	vsprintf (text, error, argptr);
	va_end (argptr);

	gi.error (ERR_FATAL, "%s", text);
}

void Com_Printf (char *msg, ...)
{
	va_list		argptr;
	char		text[1024];

	va_start (argptr, msg);
	vsprintf (text, msg, argptr);
	va_end (argptr);

	gi.dprintf ("%s", text);
}

#endif

//======================================================================


/*
=================
ClientEndServerFrames
=================
*/
void ClientEndServerFrames (void)
{
	int		i;
	edict_t	*ent;

	// calc the player views now that all pushing
	// and damage has been added
	for (i=0 ; i<maxclients->value ; i++)
	{
		ent = g_edicts + 1 + i;
		if (!ent->inuse || !ent->client)
			continue;
		ClientEndServerFrame (ent);
	}

}

/*
=================
EndDMLevel

The timelimit or fraglimit has been exceeded
=================
*/
void EndDMLevel (void)
{
	edict_t		*ent;

	// stay on same level flag
	if ((int)dmflags->value & DF_SAME_LEVEL)
	{
		ent = G_Spawn ();
		ent->classname = "target_changelevel";
		ent->map = level.mapname;
	}
	else if (level.nextmap[0])
	{	// go to a specific map
		ent = G_Spawn ();
		ent->classname = "target_changelevel";
		ent->map = level.nextmap;
	}
	else
	{	// search for a changeleve
		ent = G_Find (NULL, FOFS(classname), "target_changelevel");
		if (!ent)
		{	// the map designer didn't include a changelevel,
			// so create a fake ent that goes back to the same level
			ent = G_Spawn ();
			ent->classname = "target_changelevel";
			ent->map = level.mapname;
		}
	}

	BeginIntermission (ent);
}

/*
=================
CheckDMRules
=================
*/
void CheckDMRules (void)
{
	int			i;
	gclient_t	*cl;

	if (level.intermissiontime)
		return;

	if (!deathmatch->value)
		return;

	if (timelimit->value)
	{
		if (level.time >= timelimit->value*60)
		{
			gi.bprintf (PRINT_HIGH, "Timelimit hit.\n");
			EndDMLevel ();
			return;
		}
	}

	// Expert CTF
	// Level ends according to number of captures
	if (ctf->value) {
		if (CTFCheckRules()) {
			EndDMLevel ();
		}
	}

	if (fraglimit->value)
	{
		for (i=0 ; i<maxclients->value ; i++)
		{
			cl = game.clients + i;
			if (!g_edicts[i+1].inuse)
				continue;

			if (cl->resp.score >= fraglimit->value)
			{
				gi.bprintf (PRINT_HIGH, "Fraglimit hit.\n");
				EndDMLevel ();
				return;
			}
		}
	}
}


/*
=============
ExitLevel
=============
*/
void ExitLevel (void)
{
	int		i;
	edict_t	*ent;
	char	command [256], *nextLevel;
	qboolean mapexists;
	mapexists = false;
	// Expert : level cycles.  If a property is defined that matches 
	// the current level's name, go to that level.
	// FIXME : MapExists() sanity check?
	
	//gi.dprintf("gProperties string value = %s\n",gProperties);
	//gi.dprintf("gProperties keys string value = %s\n",gProperties->keys);
	//gi.dprintf("gProperties values value = %s\n",gProperties->values);

	nextLevel = getProp(gProperties, level.mapname);
	gi.cprintf(NULL,PRINT_HIGH,"Property pair value for %s is %s\n",level.mapname, nextLevel);
	if (gProperties) //&& nextLevel != NULL)
	{
		mapexists = searchForMapInPakFiles(nextLevel);
		if(mapexists == true)
		{
			gi.cprintf(NULL,PRINT_HIGH,"Level cycling: current level %s\n"
		   "Found property with value %s\n"
	   	   "Going to level %s\n", level.mapname, nextLevel, nextLevel);
			level.changemap = nextLevel;
		}
		else
		{
			//gi.dprintf("**Map isnt in a Pak**\n");
		}
		
		if(mapexists == false)
		{
			mapexists = MapExists(nextLevel);
			//gi.dprintf("%s sent to mapexists\n", nextLevel);
			if(mapexists == true)
			{
				gi.cprintf(NULL,PRINT_HIGH,"Level cycling: current level %s\n"
			   "Found property with value %s\n"
	   		   "Going to level %s\n", level.mapname, nextLevel, nextLevel);
				level.changemap = nextLevel;
			}
			else //property doesnt have a pair
			{
				//mapexists = MapExists(level.mapname);
				//gi.dprintf("%s sent to mapexists\n", level.mapname);
				gi.cprintf(NULL,PRINT_HIGH,"Level cycling: current level %s\n"
					   "Didn't Find a property with value %s\n"
						"THE MAP DOESNT EXIST,DEFAULTING TO CURRENT LEVEL\n", level.mapname, nextLevel);
				level.changemap = level.mapname;
			}
		}
	}
	else
	{
		gi.cprintf(NULL,PRINT_HIGH,"Level cycling: current level %s\n"
					   "but no properties are set for the map\n"
	   				   "RELOADING TO CURRENT LEVEL\n", level.mapname);
			level.changemap = level.mapname;
	}

	// Expert Level Scripting
	ExpertLevelScripting(level.changemap);
	Com_sprintf (command, sizeof(command), "gamemap \"%s\"\n", level.changemap);
	gi.AddCommandString (command);
	level.changemap = NULL;
	level.exitintermission = 0;
	level.intermissiontime = 0;
	ClientEndServerFrames ();

	// clear some things before going to next level
	for (i=0 ; i<maxclients->value ; i++)
	{
		ent = g_edicts + 1 + i;
		if (!ent->inuse)
			continue;
		if (ent->health > ent->client->pers.max_health)
			ent->health = ent->client->pers.max_health;
	}
}


qboolean MapExists(char *mapname)
{
	FILE *mfile;
	char filename[MAX_QPATH]={0};

		// Build filename
	if (gProperties)
	{	
		//check baseq2/maps then ctf/maps
		sprintf(filename,"baseq2/maps/%s.bsp",mapname);
		// Try to open the bsp file
		if ((mfile = fopen(filename, "rb")) == NULL) 
		{
			gi.cprintf(NULL,PRINT_HIGH,"Bsp File doesn't exist in baseq2/maps, trying %s/maps!\n", gamedir->string);
			//gi.dprintf("gamedir str %s \n",gamedir->string);
			
			sprintf(filename,"%s/maps/%s.bsp",gamedir->string,mapname);
			if ((mfile = fopen(filename, "rb")) == NULL) 
			{
				gi.cprintf(NULL,PRINT_HIGH,"Bsp File doesn't exist in %s/maps!\n", gamedir->string);
				return false;
			}
			else 
			{
				fclose(mfile);
				//gi.dprintf("Bsp File exists, Continue with Load\n");
				return true;
			}
		}
		else 
		{
			fclose(mfile);
			//gi.dprintf("Bsp File exists, Continue with Load\n");
			return true;
		}
	}
	else
	{
		//gi.dprintf("sv prop Properties are missing, unable to test for next map.\n");
		return false;
	}

}
/*
================
G_RunFrame

Advances the world by 0.1 seconds
================
*/
void G_RunFrame (void)
{
	edict_t	*ent;
	extern qboolean electionInProgress;
	edict_t	*player;				// Spider: player "object"

	int	i = 0;
	int	count = 0;				// Spider: Number of connected players
	int	teamcount[2] = { 0 };	// Spider: Number of player in each team
	int	minutes, seconds;		// Spider: Info for the timer indicator
	char	ch[4];					// Spider: String with player id
	static char	team1list[40];	// Spider: String with player id list
	static char	team2list[40];	// Spider: String with player id list
	static char	speclist[40];	// Spider: String with player id list

	level.framenum++;
	level.time = level.framenum*FRAMETIME;

	// choose a client for monsters to target this frame
	AI_SetSightClient ();

	// exit intermissions

	if (level.exitintermission)
	{
		ExitLevel ();
		return;
	}

	//map warping
	if (electionInProgress)
	      checkElectionTime();

	// Expert Arena 
	if ((int)sv_arenaflags->value & EXPERT_ENABLE_ARENA) {
		arenaCountdown();
	}

	//
	// treat each object in turn
	// even the world gets a chance to think
	//
	ent = &g_edicts[0];
	for (i=0 ; i<globals.num_edicts ; i++, ent++)
	{
		if (!ent->inuse)
			continue;

		level.current_entity = ent;

		VectorCopy (ent->s.origin, ent->s.old_origin);

		// if the ground entity moved, make sure we are still on it
		if ((ent->groundentity) && (ent->groundentity->linkcount != ent->groundentity_linkcount))
		{
			ent->groundentity = NULL;
			if ( !(ent->flags & (FL_SWIM|FL_FLY)) && (ent->svflags & SVF_MONSTER) )
			{
				M_CheckGround (ent);
			}
		}

		if (i > 0 && i <= maxclients->value)
		{
			ClientBeginServerFrame (ent);
			continue;
		}

		G_RunEntity (ent);
	}

	// see if it is time to end a deathmatch
	CheckDMRules ();

	// build the playerstate_t structures for all players
	ClientEndServerFrames ();


	// Spider: update timeleft in gspy
	if ((level.framenum % 10 == 1) && (deathmatch->value)) {	// once every second

		minutes = (int)timelimit->value - (int)level.time/60;
		seconds = (int)((int)timelimit->value*60 - (int)level.time)%60;

		if (timelimit->value > 0) {

			if (minutes-1 > 0) {	// Spider: if minutes is not negative

				if ((seconds < 10) && (seconds >= 0))
					gi.cvar_forceset("Timeleft", va("%i:0%i", minutes - 1, seconds));
				else
					gi.cvar_forceset("Timeleft", va("%i:%i", minutes - 1, seconds));

			} else {
				gi.cvar_forceset("Timeleft", "Time limit reached");

				// Spider: count the number of connected client
				for (i = 0, player = g_edicts + 1; i < maxclients->value; i++, player++) {
					if (player->inuse)
						count++;
				}

				if (count == 0)
					ExitLevel();
			}

		} else if (timelimit->value == 0)
			gi.cvar_forceset("Timeleft", "No time limit");
		else
			gi.cvar_forceset("Timeleft", "Invalid");

	}
	
	// Spider: update TeamXList in gspy
	if ((level.framenum % 150 == 1) && (deathmatch->value) && (ctf->value)) { // once every 15 seconds

		count = 0;
		strcpy(team1list, "Red: -");
		strcpy(team2list, "Blue: -");
		strcpy(speclist, "Spec: -");

		for (i = 0, player = g_edicts + 1; i < maxclients->value; i++, player++) {
			if (!player->inuse)
				continue;

			count++;
			teamcount[TEAM1] = 0;
			teamcount[TEAM2] = 0;

			if(count < 10)
			{
				ch[0] = (char)(count + 48);				// Spider: (char)(48) = '0'
				ch[1] = '-';
				ch[2] = '\0';
			}
			else if((count >= 10) && (count < 100))
			{
				ch[0] = (char)(count / 10 + 48);
				ch[1] = (char)(count % 10 + 48);			// Spider: (char)(48) = '0'
				ch[2] = '-';
				ch[3] = '\0';
			}
			else
				strcpy(ch, "...");

			if (player->client->resp.team == TEAM1)
			{
				teamcount[TEAM1]++;
				strcat(team1list, ch);
			}
			else if (player->client->resp.team == TEAM2)
			{
				teamcount[TEAM2]++;
				strcat(team2list, ch);
			}
			else if (player->client->resp.team == NOTEAM)
				strcat(speclist, ch);
		}

		if(SvEvenTeam->value && (teamcount[TEAM1] != teamcount[TEAM2]))
			sv_paused->value = 1;

		gi.cvar_forceset("Team1List", team1list);
		gi.cvar_forceset("Team2List", team2list);
		gi.cvar_forceset("SpecList", speclist);
	}

	// Spider: verify if server is passworded
	if ((level.framenum % 300 == 1) && (deathmatch->value)) { // once every 30 seconds
		if (Q_stricmp(password->string, "none") && Q_stricmp(password->string, ""))
			gi.cvar_forceset("needpass", "1");
		else
			gi.cvar_forceset("needpass", "0");
	}
//#define GL_FOG                            0x0B60
//#define GL_FOG_INDEX                      0x0B61
//#define GL_FOG_DENSITY                    0x0B62
//#define GL_FOG_START                      0x0B63
//#define GL_FOG_END                        0x0B64
//#define GL_FOG_MODE                       0x0B65
//#define GL_FOG_COLOR                      0x0B66
/*

#ifdef __GL__ // Check if GL is enabled
//BD 6/24/98 - Fog using OpenGL
	{
		if(sv_fogred->value > 1 || sv_fogred->value < 0)
		{
			gi.dprintf("valid red fog color option 0.0 to 1.0 resetting to default\n");
			gi.cvar_forceset("sv_fogred->value", "0.2");
		}
		if(sv_foggreen->value > 1 || sv_foggreen->value < 0)
		{
			gi.dprintf("valid green fog color option 0.0 to 1.0 resetting to default\n");
			gi.cvar_forceset("sv_foggreen" ,"0.2");
		}
		if(sv_fogblue->value > 1 || sv_fogblue->value < 0)
		{
			gi.dprintf("valid blue fog color option 0.0 to 1.0 resetting to default\n");
			gi.cvar_forceset("sv_fogblue","0.2");
		}
		
		GLfloat fogColor[] = {sv_fogred->value, sv_foggreen->value, sv_fogblue->value, 1}; // Setup array for fog color of grey
		//GLfloat fogColor[] = {0.2, 0.2, 0.2, 1}; // Setup array for fog color of grey

		glFogi (GL_FOG_MODE, GL_LINEAR);// Fog fade in is linear (this looks best IMHO)
		glFogfv (GL_FOG_COLOR, fogColor);// Set the fog color in GL
		glFogf (GL_FOG_DENSITY, sv_fogdensity->value);     // Set the default density
		glHint (GL_FOG_HINT, GL_DONT_CARE);// Set the default calculation mode to best possible
		glFogf (GL_FOG_START, 1);           // Start the near fog clipping plane to 1
		glFogf (GL_FOG_END, sv_fogclipping->value);// Set the far clipping plane to the server setting
		
	}
	glClearColor ( sv_fogred->value, sv_foggreen->value, sv_fogblue->value, 1.0); // Clear the background color to the fog color
#endif
*/
}

