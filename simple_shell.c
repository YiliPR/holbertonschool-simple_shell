#include "shell.h"

int main(void)
{
	char *line = NULL;
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

		line[nread - 1] = '\0';
		if (strcmp(line, "exit") == 0)
		{
			free(line);
			exit(EXIT_SUCCESS);
		}

		if (strcmp(line, "env") == 0)
		{
			print_environment();
			continue;
		}

		execute_command(line);
	}

	free(line);
	return (0);
}
