# Minishell

A bash-like command-line interpreter written in C that replicates core shell functionality.

## Description

Minishell is a simplified implementation of a Unix shell that provides command-line interpretation, environment variable expansion, input/output redirection, pipes, and heredocs. The project implements both built-in commands and external command execution with proper signal handling and memory management.

## Features

- Interactive command-line interface using GNU Readline
- Command history navigation
- Environment variable expansion (`$VAR`, `$?`)
- Input/output redirections (`<`, `>`, `>>`)
- Heredocs (`<<`)
- Pipes (`|`) for chaining commands
- Signal handling (CTRL+C, CTRL+D, CTRL+\\)
- Built-in commands:
  - `cd` - change directory
  - `echo` - display text (with `-n` flag support)
  - `env` - display environment variables
  - `exit` - exit the shell
  - `export` - set environment variables
  - `pwd` - print working directory
  - `unset` - remove environment variables
- External command execution via PATH resolution
- Quote handling (single and double quotes)

## Building

```bash
cd mini-shell
make
```

This will compile the project and create the `minishell` executable.

## Usage

```bash
./minishell
```

Once running, you can enter commands just like in bash:

```bash
minishell$ echo "Hello World"
Hello World
minishell$ ls -la | grep mini
minishell$ cat << EOF > file.txt
> line 1
> line 2
> EOF
minishell$ export MY_VAR=value
minishell$ echo $MY_VAR
value
minishell$ exit
```

## Development

### Build Commands

- `make` - Build the project
- `make clean` - Remove object files
- `make fclean` - Remove object files and executable
- `make re` - Rebuild from scratch
- `make valgrind` - Run with valgrind for memory leak detection
- `make valchild` - Run with valgrind including child process tracking

### Project Structure

```
mini-shell/
├── includes/
│   └── minishell.h          # Main header file
├── libraries/
│   └── libft/               # Custom C library
├── src/
│   ├── parsing/             # Input parsing and command preparation
│   └── execution/           # Command execution and built-ins
├── Makefile
└── functions.txt            # Reference for allowed external functions
```

## Requirements

- GNU Readline library
- GCC compiler
- Make

## Memory Management

The project is designed to be memory-leak free. Use the provided valgrind targets to verify:

```bash
make valgrind
```

## Author

This project was developed as part of the 42 school curriculum.
