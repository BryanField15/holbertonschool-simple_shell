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
int _execve(char *user_input);
int run_command(char *input);
int is_space(char *str);
char* trim_line(char* line);

#endif /* _MAIN_H_ */
