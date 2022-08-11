#ifndef _MAIN_H_
#define _MAIN_H_

/* Librarys */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

/* Prototypes */

char **tokenizer(char *line);
char **find_path(char **environ);
int _strlen(char *string);
int prompt(void);

/* Macros */

#define TRUE 1
#define DELIM " "



#endif /* MAIN_H */
