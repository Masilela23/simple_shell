#include "shell.h"

/**
 * sh_exit - exits the shell
 * @info: possible arguments . Maintains a constant function prototype
 *  Return: exits with a given exit status
 *         (0) if info.argv[0] != "exit"
 */
int sh_exit(info_t *info)
{
	int puma;

	if (info->argv[1])
	{
		puma = err_stoi(info->argv[1]);
		if (puma == -1)
		{
			info->status = 2;
			prnts_err(info, "Illegal number: ");
			in_puts(info->argv[1]);
			_eputchar('\n');
			return (1);
		}
		info->err_num = err_stoi(info->argv[1]);
		return (-2);
	}
	info->err_num = -1;
	return (-2);
}


/**
 * x_help - handles the "help" command in the shell
 * @info: the state of the shell.
 *  Return: Always 0
 */
int x_help(info_t *info)
{
	char **l_l;

	l_l = info->argv;
	_puts("help call works. Function not yet implemented \n");
	if (0)
		_puts(*l_l);
	return (0);
}
