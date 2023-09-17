#include "main.h"

/**
 * cmp_env_name - compares env variables with the name passed.
 * @nenv: name of the environment variable
 * @name: name passed
 * Return: 0 if are not equal. Another value if they are.
 */
int cmp_env_name(const char *nenv, const char *name)
{
	int x;

	for (x = 0; nenv[x] != '='; x++)
	{
		if (nenv[x] != name[x])
		{
			return (0);
		}
	}
	return (x + 1);
}

/**
 * _env - prints the evironment variables
 * @datash: data relevant.
 * Return: 1 on success.
 */
int _env(data_shell *datash)
{
	int x, y;

	for (x = 0; datash->_environ[x]; x++)
	{

		for (y = 0; datash->_environ[x][y]; y++)
			;
		write(STDOUT_FILENO, datash->_environ[x], y);
		write(STDOUT_FILENO, "\n", 1);
	}
	datash->status = 0;
	return (1);
}

/**
 * _getenv - get an environment variable
 * @name: name of the environment variable
 * @_environ: environment variable
 * Return: value of the environment variable if is found.
 * In other case, returns NULL.
 */
char *_getenv(const char *name, char **_environ)
{

	char *ptr_env;
	int x, mov;

	ptr_env = NULL;
	mov = 0;
	for (x = 0; _environ[x]; x++)
	{
		mov = cmp_env_name(_environ[x], name);
		if (mov)
		{
			ptr_env = _environ[x];
			break;
		}
	}
	return (ptr_env + mov);
}
