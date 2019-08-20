#include "holberton.h"

/**
 * _which - locates a command
 *
 * @cmd: command name
 * Return: location of the command.
 */
char *_which(char *cmd)
{
	char *path, *ptr_path, *token_path, *dir;
	int len_dir, len_cmd;
	struct stat st;

	if (cmd == NULL)
		return (NULL);

	if (stat(cmd, &st) == 0)
		return (cmd);

	path = _getenv("PATH");
	ptr_path = _strdup(path);
	len_cmd = _strlen(cmd);
	token_path = _strtok(ptr_path, ":");

	while (token_path != NULL)
	{
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
