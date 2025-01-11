#include "shell.h"

/**
 * main - The main entry point for the shell program.
 * @argc: The number of command-line arguments (not used here).
 * @argv: An array of strings containing the command-line arguments (not used here).
 *
 * Return: 0 on successful execution.
 */

int main(int argc, char *argv[])
{
	char *input;
	char **args;
	int status = 1;

	(void)argc;
	(void)argv;

	while (status)
	{
		prompt_user();
		input = get_input();
		args = parse_input(input);

		status = execute_command(args);

		free(input);
		free(args);
	}
	return (0);
}
