#include "shell.h"
void execute_command(char *command)
{
	char *argv[20];
	char *path = getenv("PATH"), *full_path;
	char *token = strtok(path, ":");
	pid_t pid;
	int argc = 0;

	argv[argc++] = strtok(command, " ");
	while ((argv[argc++] = strtok(NULL, " ")) != NULL);

	argv[--argc] = NULL;

	if (argv[0][0] == '/' && access(argv[0], X_OK) == 0)
	{
		pid = fork();
		if (pid == 0)
		{
			execve(argv[0], argv, environ);
			perror("execve");
			exit(EXIT_FAILURE);
		}
		else if (pid > 0)
		{
			wait(NULL);
			return;
		}
		perror("fork");
		return;
	}

	while (token)
	{
		full_path = malloc(strlen(token) + strlen(argv[0]) + 2);
		sprintf(full_path, "%s/%s", token, argv[0]);
		if (access(full_path, X_OK) == 0)
		{
			pid = fork();
			if (pid == 0)
			{
				execve(full_path, argv, environ);
				perror("execve");
				exit(EXIT_FAILURE);
			}
			else if (pid > 0)
			{
				wait(NULL);
				free(full_path);
				return;
			}
			perror("fork");
			free(full_path);
			return;
		}
		free(full_path);
		token = strtok(NULL, ":");
	}

	write(STDERR_FILENO, argv[0], strlen(argv[0]));
	write(STDERR_FILENO, ": command not found\n", 20);
}

/**
 * print_env - Prints the current environment variables
 */
void print_env(void)
{
	char **env = environ;

	while (*env)
	{
		write(STDOUT_FILENO, *env, strlen(*env));
		write(STDOUT_FILENO, "\n", 1);
		env++;
	}
}
