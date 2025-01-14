#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

extern char **environ;

void execute_command(char *command);
char *search_in_path(char *command);
void print_environment(void);

#endif /* SHELL_H */
