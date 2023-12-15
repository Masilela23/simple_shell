#ifndef _SHELL_H_
#define _SHELL_H_

#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH '\0'
#define STDERR_FILENO 2

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

/**
 * struct liststr - singly linked list
 * @num: the number field
 * @str: a string
 * @next: points to the next node
 */
typedef struct liststr
{
	int num;
	char *str;
	struct liststr *next;
} list_t;

/**
 *struct passinfo - contains pseudo-arguements to pass into a function,
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
 *@cmd_buf: address of pointer to cmd_buf, on if chaining
 *@cmd_buf_type: CMD_type ||, &&, ;
 *@readfd: the fd from which to read line input
 *@histcount: the history line number count
 */
typedef struct passinfo
{
	char *arg;
	char **argv;
	char *path;
	int argc;
	unsigned int line_count;
	int err_num;
	int linecount_flag;
	char *fname;
	list_t *env;
	list_t *history;
	list_t *alias;
	char **environ;
	int env_changed;
	int status;

	char **cmd_buf; /* pointer to cmd ; chain buffer, for memory mangement */
	int cmd_buf_type; /* CMD_type ||, &&, ; */
	int readfd;
	int histcount;
} info_t;

#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
	0, 0, 0}

/**
 *struct builtin - contains a builtin string and related function
 *@type: the builtin command flag
 *@func: the function
 */
typedef struct builtin
{
	char *type;
	int (*func)(info_t *);
} builtin_table;

int enviro_list(info_t *info);
char *recenv(info_t *info, const char *name);
int printenv_(info_t *info);
int inter_shell(info_t *info);
int sh_exit(info_t *info);
int str_int(char *s);
int true_deli(char q, char *deli);
int alpha_shell(int q);
int _myhelp(info_t *info);
int xx_cd(info_t *info);
int alias_un_set(info_t *info, char *str);
int alias_set(info_t *info, char *str);
int alias_prntr(list_t *node);
int i_alias(info_t *info);
void in_puts(char *str);
int _eputchar(char c);
int fd_puts(char c, int fd);
int sfd_puts(char *str, int fd);
int err_stoi(char *s);
int d_prntr(int input, int fd);
void prnts_err(info_t *info, char *error_str);
char *conv_numbr(long int num, int base, int mas);

#endif
