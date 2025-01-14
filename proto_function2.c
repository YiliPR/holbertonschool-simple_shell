#include "shell.h"

/**
 * search_in_path - Searches for a command in the PATH directories
 * @command: Command to search for
 *
 * Return: Full path of the command if found, NULL otherwise
 */

char *search_in_path(char *command)
{
	char *path = getenv("PATH");
	char *path_copy, *token, *full_path;
	size_t command_len = strlen(command);

	if (!path)
		return (NULL);

	path_copy = strdup(path);
	if (!path_copy)
		return (NULL);

	token = strtok(path_copy, ":");
	while (token)
	{
		full_path = malloc(strlen(token) + command_len + 2);
		if (!full_path)
		{
			free(path_copy);
			return (NULL);
		}

		sprintf(full_path, "%s/%s", token, command);
		if (access(full_path, X_OK) == 0)
		{
			free(path_copy);
			return (full_path);
		}

		free(full_path);
		token = strtok(NULL, ":");
	}

	free(path_copy);
	return (NULL);
}
