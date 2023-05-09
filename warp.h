#ifndef WARP_H
#define WARP_H

void Cmd_Warp(edict_t *ent);   
void Cmd_Yes(edict_t *ent);
void Cmd_No(edict_t *ent);
void checkElectionTime(void);
void ListMaps(edict_t* ent);

extern qboolean electionInProgress; //QW// declared here for global access

#endif
