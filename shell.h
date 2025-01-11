#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

void prompt_user(void);
char *get_input(void);
char **parse_input(char *input);
int execute_command(char **args);
int handle_exit(char **args);
void handle_env(void);

#endif
