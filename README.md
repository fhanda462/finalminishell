# Minishell

This project has been created as part of the 42 curriculum by fhanda and hazali.
---

## Description 

**Minishell** is a shell implementation in C that replicates the core functionalities of Bash (Posix version).

The shell interprets user commands, manages environment variables, handles input/output redirections, executes pipelines, and supports logical operators. It provides an interactive interface with command history and proper signal management.

**Key features:**
- Command execution with PATH resolution
- Built-in commands (`echo`, `cd`, `pwd`, `export`, `unset`, `env`, `exit`)
- Input/output redirections (`<`, `>`, `>>`, `<<`)
- Pipelines (`|`) and logical operators (`&&`, `||`)
- Environment variable expansion (`$VAR`, `$?`)
- Signal handling (`Ctrl+C`, `Ctrl+D`, `Ctrl+\`)
- Quote handling (single `'` and double `"`)


## Instructions

### Prerequisites

You need the `readline` library installed on your system.

### Compilation 
```bash
make
```

Launch the shell:

```bash
./minishell
```

Use it like a regular shell. Type `exit` or Ctrl + D to quit.

### Cleaning

```bash
make clean    # Remove object files
make fclean   # Remove all compiled files
make re       # Recompile everything
```

## Resources

### Documentation

- [Bash Reference Manual](https://www.gnu.org/software/bash/manual/bash.html)
- [POSIX Shell Specification](https://pubs.opengroup.org/onlinepubs/9699919799/utilities/V3_chap02.html)
- [readline Library Documentation](https://tiswww.case.edu/php/chet/readline/rltop.html)

### Tutorials
- [Minishell: Building a mini-bash](https://m4nnb3ll.medium.com/minishell-building-a-mini-bash-a-42-project-b55a10598218) - A complete guide by m4nnb3ll
- [Mes conseils si je devais recommencer minishell](https://medium.com/@mostafa.omrane/mes-conseils-si-je-devais-recommencer-minishell-a9783c51ba1b) - Tips and advice by Mostafa Omrane

### AI Usage
AI (Claude 4.5 Sonnet) was used as a debugging and learning tool for:

**What AI helped with:**
- Fixing memory leaks detected by Valgrind
- Debugging edge cases in variable expansion and quote handling
- Explaining complex pointer operations and POSIX standards
- Explaining and exemples how does the normal shell lexer/parser works
- Helped writing the Readme file