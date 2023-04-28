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

/**
 * struct list_s - singly linked list
 * @str: string - (malloc'ed string)
 * 
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 */
typedef struct list_s
{
	char *str;
	int len;
	struct list_s *next;
} list_t;

extern char **environ;

void init_shell(void);
char *read_line();
char *trim_line(char *line);
char **make_token(char *trimmed, char *delim);

list_t *add_node_end(list_t **head, const char *str);
list_t *add_node(list_t **head, const char *str);

/*int _execve(char **token_array);
 */
int run_command(char **token_array);

char *get_path(char *command);

/* built_in */
int check_builtin_cmd(char **token_array);
int print_env(char **token_array);
int leave_shell(char **token_array);
int change_wd(char **token_array);

#endif
