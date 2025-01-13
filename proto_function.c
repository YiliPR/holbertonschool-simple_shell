#include "shell.h"

/**
 * execute_command - Executes a command by searching PATH and using execve
 * @command: The command to execute
 */
void execute_command(char *command)
{
	pid_t pid;
	char *path = NULL;

	path = find_command_path(command);
	if (path == NULL)
	{
		write(STDERR_FILENO, command, strlen(command));
		write(STDERR_FILENO, ": command not found\n", 20);
		return;
	}

	pid = fork();
	if (pid == 0)
	{
		char *argv[] = {path, NULL};
		if (execve(path, argv, environ) == -1)
		{
			perror(command);
			free(path);
			exit(EXIT_FAILURE);
		}
	}
	else if (pid > 0)
	{
		wait(NULL);
	}
	else
	{
		perror("fork");
	}

	free(path);
}
