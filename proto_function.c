#include "shell.h"

/**
 * display_prompt - displays the shell prompt to the user.
 * Return: void.
 */
void display_prompt(void)
{
	printf("$ ");
	fflush(stdout);
}

/**
 * read_command - reads a line of input from the user.
 * Return: the user input (command), or NULL if EOF is encountered.
 */
char *read_command(void)
{
	char *line = NULL;
	size_t len = 0;

	if (getline(&line, &len, stdin) == -1)
	{
		free(line);
		return (NULL);
	}

	line[strcspn(line, "\n")] = '\0';
	return (line);
}

/**
 * execute_command - executes a given command using execve.
 * @command: the command to be executed.
 * @envp: the environment variables to be passed to the command.
 * Return: void. The function does not return on successful execution.
 */
void execute_command(char *command, char **envp)
{
	pid_t pid;
	int status;
	char *args[2];

	if (access(command, X_OK) != 0)
	{
		fprintf(stderr, "%s: command not found\n", command);
		return;
	}

	args[0] = command;
	args[1] = NULL;

	pid = fork();
	if (pid == 0)
	{
		if (execve(command, args, envp) == -1)
		{
			perror("execve");
			exit(EXIT_FAILURE);
		}
	}
	else if (pid > 0)
		waitpid(pid, &status, 0);
	else
		perror("fork");
}

/**
 * handle_env - prints the current environment.
 * @envp: the environment variables.
 * Return: void.
 */
void handle_env(char **envp)
{
	int i;

	for (i = 0; envp[i]; i++)
		printf("%s\n", envp[i]);
}
