# holbertonschool-simple_shell

## Description

This repository contains the files to simulate a basic Unix Shell with its respective commands. It is made to carry out the C - Simple Shell project at [Holberton School](https://www.holbertonschool.com/)

The predominantly used calls are read, write, open, execve, exit, fork, free, malloc, getline, isatty, perror, strtok, and wait.

## Flowchart

![Shell Flowchart](/Holbertonschool-simple-shell/shell_flowchart.jpg)

## Process Description

The next steps are a brief description about how the shell works:

1. Select between interactive mode or non-interactive mode through the isatty() call.
2. If it is interactive mode, the prompt function is executed so that the user then inserts the command
3. The received command is evaluated and sent to a selector function to check if it is built-in or not
4. A token process is performed to the command and the PATH to then pass them through stat verification
5. The child process is created and the command is executed inside the child process, while the parent process waits
6. Finally, the child process terminates and the parent process returns to the prompt function.

## Requirements:

Operating System: [Ubuntu 20.04](https://releases.ubuntu.com/20.04/)
Compiler: [GCC](https://gcc.gnu.org/)

## General Project

- Allowed editors: vi, vim, emacs
- All your files will be compiled on Ubuntu 20.04 LTS using gcc, using the options -Wall -Werror -Wextra -pedantic -std=gnu89
- All your files should end with a new line
- A README.md file, at the root of the folder of the project is mandatory
- Your code should use the Betty style. It will be checked using [betty-style.pl](https://github.com/holbertonschool/Betty/blob/master/betty-style.pl) and [betty-doc.pl](https://github.com/holbertonschool/Betty/blob/master/betty-doc.pl)
- Your shell should not have any memory leaks
- No more than 5 functions per file
- All your header files should be include guarded
- Use system calls only when you need to ([why](https://www.quora.com/Why-are-system-calls-expensive-in-operating-systems))

## Compiling, Debugging and Runing

- Use gcc compiler, with -Wall -Werror -Wextra -pedantic -std=gnu89 flags
- If you want to debugging the shell, use valgrind:

valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all ./main

- To run the program type: 

./main

- To check the Shell manual type: 

man ./man_1_simple_shell

## Files Description

- hsh.c
	- Inside this file is the main function of the program
- main.h
	- Inside this file are the prototypes, structures, global variables and macros used in the program.
- functions_str.c
	- In this file are the local functions of the library <string.h>
- functions_help.c
	- In this file are the support functions for the main function
- function_aux.c
	- In this file are the helper functions
- built_in.c
	- In this file are the functions of the built in commands

## Examples

Here are shown some examples of the usage of the Shell:

- ls

`($) ls
 AUTHORS    'Shell flowchart.jpg'   built_in.c        functions_help.c   hsh.c   main.h               practice
 README.md   _printf.c              functions_aux.c   functions_str.c    main    man_1_simple_shell`

- /bin/ls

`($) ls
 AUTHORS    'Shell flowchart.jpg'   built_in.c        functions_help.c   hsh.c   main.h               practice
 README.md   _printf.c              functions_aux.c   functions_str.c    main    man_1_simple_shell`

## Authors:

- David Andres Perez Cruz - [davidperez95](https://github.com/davidperez95)
- Manuel Esteban Rodriguez Castro - [ManuRodriguezC](https://github.com/ManuRodriguezC)
