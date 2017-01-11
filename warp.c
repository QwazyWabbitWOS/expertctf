#include "g_local.h"  

// all for warp command (vote on map change)

// Differences from Zoid's warp command:
//
// a person alone on a server can do it
// doesn't wait for mouse click before changing map
// default electpercentage is 0 (disabled)
// uses sv prop instead of warp_list

char voteMap[MAX_QPATH];
int yesVotes, voteEndTime, numplayers = 0;
qboolean electionInProgress = false;
cvar_t *sv_electpercentage, *sv_votetime;//*sv_warp_list,

// big array, indexed by playernum
qboolean whoVoted[MAX_CLIENTS];

edict_t *warper = NULL;

void printelection(void)
{
    int voteTimeLeft, neededVotes = 0;

    gi.bprintf(PRINT_CHAT, "%s has requested warping to level %s.\n", 
	       warper->client->pers.netname, voteMap);
    gi.bprintf(PRINT_HIGH, "Type YES or NO to vote on this request.\n");

    voteTimeLeft = voteEndTime - (int)level.time;
    neededVotes = ceil(sv_electpercentage->value/100.*(numplayers - 1) - 
		       yesVotes);
    gi.bprintf(PRINT_HIGH, "Votes: %d  Needed: %d  Time left: %ds\n", 
	       yesVotes, neededVotes, voteTimeLeft);
}

void mapwins(void)
{
    electionInProgress = false;
    gi.bprintf(PRINT_HIGH, "%s is warping to level %s.\n", 
	       warper->client->pers.netname, voteMap);
    gi.AddCommandString(va("gamemap %s\n", voteMap));
}

void checkElectionTime(void)
{
    if (voteEndTime < (int)level.time){
	electionInProgress = false;
	gi.bprintf(PRINT_CHAT, "Election timed out and has been cancelled.\n");
    }
}


void Cmd_Warp(edict_t *ent)
{
    int i, voteStartTime;
    edict_t *player;
//    int pairs;
//    props_t *props;
    char *value;

    sv_electpercentage = gi.cvar("electpercentage", "0", CVAR_SERVERINFO);
	sv_votetime = gi.cvar("votetime", "60",0);

    if(! (int)sv_electpercentage->value){
	gi.cprintf(ent, PRINT_HIGH, "Elections are disabled\n");
	return;
    }

    if(electionInProgress){
	gi.cprintf(ent, PRINT_HIGH, "Election already in progress.\n");
	return;
    }

    //sv_warp_list = gi.cvar("warp_list", "", CVAR_SERVERINFO);

    if (gi.argc() == 1) {
	gi.cprintf(ent, PRINT_HIGH, "Usage:  warp mapname\n");
	gi.cprintf(ent, PRINT_HIGH, "like:   warp q2ctf1\n");
/*  	gi.cprintf(ent, PRINT_HIGH, "Available levels are:\n"); */

/*  	  props = gProperties; */
/*  	  pairs = listSize(props->keys); */
/*  	  for (i = 0; i < pairs; i++){ */
/*  	      value = (char *)listElementAt(props->values, i); */
/*  	      if(Q_stricmp(value, "remove") != 0) */
/*  		  gi.cprintf(ent, PRINT_HIGH, "%s\n",  */
/*  			     (char *)listElementAt(props->keys, i)); */
/*  	  } */
	return;
    }


    Com_sprintf(voteMap, sizeof(voteMap), "%s", gi.argv(1));

    value = getProp(gProperties, voteMap);
    if((! value) || (Q_stricmp(value, "remove") == 0)){
	gi.cprintf(ent, PRINT_HIGH, "Level not in map rotation.\n");
//	  gi.cprintf(ent, PRINT_HIGH, "Available levels are:\n");
//
//	  props = gProperties;
//	  pairs = listSize(props->keys);
//	  for (i = 0; i < pairs; i++){
//	      value = (char *)listElementAt(props->values, i);
//	      if(Q_stricmp(value, "remove") != 0)
//		  gi.cprintf(ent, PRINT_HIGH, "%s\n", 
//			     (char *)listElementAt(props->keys, i));
//	  }
//
	return;
    }				  

    numplayers = 0;
    for (i = 1; i <= game.maxclients; i++){
	player = &g_edicts[i];
	if (player->inuse && player->client)
	    numplayers++;
    }

    for (i = 0; i < game.maxclients; i++)
	whoVoted[i] = false;

    warper = ent;
    if(numplayers == 1)
	mapwins();
    else{
	yesVotes = 0;
	voteStartTime = (int)level.time;
	voteEndTime = voteStartTime + sv_votetime->value;
	electionInProgress = true;
	printelection();
    }

}

