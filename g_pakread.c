#include "g_local.h"
#include "g_pakread.h"

// Primary map search function. This drives the pak searches
// by passing the path and map name to the pak search function.
qboolean searchForMapInPakFiles(char* mapName)
{
	char Pakpath[MAX_QPATH];
	qboolean stat = false;

	// Search first in mod directory, then in baseq2.
	sprintf(Pakpath, "%s", gamedir->string);
	stat = searchFormedPathPakFiles(mapName, Pakpath);
	if (stat)
		return stat;
	else {
		sprintf(Pakpath, "%s/../baseq2", gamedir->string);
		return searchFormedPathPakFiles(mapName, Pakpath);
	}
}

qboolean searchFormedPathPakFiles(char* mapName, char* path)
{
	FILE* fPak = NULL;
	PAK* pPak = { 0 };
	dpackfile_t* pFile;
	int i;
	int count;
	qboolean stat = false;

	char filename[MAX_QPATH] = { 0 };
	char currentPakName[9];
	char currentFullPakName[MAX_QPATH];

	sprintf(filename, "%s.bsp", mapName);

	for (count = 0; count < 10; count++)
	{
		sprintf(currentPakName, "pak%i.pak", count);
		sprintf(currentFullPakName, "%s/%s", path, currentPakName);

		// Open the pak file for reading
		if ((fPak = fopen(currentFullPakName, "rb")) == NULL)
		{
			continue;
		}

		// Allocate a PAK struct
		if ((pPak = (PAK*)gi.TagMalloc(sizeof(PAK), TAG_LEVEL)) == NULL)
		{
			fclose(fPak);
			continue;
		}

		// Read the header from the pak file
		if (fread(&pPak->header, PAK_HEADER_SIZE, 1, fPak) != 1)
		{
			fclose(fPak);
			gi.TagFree(pPak);
			continue;
		}

		// Check and make sure we got a proper header
		if (pPak->header.ident != IDPAKHEADER)
		{
			fclose(fPak);
			gi.TagFree(pPak);
			continue;
		}

		// fseek past all of the file data
		if (fseek(fPak, pPak->header.dirofs - PAK_HEADER_SIZE, SEEK_CUR))
		{
			fclose(fPak);
			gi.TagFree(pPak);
			continue;
		}

		// Determine the number of files in the pak file
		pPak->dir.nfiles = pPak->header.dirlen / PAK_FILE_SIZE;
		pFile = pPak->dir.file;

		for (i = 0; i < pPak->dir.nfiles; i++, pFile++)
		{
			//gi.dprintf("Count loop - %i files %d\n", i, pPak->dir.nfiles);
			if (fread(pFile, PAK_FILE_SIZE, 1, fPak) != 1)
			{
				i = pPak->dir.nfiles;
				fclose(fPak);
				gi.TagFree(pPak);
				continue;
			}
		}

		fseek(fPak, 0L, SEEK_SET);
		pPak->fp = fPak;
		pPak->name = (char*)strdup(currentPakName);
		//gi.dprintf("Checking pak name = %s\n", pPak->name);
		stat = searchForMapInPakFile(pPak, filename);
		PakClose(pPak);
		if (stat)
			return stat; // we found one
	}
	return stat;
}

// Search for the mapName in the current pak file
// Return "true" if it is in there, otherwise "false"
qboolean searchForMapInPakFile(PAK* pak, char* mapName)
{
	int i;

	// Loop through the maps in the pak file, comparing the names
	for (i = 0; i < pak->dir.nfiles; i++)
	{
		// Make sure the current item in the pak file starts with "maps/",
		// and if so, check to see if it's the map we are looking for
		/*
		//DEBUG CHECKING
		if ((strncmp(pak->dir.file[i].name, "maps/", 5) == 0))
		{
			gi.dprintf("file %s Maprequest %s\n", pak->dir.file[i].name, mapName);
			gi.dprintf("file5 %s Maprequest %s\n", pak->dir.file[i].name + 5, mapName);
			//gi.dprintf("%i\n" strncmp(pak->dir.file[i].name + 5, mapName, strlen(pak->dir.file[i].name) - 5) == 0));
		}
		*/
		if ((strncmp(pak->dir.file[i].name, "maps/", 5) == 0) &&
			strncmp(pak->dir.file[i].name + 5, mapName, strlen(pak->dir.file[i].name) - 5) == 0)
		{
			// Found the map in the pak file
			return true;
		}
	}
	// Did not find the map in the pak file
	return false;
}

//========================================
// Close PAK file. Free memory.
//========================================
void PakClose(PAK* pak)
{
	if (pak)
	{
		if (pak->fp)
		{
			fclose(pak->fp);
		}
		gi.TagFree(pak);
	}
}
