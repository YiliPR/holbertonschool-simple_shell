#include "shell.h"

/**
 * find_command_path - Searches the PATH for a command
 * @command: The command to find
 *
 * Return: The full path of the command, or NULL if not found
 */
char *find_command_path(char *command)
{
	char *path = getenv("PATH");
	char *path_copy = NULL, *dir = NULL;
	char *full_path = NULL;

	if (path == NULL)
		return (NULL);

	path_copy = strdup(path);
	if (path_copy == NULL)
		return (NULL);

	dir = strtok(path_copy, ":");
	while (dir != NULL)
	{
		full_path = malloc(strlen(dir) + strlen(command) + 2);
		if (full_path == NULL)
		{
			free(path_copy);
			return (NULL);
		}

		sprintf(full_path, "%s/%s", dir, command);

		/* Check if the command is executable */
		if (access(full_path, X_OK) == 0)
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
