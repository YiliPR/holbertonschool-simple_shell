#include "shell.h"

/**
 * shell_prompt - Displays the shell prompt.
 */

void shell_prompt(void)
{
	write(STDOUT_FILENO, "$ ", 2);
}

/**
 * read_command - Reads a command line from the user.
 * Return: Pointer to the input command string.
 */

char *read_command(void)
{
	char *buffer = NULL;
	size_t size = 0;

	if (getline(&buffer, &size, stdin) == -1)
	{
		free(buffer);
		return (NULL);
	}
	return (buffer);
}

/**
 * parse_command - Splits a command line into arguments.
 * @command: Pointer to the input command string.
 * Return: Array of pointers to arguments.
 */

char **parse_command(char *command)
{
	char **args = NULL;
	char *token;
	size_t i = 0;

	args = malloc(1024 * sizeof(char *));
	if (!args)
		return (NULL);

	token = strtok(command, " \t\n");
	while (token)
	{
		args[i++] = token;
		token = strtok(NULL, " \t\n");
	}
	args[i] = NULL;
	return (args);
}
