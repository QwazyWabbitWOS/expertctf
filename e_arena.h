#ifndef _E_ARENA_H_
#define _E_ARENA_H_
/**
 * e_arena.h
 *
 * Prototypes for the arena subsystem
 */

void arenaInitLevel(void);  // called when a new level is entered
void arenaEndLevel(void); // called at the end of a level
void arenaConnect(edict_t *player); // called when a player connects
void arenaDisconnect(edict_t *player); // called when a player disconnects
void arenaKilled(edict_t *victim); // called when a player dies
void arenaSpawn(edict_t* player); // called by PutClientInServer during spawning/respawning
void arenaCountdown(void);
// determines whether a player can attack 
// and be damaged when in arena mode
qboolean arenaCombatAllowed(edict_t *player);

#endif