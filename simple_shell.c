#include "shell.h"

/**
 * main - entry point of the shell program.
 * @argc: number of arguments passed to the program.
 * @argv: array of arguments passed to the program.
 * @envp: array of environment variables.
 * Return: 0 on success.
 */

int main(int argc, char **argv, char **envp)
{
	char *command;

	(void)argc;
	(void)argv;

	while (1)
	{
		display_prompt();

		command = read_command();
		if (!command)
		{
			printf("\n");
			break;
		}

		if (strcmp(command, "exit") == 0)
		{
			free(command);
			break;
		}

		if (strcmp(command, "env") == 0)
			handle_env(envp);
		else
			execute_command(command, envp);

		free(command);
	}

	return (0);
}
