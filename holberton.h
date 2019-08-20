#ifndef _HOLBERTON_
#define _HOLBERTON_

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>

#define BUFSIZE 1024
#define TOK_BUFSIZE 128
#define TOK_DELIM " \t\r\n\a"

/* Points to an array of pointers to strings called the "environment" */
extern char **environ;

/* global char variable for handle errors */
char *prgname;

/**
 * struct builtin_s - Builtin struct for command args.
 * @name: The name of the command builtin i.e cd, exit, env
 * @f: data type pointer function.
 */
typedef struct builtin_s
{
	char *name;
	int (*f)(char **argv);
} builtin_t;

/* aux_str functions */
char *_strcat(char *dest, const char *src);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strchr(char *s, char c);
int _strspn(char *s, char *accept);

/* aux_mem.c */
void _memcpy(void *newptr, const void *ptr, unsigned int size);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char **_reallocdp(char **ptr, unsigned int old_size, unsigned int new_size);

/* aux_str2.c */
char *_strdup(const char *s);
int _strlen(const char *s);
int cmp_chars(char str[], const char *delim);
char *_strtok(char str[], const char *delim);

/* shell_loop.c */
void shell_loop(void);

/* read_line.c */
char *read_line(void);

/* split_line.c */
char **split_line(char *input);

/* get_line.c */
void bring_line(char **lineptr, size_t *n, char *buffer, size_t j);
ssize_t get_line(char **lineptr, size_t *n, FILE *stream);

/* exec_line */
int exec_line(char **args, char *input);

/* cmd_exec.c */
char *_which(char *cmd);
int cmd_exec(char **args, char *input);

/* env1.c */
char *_getenv(const char *name);
int _env(char **args);

/* get_builtin */
int (*get_builtin(char *cmd))(char **args);

/* _exit.c */
int exit_shell(char **args);

/* aux_stdlib.c */
int get_len(int n);
char *aux_itoa(int n);

/* aux_error1.c */
char *error_get_cd(char **args);
char *error_not_found(char **args);
char *error_exit_shell(char **args);

/* aux_error2.c */
char *error_get_alias(char **args);
char *error_env(char **args);
char *error_syntax(char **args);
char *error_permission(char **args);

/* get_error.c */
int get_error(char **args, int eval);

/* get_sigint.c */
void get_sigint(int sig);

#endif
