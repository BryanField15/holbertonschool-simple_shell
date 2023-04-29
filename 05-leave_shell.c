#include "main.h"

/**
 * leave_shell - builtin exit
 * @token_array: unused parameter
 * Return: always 0
 */

int leave_shell(__attribute__((unused))char **token_array)
{
	printf("address passed to exit is %p (*token_array)\n", *token_array);
	return (42);
}
