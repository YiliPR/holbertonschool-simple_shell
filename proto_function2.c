#include "shell.h"

/**
 * handle_env - prints the current environment.
 * @envp: the environment variables.
 * Return: void.
 */
void handle_env(char **envp)
{
	int i;

	for (i = 0; envp[i]; i++)
	{
		printf("%s\n", envp[i]);
	}
}
