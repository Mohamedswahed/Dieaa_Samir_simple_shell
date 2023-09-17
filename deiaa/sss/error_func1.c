#include "main.h"

/*
 # err_exit_shell - generic error message to exit in get_exit
 # @datash: data relevant (counter, arguments)
 # Return: error message
 */
char *err_exit_shell(data_shell *datash)
{
	char *err, *ver_str;
	int l;
	ver_str = aux_itoa(datash->counter);
	l = _strlen(datash->av[0]) + _strlen(ver_str);
	l += _strlen(datash->args[0]) + _strlen(datash->args[1]) + 23;
	err = malloc(sizeof(char) * (l + 1));
	if (err == 0)
	{
		free(ver_str);
		return (NULL);
	}
	_strcpy(err, datash->av[0]);
	_strcat(err, ": ");
	_strcat(err, ver_str);
	_strcat(err, ": ");
	_strcat(err, datash->args[0]);
	_strcat(err, ": Illegal number: ");
	_strcat(err, datash->args[1]);
	_strcat(err, "\n\0");
	free(ver_str);
	return (err);
}

/*
 # err_path_126 - error message for path and failure denied permission.
 # @datash: data relevant (counter, arguments).
 # Return: The error string.
 */
char *err_path_126(data_shell *datash)
{
	char *ver_str, *err;
	int l;
	ver_str = aux_itoa(datash->counter);
	l = _strlen(datash->av[0]) + _strlen(ver_str);
	l += _strlen(datash->args[0]) + 24;
	err = malloc(sizeof(char) * (l + 1));
	if (err == 0)
	{
		free(err);
		free(ver_str);
		return (NULL);
	}
	_strcpy(err, datash->av[0]);
	_strcat(err, ": ");
	_strcat(err, ver_str);
	_strcat(err, ": ");
	_strcat(err, datash->args[0]);
	_strcat(err, ": Permission denied\n");
	_strcat(err, "\0");
	free(ver_str);
	return (err);
}

/*
 # err_env - error message for env in get_env.
 # @datash: data relevant (counter, arguments)
 # Return: error message.
 */
char *err_env(data_shell *datash)
{
	char *err, *ver_str, *masg;
	int l;
	ver_str = aux_itoa(datash->counter);
	masg = ": Unable to add/remove from environment\n";
	l = _strlen(datash->av[0]) + _strlen(ver_str);
	l += _strlen(datash->args[0]) + _strlen(masg) + 4;
	err = malloc(sizeof(char) * (l + 1));
	if (err == 0)
	{
		free(err);
		free(ver_str);
		return (NULL);
	}
	_strcpy(err, datash->av[0]);
	_strcat(err, ": ");
	_strcat(err, ver_str);
	_strcat(err, ": ");
	_strcat(err, datash->args[0]);
	_strcat(err, masg);
	_strcat(err, "\0");
	free(ver_str);
	return (err);
}

/*
 # err_not_found - generic error message for command not found
 # @datash: data relevant (counter, arguments)
 # Return: error message
 */
char *err_not_found(data_shell *datash)
{
	char *err, *ver_str;
	int l;
	ver_str = aux_itoa(datash->counter);
	l = _strlen(datash->av[0]) + _strlen(ver_str);
	l += _strlen(datash->args[0]) + 16;
	err = malloc(sizeof(char) * (l + 1));
	if (err == 0)
	{
		free(err);
		free(ver_str);
		return (NULL);
	}
	_strcpy(err, datash->av[0]);
	_strcat(err, ": ");
	_strcat(err, ver_str);
	_strcat(err, ": ");
	_strcat(err, datash->args[0]);
	_strcat(err, ": not found\n");
	_strcat(err, "\0");
	free(ver_str);
	return (err);
}

/*
 # err_get_cd - error message for cd command in get_cd
 # @datash: directory for data relevant
 # Return: error message
 */
char *err_get_cd(data_shell *datash)
{
	int l, l_id;
	char *err, *ver_str, *masg;
	ver_str = aux_itoa(datash->counter);
	if (datash->args[1][0] == '-')
	{
		masg = ": Illegal option ";
		l_id = 2;
	}
	else
	{
		masg = ": can't cd to ";
		l_id = _strlen(datash->args[1]);
	}

	l = _strlen(datash->av[0]) + _strlen(datash->args[0]);
	l += _strlen(ver_str) + _strlen(masg) + l_id + 5;
	err = malloc(sizeof(char) * (l + 1));
	if (err == 0)
	{
		free(ver_str);
		return (NULL);
	}
	err = strcat_cd(datash, masg, err, ver_str);
	free(ver_str);
	return (err);
}
