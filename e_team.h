#ifndef E_TEAM_H
#define E_TEAM_H
/*
 * Expert Quake2 Teamplay code.
 */

// shortcuts used for games limited to a
// specific number of teams, eg CTF
#define NOTEAM -1
#define TEAM1 0
#define TEAM2 1 
#define TEAM3 2 

// Max number of teams
#define MAX_TEAMS				32

// Filename to store team setup
#define TEAM_FILENAME		"teams.txt"

qboolean teamplayEnabled(void);
qboolean playerIsOnATeam(edict_t *player);
qboolean onSameTeam(edict_t *player1, edict_t *player2);
qboolean validSkinName(char *skinName);
char *nameForTeam(int team);
int teamForName(char *teamName);
int memberCount(int team);
void teamSound(int team, int soundIndex, float volume);
void teamPrint(int team, int priority, char *message);
void InitTeamAudio(void);
void ExpertTeamAudioInit(void);

void loadTeams(void);
void assignTeam(edict_t *player);
void assignToTeam(edict_t *player, int teamToAssign);
void addPlayerToTeam(edict_t *player, int team);
void removePlayerFromTeam(edict_t *player);
void teamDisconnect(edict_t *player);

void killAndSwitchTeam(edict_t *player, int desiredTeam);
void enforceTeamModelSkin(edict_t *player);

void Cmd_Team_f(edict_t *player);
void Cmd_TeamAudio_f(edict_t *player);
void Cmd_Examine_Teams(edict_t *player);

// Array of possible teams.  The .team field in ent->client->resp 
// is an index into this array. Note -1 or any negative number 
// indicates an invalid team.
typedef struct
{
	// name of team, case insensitive
	char *teamName;
	// paths for _either_ skins or models
	char *skinPaths;
	int skinPathLength;
	int memberCount;
	// unused: meant to be pointer to list of team members
	edict_t *teamList;
} gteam_t;

extern gteam_t gTeams[MAX_TEAMS]; 

#endif
