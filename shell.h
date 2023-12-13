#ifndef SHELL_H
#define SHELL_H

#define BUFFERSIZE 1024
#define DELIMINATOR "\n\r\t\a "

extern char **envi;

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
char *read_line(void);
char *_strcat(char *s1, char *s2);
void ctrl_c_handler(int sig_num);
char **parse_line(char *line);
int function_filter(char **commands, char **env);
int WhoAmI(void);

#endif
