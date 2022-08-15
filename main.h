#ifndef _MAIN_H_
#define _MAIN_H_

/* Librarys */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <string.h>

/* Global variable */

extern char **environ;

/* Structure */

/**
 * struct built - builtin structure
 * @command: Received command
 * @function_built: Pointer to function
 */
typedef struct built
{
	char *command;
	int (*function_built)(char *command);
} built_t;

/* Prototypes */

char **tokenizer(char *line, char *delim);
char **find_path(char **environ);
int _strlen(char *string);
int _strcmp(char *s1, char *s2);
char *_strcpy(char *dest, char *src);
int _strncmp(char *s1, char *s2, size_t n);
int prompt(void);
void all_free(char **argv, char **envp, char *line);
int (*get_command(char *command));
int env_func(void);

/* Macros */

#define TRUE 1
#define DELIM_PATH ":="
#define DELIM_LINE " \t\n"
#define EXIT "exit"

#endif /* MAIN_H */
