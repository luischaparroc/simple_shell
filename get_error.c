#include "holberton.h"

/**
 * get_error - calls the error according the builtin, syntax or permission
 * @args: type pointer array of agrs
 * @eval: error value
 * Return: error
 */
int get_error(char **args, int eval)
{
	char *error;

	switch (eval)
	{
	case 1:
		error = error_get_alias(args);
		break;
	case 2:
		error = error_env(args);
		break;
	case 3:
		error = error_permission(args);
	case 4:
		error = error_not_found(args);
		break;
	case 5:
		error = error_get_cd(args);
		break;
	case 6:
		error = error_syntax(args);
		break;
	case 7:
		error = error_exit_shell(args);
		break;
	}
	write(STDERR_FILENO, error, _strlen(error));
	if (error)
		free(error);
	return (eval);
}
