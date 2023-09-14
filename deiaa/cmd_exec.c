#include "main.h"

/**
 * is_cdir - checks ":" if is in the current directory.
 * @pth: type char pointer char.
 * @i: type int pointer of index.
 * Return: 1 if the pth is searchable in the cd, 0 otherwise.
 */
int is_cdir(char *pth, int *x)
{
	if (pth[*x] == ':')
		return (1);

	while (pth[*x] != ':' && pth[*x])
	{
		*x += 1;
	}

	if (pth[*x])
		*x += 1;

	return (0);
}

/**
 * _which - command locate
 *
 * @cmd: name of command
 * @_environ: env. var.
 * Return: command location.
 */
char *_which(char *cmd, char **_environ)
{
	char *pth, *p_pth, *tkn_pth, *dir;
	int len_dir, len_cmd, x;
	struct stat st;

	pth = _getenv("pth", _environ);
	if (pth)
	{
		p_pth = _strdup(pth);
		len_cmd = _strlen(cmd);
		tkn_pth = _strtok(p_pth, ":");
		x = 0;
		while (tkn_pth != NULL)
		{
			if (is_cdir(pth, &x))
				if (stat(cmd, &st) == 0)
					return (cmd);
			len_dir = _strlen(tkn_pth);
			dir = malloc(len_dir + len_cmd + 2);
			_strcpy(dir, tkn_pth);
			_strcat(dir, "/");
			_strcat(dir, cmd);
			_strcat(dir, "\0");
			if (stat(dir, &st) == 0)
			{
				free(p_pth);
				return (dir);
			}
			free(dir);
			tkn_pth = _strtok(NULL, ":");
		}
		free(p_pth);
		if (stat(cmd, &st) == 0)
			return (cmd);
		return (NULL);
	}
	if (cmd[0] == '/')
		if (stat(cmd, &st) == 0)
			return (cmd);
	return (NULL);
}

/**
 * is_executable - check if is executable
 *
 * @datash: data structure
 * Return: 0 in case of executable, other number if not
 */
int is_executable(data_shell *datash)
{
	struct stat st;
	int x;
	char *in;

	in = datash->args[0];
	for (x = 0; in[x]; x++)
	{
		if (in[x] == '.')
		{
			if (in[x + 1] == '.')
				return (0);
			if (in[x + 1] == '/')
				continue;
			else
				break;
		}
		else if (in[x] == '/' && x != 0)
		{
			if (in[x + 1] == '.')
				continue;
			x++;
			break;
		}
		else
			break;
	}
	if (x == 0)
		return (0);

	if (stat(in + x, &st) == 0)
	{
		return (x);
	}
	get_err(datash, 127);
	return (-1);
}

/**
 * check_err_cmd - check if user has access permissions.
 *
 * @dir: destination directory
 * @datash: data structure
 * Return: 1 in case of there is an error, 0 if not
 */
int check_err_cmd(char *dir, data_shell *datash)
{
	if (dir == NULL)
	{
		get_err(datash, 127);
		return (1);
	}

	if (_strcmp(datash->args[0], dir) != 0)
	{
		if (access(dir, X_OK) == -1)
		{
			get_err(datash, 126);
			free(dir);
			return (1);
		}
		free(dir);
	}
	else
	{
		if (access(datash->args[0], X_OK) == -1)
		{
			get_err(datash, 126);
			return (1);
		}
	}

	return (0);
}

/**
 * cmd_exec - executes command lines
 *
 * @datash: data relevant (args and input)
 * Return: 1 on success.
 */
int cmd_exec(data_shell *datash)
{
	pid_t pd;
	pid_t wpd;
	int state;
	int exec;
	char *dir;
	(void) wpd;

	exec = is_executable(datash);
	if (exec == -1)
		return (1);
	if (exec == 0)
	{
		dir = _which(datash->args[0], datash->_environ);
		if (check_err_cmd(dir, datash) == 1)
			return (1);
	}

	pd = fork();
	if (pd == 0)
	{
		if (exec == 0)
			dir = _which(datash->args[0], datash->_environ);
		else
			dir = datash->args[0];
		execve(dir + exec, datash->args, datash->_environ);
	}
	else if (pd < 0)
	{
		perror(datash->av[0]);
		return (1);
	}
	else
	{
		do {
			wpd = waitpid(pd, &state, WUNTRACED);
		} while (!WIFEXITED(state) && !WIFSIGNALED(state));
	}

	datash->status = state / 256;
	return (1);
}
