# Simple Shell

## Overview
This project is a simple shell implementation in C that provides basic functionality found in most Unix-based command-line interfaces. The shell supports executing user input commands, managing environment variables, and handling simple built-in commands like `exit` and `env`.

## Features

- **Prompt display**: The shell displays a prompt (`$ `) to the user.
- **Command execution**: Executes commands entered by the user using the `execve` system call.
- **Environment variables**: The shell can print environment variables with the `env` command.
- **Built-in commands**: Supports `exit` to terminate the shell and `env` to print environment variables.
- **Error handling**: Includes error handling for invalid commands and execution failures.

## Getting Started

### Prerequisites

- You need a C compiler (e.g., GCC) to compile the shell.
- Make sure you have access to a Unix-based system (Linux/macOS) or a compatible environment.

### Installation
``
1. **Clone the repository**:

   ```bash
   git clone https://github.com/holbertonschool/simple_shell.git
   cd simple_shell

2. **Compile the code**:

Use the following command to compile the shell code:
```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

3. Run the shell:

After compiling, you can run your shell with:

./hsh

This will start the shell, and you will see the prompt ($ ).

### Usage

Once the shell is running, you can enter commands:

1. Execute commands: Type any command, e.g., ls, pwd, etc., after the prompt. For example:

$ ls

This will execute the ls command and display the directory contents.

2. Exit the shell: Type exit to exit the shell:

$ exit

3. Display environment variables: Type env to print the environment variables:

$ env

###Functions Implemented

Here’s a brief overview of the functions implemented in the shell:

display_prompt: Displays the shell prompt ($ ).
read_command: Reads a line of input from the user.
execute_command: Executes a single-word command entered by the user.
handle_env: Prints the current environment variables.

### Authors

Eli Figueroa
