#include "shell.h"

/**
 * execute_command - Executes a command by forking a child process and using execvp.
 * @args: Array of arguments (command and its parameters).
 *
 * Return: 1 if command executed successfully, 0 if the shell should exit.
 */
int execute_command(char **args)
{
	pid_t pid;
	int status;
	if (args[0] == NULL)
		return (1);
	if (strcmp(args[0], "exit") == 0)
		return (handle_exit(args));
	if (strcmp(args[0], "env") == 0)
	{
		handle_env();
		return (1);
	}
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(1);
	}
	if (pid == 0)
	{
		if (execvp(args[0], args) == -1)
		{
			perror(args[0]);
			exit(1);
		}
	}
	else
	{
		waitpid(pid, &status, 0);
	}
	return (1);
}
/**
 * handle_exit - Handles the exit built-in command to terminate the shell.
 * @args: Arguments passed to the exit command (not used here).
 *
 * Return: 0 to exit the shell.
 */
int handle_exit(char **args)
{
	(void)args;
	exit(0);
}
/**
 * handle_env - Prints the current environment variables.
 *
 * Return: void
 */
void handle_env(void)
{
	extern char **environ;
	int i;
	for (i = 0; environ[i] != NULL; i++)
	{
		write(STDOUT_FILENO, environ[i], strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
}
