#include "shell.h"

/**
 * execute_command - Executes a command
 * @command: The command to execute
 */
void execute_command(char *command)
{
	char *argv[2];
	char *path_command = NULL;
	pid_t pid;

	argv[0] = command;
	argv[1] = NULL;

	if (access(command, X_OK) == 0)
	{
		path_command = command;
	}
	else
	{
		path_command = search_in_path(command);
		if (!path_command)
		{
			write(STDERR_FILENO, command, strlen(command));
			write(STDERR_FILENO, ": command not found\n", 20);
			return;
		}
	}

	pid = fork();
	if (pid == 0)
	{
		execve(path_command, argv, environ);
		perror("execve");
		exit(EXIT_FAILURE);
	}
	else if (pid > 0)
	{
		wait(NULL);
	}
	else
	{
		perror("fork");
	}

	if (path_command != command)
		free(path_command);
}

/**
 * print_environment - Prints the current environment variables
 */
void print_environment(void)
{
	char **env = environ;

	while (*env)
	{
		write(STDOUT_FILENO, *env, strlen(*env));
		write(STDOUT_FILENO, "\n", 1);
		env++;
	}
}
