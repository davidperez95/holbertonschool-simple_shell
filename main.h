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
#include <stdarg.h>
#include <limits.h>

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
	void (*function_built)(void);
} built_t;

/**
 * struct functions - _printf structure
 *@op: Received options
 *@f: Pointer fuction
 */
typedef struct functions
{
	char *op;
	void (*f)(char *, va_list, int *);
} functions;

/* Prototypes */

char **tokenizer(char *line, char *delim);
char **find_path(char **environ);
char *_check_argv(char *command, char **envp);
char *read_line(char *line, size_t line_size, int status);
int execute_child(char **argv, int status);
void print_error(char *command);

/* string prototypes */
int _strlen(char *string);
int _strncmp(char *s1, char *s2, size_t n);
int _strcmp(char *s1, char *s2);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);

/* aux functions prototypes */
int prompt(void);
int _printf(const char *format, ...);
void all_free(char **argv, char **envp, char *line);
void *_calloc(unsigned int nmemb, unsigned int size);
void (*get_op_functions(char c))(char *, va_list, int *);
void op_string(char *buffer, va_list ap, int *bf_count);

/* built in functions prototypes */
void (*get_command(char *command))(void);
void env_func(void);
void help_func(void);

/* Macros */

#define TRUE 1
#define DELIM_PATH ":="
#define DELIM_LINE " \t\n"
#define EXIT "exit"
#define FILE_NOT_FOUND 32512

#endif /* MAIN_H */
