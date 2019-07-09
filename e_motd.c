#include <stdio.h>
#include "g_local.h"

char *motd = NULL; // initialized at startup

// InitMOTD: Initializes the MOTD during InitGame from ExpertGameInits
void InitMOTD(void)
{
	FILE* motdfile;
	int motdChars;
	char* here;
	int c;

	if (motd == NULL)
	{
		motdfile = OpenGamedirFile(gamedir->string, va("%s/%s", levelCycle->string, EXPERT_MOTD_FILENAME), "r");

		if (motdfile)
		{
			motdChars = 0;
			if (motdfile != NULL)
			{
				while ((c = fgetc(motdfile)) != EOF)
					motdChars++;
			}
			else
			{
				gi.dprintf("Unable to open MOTD file.\n");
				motd = NULL;
				return;
			}

			motd = gi.TagMalloc(motdChars + 1, TAG_GAME);
			gi.dprintf("Allocating %i bytes for MOTD\n", motdChars + 1);
			here = motd;

			// Now load in the MOTD file.  Nul-terminate the string.
			if (motdfile)
			{
				rewind(motdfile);
				while ((c = fgetc(motdfile)) != EOF)
				{
					*here = c;
					here++;
					motdChars--;
				}
				fclose(motdfile);
			}

			*here = '\0';

			if (motdChars != 0)
				gi.dprintf("MOTD error: off by %d characters", motdChars);
		}
	}
}

// DisplayMOTD: Display the MOTD to the client
void DisplayMOTD(edict_t *client)
{
	if (motd)
		gi.centerprintf(client, "Quake 2 Expert v%s\n\n%s", EXPERT_VERSION, motd);
	else
		gi.centerprintf(client, "Quake 2 Expert v%s\n", EXPERT_VERSION);
}

// DisplayRespawnLine: Displays an info line on respawn
void DisplayRespawnLine(edict_t *client)
{
	gi.cprintf(client, PRINT_MEDIUM, "Expert %s - \"help\" for info\n", GAMESTRING);
}

void DisplaySettings(edict_t *client)
{
	int i;
	qboolean firstPrint = true;

	gi.cprintf(client, PRINT_MEDIUM, "The following options are in effect: ");
	
	for (i = 0; i < NUM_SETTINGS; i++) {
		if (expflags & (1 << i)) {
			if (firstPrint) {
				gi.cprintf(client, PRINT_MEDIUM, "%s", e_bits[i]);
				firstPrint = false;
			} else {
				gi.cprintf(client, PRINT_MEDIUM, ", %s", e_bits[i]);
			}
		}
	}

	gi.cprintf(client, PRINT_MEDIUM, "\n");

	gi.cprintf(client, PRINT_MEDIUM, "Pace multiplier is %.2f\n", pace);
	gi.cprintf(client, PRINT_MEDIUM, "Lethality multiplier is %.2f\n", lethality);
}

