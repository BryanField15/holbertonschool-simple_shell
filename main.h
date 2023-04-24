#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

char *read_line();
void init_shell(void);
int _execve(char *user_input);
int run_command(char* input);

#endif /* _MAIN_H_ */
