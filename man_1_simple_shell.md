.TH SIMPLE_SHELL 1 "January 2025" "1.0" "Simple Shell"
.SH NAME
simple_shell \- A simple command line shell

.SH SYNOPSIS
.B simple_shell
.RI [ "arg1" "arg2" ... ]
.SH DESCRIPTION
The simple_shell is a command line shell that reads and executes commands typed by the user. It supports basic commands, the ability to execute system commands, and built-in commands such as \fIexit\fR and \fIenv\fR. It provides a simple interface to interact with the Unix environment.

.SH COMMANDS

The following commands are supported:

.TP
.B exit
Exit the shell.
.TP
.B env
Display the current environment variables.

.SH USAGE

1. **Run the shell**:
   After compiling the shell program, you can execute the shell by running the following:

   .RS 4
   ./hsh
   .RE

2. **Execute a command**:
   Type any command (e.g., `ls`, `pwd`) after the prompt (`$ `) and press Enter. The command will be executed.

   .RS 4
   $ ls
   .RE
   This will execute the `ls` command and show the directory contents.

3. **Exit the shell**:
   To exit the shell, type the `exit` command.

   .RS 4
   $ exit
   .RE

4. **Display environment variables**:
   Type `env` to display all current environment variables.

   .RS 4
   $ env
   .RE

.SH EXIT STATUS
The exit status of the shell is `0` on success, and `1` on failure.

.SH AUTHORS
This manual page was written by:

- **Eli Figueroa**

.SH SEE ALSO
.BR sh (1),
.BR bash (1),
.BR execve (2),
.BR fork (2),
.BR getenv (3)
