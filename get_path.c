#include "main.h"

/**
 *get_path - handles the path variable and only forks if it is found
 *@command:
 *
 *Return: NULL
 */

char *get_path(char *command)
{
    char *path_env = getenv("PATH");
    char *path = strtok(path_env, ":");
    char *full_path = NULL;
    struct stat sb;

    while (path != NULL)
    {
	    full_path = malloc(strlen(path) + strlen(command) + 2);
	    if (full_path == NULL)
	    {
		    perror("malloc");
		    exit(EXIT_FAILURE);
	    }
	    sprintf(full_path, "%s/%s", path, command);
	    if (stat(full_path, &sb) == 0 && sb.st_mode & S_IXUSR)
	    {
		    return (full_path);
	    }
	    free(full_path);
	    path = strtok(NULL, ":");
    }
    return (NULL);
}
