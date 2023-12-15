#ifndef SHELL_H
#define SHELL_H

#define BUFFERSIZE 1024
#define DELIMINATOR "\n\r\t\a "

extern char **environ;

#include <errno.h>
#include <fcntl.h>
#include <limits.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stddef.h>
#include <ctype.h>
#include <stdbool.h>

/**
 *info - contains pseudo-arguements to pass into a function,
 *		allowing uniform prototype for function pointer struct
 *@arg: a string generated from getline containing arguements
 *@argv: an array of strings generated from arg
 *@path: a string path for the current command
 *@argc: the argument count
 *@line_count: the error count
 *@err_num: the error code for exit()s
 *@linecount_flag: if on count this line of input
 *@fname: the program filename
 *@env: linked list local copy of environ
 *@environ: custom modified copy of environ from LL env
 *@history: the history node
 *@alias: the alias node
 *@env_changed: on if environ was changed
 *@status: the return status of the last exec'd command
  *@readfd: the fd from which to read line input
 *@histcount: the history line number count
 */


/**
 * struct list_s - singly linked list
 * @str: string - (malloc'ed string)
 * @len: length of the string
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 */

typedef struct list_s
{
	char *str;
	unsigned int len;
	struct list_s *next;
} list_t;

extern char *head;
int main(void);
int call_unsetenv(char **env, char **str);
int call_setenv(char **env, char **str);
int call_cd(char **args);
void call_exit(char **args);
int call_exit_status(char **args);
int call_env(char **args);
int call_help(char *args);
char *_getenv(char **env, char *str);
int input_check(char **str, char **env, char *newstr, char *path, char *mas);
int find_env_var(char **enviorment, char *str);
int check_input(char **str, char **env);
int _isdigit(char str);
int _exit_atoi(char *str);
list_t *add_node(list_t **head, const char *str);
void free_list(list_t *head);
int _strlen(char *str);
char *_strcpy(char *dest, char *src);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
int _atoi(char *str);
char *_strdup(const char *str);
int _strcmp(char *str1, char *str2);
int exec_cmd(char **str, char **env);
char *read_shell(void);
char *_strcat(char *s1, char *s2);
void ctrl_c_handler(int sig_num);
char **shell_line(char *line);
int shell_filter(char **commands, char **env);
int WhoAmI(void);


#endif
