#include "shell.h"
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>

/**
 * find_path - Searches for an executable file in the system PATH.
 * @cmd: The command to search for.
 * Return: Full path of the executable if found, NULL otherwise.
 */

char *find_path(char *cmd)
{
	char *path = getenv("PATH");
	char *path_copy = NULL, *dir = NULL, *full_path = NULL;
	struct stat buffer;

	if (!path)
		return (NULL);

	path_copy = strdup(path);
	dir = strtok(path_copy, ":");

	while (dir)
	{
		full_path = malloc(strlen(dir) + strlen(cmd) + 2);
		if (!full_path)
		{
			free(path_copy);
			return (NULL);
		}
		strcpy(full_path, dir);
		strcat(full_path, "/");
		strcat(full_path, cmd);

		if (stat(full_path, &buffer) == 0 && S_ISREG(buffer.st_mode) &&
(buffer.st_mode & S_IXUSR))
		{
			free(path_copy);
			return (full_path);
		}

		free(full_path);
		dir = strtok(NULL, ":");
	}

	free(path_copy);
	return (NULL);
}

