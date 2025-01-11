#include "shell.h"

/**
 * handle_exit - Exits the shell.
 * @args: Array of arguments (unused).
 */
void handle_exit(char **args)
{
	free(args);
	_exit(0);
}

/**
 * print_env - Prints the environment variables.
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
