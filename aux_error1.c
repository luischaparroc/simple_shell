#include "holberton.h"

/**
 * error_get_cd - error message for cd command in get_cd
 * @args: type array of args that is passed to the command.
 * Return: Error
 */
char *error_get_cd(char **args)
{
	int count = 0;
	int length;
	char *error;
	char *ver_str;

	ver_str = aux_itoa(count);
	if (ver_str == 0)
		return (NULL);

	if (args[0][0] == '-')
		args[0][2] = '\0';
	length = _strlen(prgname) + _strlen(ver_str) + _strlen(args[0]) + 20;
	error = malloc(sizeof(char) * (length + 1));
	if (error == 0)
	{
		free(ver_str);
		return (NULL);
	}
	_strcpy(error, prgname);
	_strcat(error, ": ");
	_strcat(error, ver_str);
	if (args[0][0] == '-')
		_strcat(error, ": cd: not found ");
	else
		_strcat(error, ": cd: not found ");
	_strcat(error, args[0]);
	_strcat(error, "\n");
	free(ver_str);
	return (error);
}
/**
 * error_not_found - generic error message for command not found
 * @args: type array of args that is passed to the command.
 * Return: Error
 */
char *error_not_found(char **args)
{
	int count = 0;
	int length;
	char *error;
	char *ver_str;

	ver_str = aux_itoa(count);
	if (ver_str == 0)
		return (NULL);
	length = _strlen(prgname) + _strlen(ver_str) + _strlen(args[0]) + 16;
	error = malloc(sizeof(char) * (length + 1));
	if (error == 0)
	{
		free(ver_str);
		return (NULL);
	}
	_strcpy(error, prgname);
	_strcat(error, ": ");
	_strcat(error, ver_str);
	_strcat(error, ": ");
	_strcat(error, args[0]);
	_strcat(error, ": not found\n");
	free(ver_str);
	return (error);
}
/**
 * error_exit_shell - generic error message for exit in get_exit
 * @args: type array of args that is passed to the command.
 * Return: Error
 */
char *error_exit_shell(char **args)
{
	int count = 0;
	int lenght;
	char *error;
	char *ver_str;

	ver_str = aux_itoa(count);
	if (ver_str == 0)
		return (NULL);
	lenght = _strlen(prgname) + _strlen(ver_str) + _strlen(args[0]) + 30;
	error = malloc(sizeof(char) * (lenght + 1));
	if (error == 0)
	{
		free(ver_str);
		return (NULL);
	}
	_strcpy(error, prgname);
	_strcat(error, ": ");
	_strcat(error, ver_str);
	_strcat(error, ": command failed to execute");
	_strcat(error, args[0]);
	_strcat(error, "\n");
	free(ver_str);
	return (error);
}
