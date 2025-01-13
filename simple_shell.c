#include "shell.h"

int main(void)
{
	char *line = NULL, *command = NULL;
	size_t len = 0;
	ssize_t nread;

	while (1)
	{
		write(STDOUT_FILENO, "$ ", 2);

		nread = getline(&line, &len, stdin);
		if (nread == -1)
		{
			free(line);
			exit(EXIT_SUCCESS);
		}

		command = trim_whitespace(line);
		if (*command == '\0')
			continue;

		if (strcmp(command, "exit") == 0)
		{
			free(line);
			exit(EXIT_SUCCESS);
		}
		if (strcmp(command, "env") == 0)
		{
			print_env();
			continue;
		}

		execute_command(command);
	}

	free(line);
	return (0);
}
