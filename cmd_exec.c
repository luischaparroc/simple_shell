#include "holberton.h"

/**
 * is_cdir - checks ":" if is in the current directory.
 * @path: type char pointer char.
 * @i: type int pointer of index.
 * Return: 1 if the path is searchable in the cd, 0 otherwise.
 */


int is_cdir(char *path, int *i)
{
	if (path[*i] == ':')
		return (1);

	while (path[*i] != ':')
	{
		*i += 1;
	}

	*i += 1;

	return (0);
}

/**
 * _which - locates a command
 *
 * @cmd: command name
 * Return: location of the command.
 */
char *_which(char *cmd)
{
	char *path, *ptr_path, *token_path, *dir;
	int len_dir, len_cmd, i;
	struct stat st;

	if (cmd == NULL)
		return (NULL);

	path = _getenv("PATH");
	ptr_path = _strdup(path);
	len_cmd = _strlen(cmd);
	token_path = _strtok(ptr_path, ":");
	i = 0;

	while (token_path != NULL)
	{
		if (is_cdir(path, &i))
			if (stat(cmd, &st) == 0)
				return (cmd);

		len_dir = _strlen(token_path);
		dir = malloc(len_dir + len_cmd + 2);
		_strcpy(dir, token_path);
		_strcat(dir, "/");
		_strcat(dir, cmd);
		_strcat(dir, "\0");

		if (stat(dir, &st) == 0)
			return (dir);

		free(dir);
		token_path = _strtok(NULL, ":");
	}
	free(ptr_path);

	if (stat(cmd, &st) == 0)
		return (cmd);

	return (NULL);
}

/**
 * cmd_exec - executes command lines
 *
 * @args: arguments
 * @input: input arguments
 * Return: 1 on success.
 */
int cmd_exec(char **args, char *input)
{
	pid_t pd;
	pid_t wpd;
	int state;
	char *dir;

	(void) wpd;
	pd = fork();

	if (pd == 0)
	{
		dir = _which(args[0]);

		if (dir != NULL)
			execve(dir, args, NULL);

		perror("lsh: not found");
		free(dir);
		free(input);
		free(args);
		exit(EXIT_FAILURE);
	}
	else if (pd < 0)
	{
		free(input);
		free(args);
		perror("lsh");
	}
	else
	{
		do {
			wpd = waitpid(pd, &state, WUNTRACED);
		} while (!WIFEXITED(state) && !WIFSIGNALED(state));
	}

	return (1);
}