void Cmd_Yes(edict_t *ent)
{
    int playernum;

    if (!electionInProgress){
	gi.cprintf(ent, PRINT_HIGH, "No election is in progress.\n");
	return;
    }
    if (ent == warper){
	gi.cprintf(ent, PRINT_HIGH, "You can't vote for yourself.\n");
	return;
    }
    playernum = ent - g_edicts - 1;
    if (whoVoted[playernum]){
	gi.cprintf(ent, PRINT_HIGH, "You already voted.\n");
	return;
    }
    whoVoted[playernum] = true;
    yesVotes++;
    if ((float)yesVotes/(numplayers - 1) >= sv_electpercentage->value/100)
	mapwins();
    else
	printelection();
}

void Cmd_No(edict_t *ent)
{
    int playernum;

    if (!electionInProgress){
	gi.cprintf(ent, PRINT_HIGH, "No election is in progress.\n");
	return;
    }
    if (ent == warper){
	gi.cprintf(ent, PRINT_HIGH, "You can't vote for yourself.\n");
	return;
    }
    playernum = ent - g_edicts - 1;
    if (whoVoted[playernum]){
	gi.cprintf(ent, PRINT_HIGH, "You already voted.\n");
	return;
    }
    whoVoted[playernum] = true;
    printelection();
}


// g_cmds.c:ClientCommand()

          // begin warp
//	  else if (Q_stricmp(cmd, "warp") == 0)
//	      Cmd_Warp(ent);
//	  else if (Q_stricmp(cmd, "yes") == 0)
//	      Cmd_Yes(ent);
//	  else if (Q_stricmp(cmd, "no") == 0)
//	      Cmd_No(ent);
	  // end warp

//	  else    // anything that doesn't match a command will be a chat
//		  Cmd_Say_f (ent, false, true);

// in g_main.c:G_RunFrame()
//
//	  edict_t	*ent; 
//
//	  // begin warp
//	  extern qboolean electionInProgress;
//	  // end warp
//
//	  level.framenum++;

// in same function:
//
//	  if ((int)sv_arenaflags->value & EXPERT_ENABLE_ARENA) {
//		  arenaCountdown();
//	  }
//
//
//	  // begin warp
//	  if (electionInProgress)
//	      checkElectionTime();
//	  // end warp
//
//	  //
//	  // treat each object in turn
	
//add warp.o to the makefile:
//
//GAME_OBJS = \
//	  g_ai.o p_client.o g_cmds.o g_combat.o g_func.o g_items.o \
//	  g_main.o g_misc.o g_monster.o g_phys.o g_save.o g_spawn.o \
//	  g_target.o g_trigger.o g_utils.o g_weapon.o m_move.o p_hud.o \
//	  p_trail.o p_view.o p_weapon.o q_shared.o \
//	  e_arena.o e_game.o e_gbstat.o e_grapple.o e_id.o e_ftrack.o \
//	  e_matrix.o e_motd.o e_obit.o e_overlay.o e_team.o e_util.o \
//	  darray.o list.o props.o g_ctf.o p_menu.o g_svcmds.o \
//	  g_observe.o joe.o warp.o

// include warp.h in g_cmd.c:
//
//void Cmd_Warp(edict_t *ent);   
//void Cmd_Yes(edict_t *ent);
//void Cmd_No(edict_t *ent);
