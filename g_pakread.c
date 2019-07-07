#include "g_local.h"
#include "g_pakread.h"

//qboolean searchForMapInPakFiles(char *mapName);
//qboolean searchForMapInPakFile(PAK *pak, char *mapName);
//void PakClose(PAK *pak);

// Main function to be called.  Enter a map name as a parameter
// and this function will return "true" if any pak files have
// that map...  otherwise it will return false
qboolean searchForMapInPakFiles(char *mapName)
{
	FILE *fPak;
	PAK *pPak;
	dpackfile_t *pFile;
	size_t i; 
	int count;
	
	//char *fileNameExt;
	char filename[MAX_QPATH]={0};
	char currentPakName[9];
	char currentFullPakName[MAX_QPATH];
	
	sprintf(filename,"%s.bsp",mapName);
	
	for (count = 0; count < 10; count++)
	{
		sprintf(currentPakName, "pak%i.pak", count);
		//sprintf(currentPakName, "pak%i.pak", count);
		sprintf(currentFullPakName, "%s/%s", gamedir->string, currentPakName);
		
		// Open the pak file for reading
		if ((fPak = fopen(currentFullPakName, "rb")) == NULL)
		{
			continue; 
		}
		
		// Allocate a PAK struct
		if ((pPak = (PAK *) calloc(1, sizeof(PAK))) == NULL)
		{
			fclose(fPak);
			continue;
		}
		
		// Read the header from the pak file
		if (fread(&pPak->header, PAK_HEADER_SIZE,1,fPak) != 1)
		{
			fclose(fPak);
			free(pPak);
			continue;
		}
		
		// Check and make sure we got a proper header
		if (pPak->header.ident != IDPAKHEADER)
		{
			fclose(fPak);
			free(pPak);
			continue;
		}
		
		// fseek past all of the file data
		if (fseek(fPak, pPak->header.dirofs-PAK_HEADER_SIZE,SEEK_CUR))
		{
			fclose(fPak);
			free(pPak);
			continue;
		}
		
		// Determine the number of files in the pak file
		pPak->dir.nfiles = pPak->header.dirlen/PAK_FILE_SIZE;
		pFile = pPak->dir.file; 
		
		for (i=0; i < pPak->dir.nfiles; i++, pFile++)
		{
			//gi.dprintf("Count loop - %i files %d\n", i, pPak->dir.nfiles);
			if (fread(pFile, PAK_FILE_SIZE, 1, fPak) != 1)
			{
				fclose(fPak);
				free(pPak);
				i = pPak->dir.nfiles;
				continue;
			}
		}
		
		fseek(fPak, 0L, SEEK_SET);
		pPak->fp = fPak;
		pPak->name = (char *) strdup(currentPakName); 
		//DEBUG CHECK
		//gi.dprintf("Pak name = %s\n", pPak->name);
		// Check to see if the map is in the current pak file.  If it is,
		// return "true", we are done.
		if (searchForMapInPakFile(pPak, filename) == true)
		{
			PakClose(pPak);
			//gi.dprintf("Map found in Pak %s\n", pPak->name);
			return(true);
		}
		else
		{
			PakClose(pPak);
		}
	}
	
	for (count = 0; count < 10; count++)
	{
		sprintf(currentPakName, "pak%i.pak", count);
		//sprintf(currentPakName, "pak%d.pak", count);
		
		sprintf(currentFullPakName, "%s/../baseq2/%s", gamedir->string,currentPakName);
		//DEBUG CHECKING
		//gi.dprintf("Current pakname - %s\n", currentFullPakName);
		// Open the pak file for reading
		if ((fPak = fopen(currentFullPakName, "rb")) == NULL)
		{
			continue; 
		}
		
		// Allocate a PAK struct
		if ((pPak = (PAK *) calloc(1, sizeof(PAK))) == NULL)
		{
			fclose(fPak);
			continue;
		}
		
		// Read the header from the pak file
		if (fread(&pPak->header, PAK_HEADER_SIZE,1,fPak) != 1)
		{
			fclose(fPak);
			free(pPak);
			continue;
		}
		
		// Check and make sure we got a proper header
		if (pPak->header.ident != IDPAKHEADER)
		{
			fclose(fPak);
			free(pPak);
			continue;
		}
		
		// fseek past all of the file data
		if (fseek(fPak, pPak->header.dirofs-PAK_HEADER_SIZE,SEEK_CUR))
		{
			fclose(fPak);
			free(pPak);
			continue;
		}
		
		// Determine the number of files in the pak file
		pPak->dir.nfiles = pPak->header.dirlen / PAK_FILE_SIZE;
		pFile = pPak->dir.file; 
		
		for (i=0; i < pPak->dir.nfiles; i++, pFile++)
		{
			if (fread(pFile, PAK_FILE_SIZE, 1, fPak) != 1)
			{
				i = pPak->dir.nfiles;
				fclose(fPak);
				free(pPak);
				continue;
			}
		}
		
		fseek(fPak, 0L, SEEK_SET);
		pPak->fp = fPak;
		pPak->name = (char *) strdup(currentPakName); 
		
		// Check to see if the map is in the current pak file.  If it is,
		// return "true", we are done.
		if (searchForMapInPakFile(pPak, filename) == true)
		{
			PakClose(pPak);
			//gi.dprintf("Map found in Pak %s\n", pPak->name);
			return(true);
		}
		else
		{
			PakClose(pPak);
		}
	}
	return(false);
} 

// Search for the mapName in the current pak file
// Return "true" if it is in there, otherwise "false"
qboolean searchForMapInPakFile(PAK *pak, char *mapName)
{
	int i; 
	
	// Loop through the maps in the pak file, comparing the names
	for (i=0; i < pak->dir.nfiles; i++)
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
			return(true);
		}
	}
	// Did not find the map in the pak file
	return(false);
} 

//========================================
// Close PAK file. Free memory.
//========================================
void PakClose(PAK *pak)
{
	if (pak)
	{
		if (pak->fp)
		{
			fclose(pak->fp);
		}
		free(pak->name);
		free(pak);
	}
} 
