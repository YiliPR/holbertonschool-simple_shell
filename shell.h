#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

/* Function Prototypes */
void display_prompt(void);
char *read_command(void);
void execute_command(char *command, char **envp);
void handle_env(char **envp);

#endif /* SHELL_H */
