#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

extern char **environ;

void shell_prompt(void);
char *read_command(void);
char **parse_command(char *command);
int execute_command(char **args, char *program_name);
void handle_exit(char **args);
void print_env(void);

#endif /* SHELL_H */
