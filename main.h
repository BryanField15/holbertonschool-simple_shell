#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include <ctype.h>

char *read_line();
void init_shell(void);
int _execve(char **token_array);
int run_command(char **token_array);
char* trim_line(char* line);
char **make_token(char *trimmed, char *delim);
#endif /* _MAIN_H_ */
