#include "holberton.h"

/**
 * get_error - calls the error according the builtin, syntax or permission
 * @datash: data structure that contains arguments
 * @eval: error value
 * Return: error
 */
int get_error(data_shell *datash, int eval)
{
	char *error;
	char **args = NULL;

	switch (eval)
	{
	case -1:
		error = error_env(datash);
		break;
	case 1:
		error = error_get_alias(args);
		break;
	case 126:
		error = error_permission(args);
		break;
	case 127:
		error = error_not_found(datash);
		break;
	case 2:
		error = error_exit_shell(datash);
		break;
	}

	if (error)
	{
		write(STDERR_FILENO, error, _strlen(error));
		free(error);
	}

	datash->status = eval;
	return (eval);
}
