#include "shell.h"

/**
 * main - Entry point for the shell program.
 * @argc: Argument count.
 * @argv: Array of argument strings.
 * Return: Always 0 on success.
 */
int main(int argc, char **argv)
{
	char *command;
	char **args;
	int status = 1;

	(void)argc; /* Unused */

	while (status)
	{
		shell_prompt();
		command = read_command();
		if (!command)
		{
			free(command);
			break;
		}

		args = parse_command(command);
		if (!args || !args[0])
		{
			free(command);
			free(args);
			continue;
		}

		if (strcmp(args[0], "exit") == 0)
			handle_exit(args);
		else if (strcmp(args[0], "env") == 0)
			print_env();
		else
			status = execute_command(args, argv[0]);

		free(command);
		free(args);
	}
	return (0);
}
