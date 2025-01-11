#include "shell.h"

/**
 * execute_command - Executes a command using execve after checking the path.
 * @args: Array of arguments for the command.
 * @program_name: Name of the shell program (argv[0]).
 * Return: 1 on success, 0 on failure.
 */

int execute_command(char **args, char *program_name)
{
	pid_t pid;
	int status;
	char *path = args[0];
	char *full_path = NULL;

	if (access(path, F_OK) == 0)
	{
		full_path = path;
	}
	else
	{
		full_path = find_path(path);
	}

	if (full_path)
	{
		pid = fork();
		if (pid == 0)
		{
			if (execve(full_path, args, environ) == -1)
			{
				fprintf(stderr, "%s: 1: %s: not found\n", program_name, args[0]);
				exit(EXIT_FAILURE);
			}
		}
		else if (pid < 0)
		{
			perror("Error");
		}
		else
		{
			wait(&status);
		}
		free(full_path);
	}
	else
	{
		fprintf(stderr, "%s: 1: %s: not found\n", program_name, args[0]);
	}
	return (1);
}
