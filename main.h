#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <ctype.h>

/**
 * struct builtin_func - structure of built-in functions
 * @name: name
 * @func: functions
 */
typedef struct builtin_func
{
        char *name;
        int (*f)(char **token_array);
} func_t;

extern char **environ;

void init_shell(void);
char *read_line();
char *trim_line(char *line);
char **make_token(char *trimmed, char *delim);

int _execve(char **token_array);
int run_command(char **token_array);

char *get_path(char *command);

/* built_in */
int check_builtin_cmd(char **token_array);
int print_env(char **token_array);
int leave_shell(char **token_array);


#endif
