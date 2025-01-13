#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <ctype.h>

extern char **environ;

char *trim_whitespace(char *str);
void execute_command(char *command);
void print_env(void);

#endif /* SHELL_H */
