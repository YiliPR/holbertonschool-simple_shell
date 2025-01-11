#include "shell.h"

/**
 * prompt_user - Displays a shell prompt to the user.
 *
 * Return: void
 */
void prompt_user(void)
{
	write(STDOUT_FILENO, "$ ", 2);
}

/**
 * get_input - Reads input from the user.
 *
 * Return: A string containing the user input.
 */
char *get_input(void)
{
	char *input = NULL;
	size_t size = 0;

	if (getline(&input, &size, stdin) == -1)
	{
		if (feof(stdin))
		{
			write(STDOUT_FILENO, "\n", 1);
			exit(0);
		}
		perror("getline");
		exit(1);
	}
	return (input);
}

/**
 * parse_input - Tokenizes the user input string into an argument array.
 * @input: The input string.
 *
 * Return: An array of arguments (strings).
 */
char **parse_input(char *input)
{
	char **args;
	char *token;
	int position = 0;

	args = malloc(sizeof(char *) * 64);
	if (!args)
	{
		perror("malloc");
		exit(1);
	}

	token = strtok(input, " \t\r\n\a");
	while (token != NULL)
	{
		args[position] = token;
		position++;

		token = strtok(NULL, " \t\r\n\a");
	}
	args[position] = NULL;
	return (args);
}
