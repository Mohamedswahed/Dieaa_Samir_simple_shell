#include "main.h"
/*
 # cd_shell - Changes current directory
 # @datash: data relevant
 # Return: 1 in case of success
 */
int cd_shell(data_shell *datash)
{
	char *dir;
	int ishome, ishome2, isddash;
	dir = datash->args[1];
	if (dir != NULL)
	{
		ishome = _strcmp("$HOME", dir);
		ishome2 = _strcmp("~", dir);
		isddash = _strcmp("--", dir);
	}
	if (dir == NULL || !ishome || !ishome2 || !isddash)
	{
		cd_to_home(datash);
		return (1);
	}
	if (_strcmp("-", dir) == 0)
	{
		cd_previous(datash);
		return (1);
	}
	if (_strcmp(".", dir) == 0 || _strcmp("..", dir) == 0)
	{
		cd_dot(datash);
		return (1);
	}
	cd_to(datash);
	return (1);
}

/*
 # cd_to_home - Change to home directory
 # @datash: data relevant (environ)
 # Return: No Return
 */
void cd_to_home(data_shell *datash)
{
	char *p_pwd, *home, pwd[PATH_MAX];
	getcwd(pwd, sizeof(pwd));
	p_pwd = _strdup(pwd);
	home = _getenv("HOME", datash->_environ);
	if (home == NULL)
	{
		set_env("OLDPWD", p_pwd, datash);
		free(p_pwd);
		return;
	}
	if (chdir(home) == -1)
	{
		get_err(datash, 2);
		free(p_pwd);
		return;
	}
	set_env("OLDPWD", p_pwd, datash);
	set_env("PWD", home, datash);
	free(p_pwd);
	datash->status = 0;
}

/*
 # cd_to - Function to change directory to a given directory.
 # @datash: data relevant (directories)
 # Return: No Return
 */
void cd_to(data_shell *datash)
{
	char pwd[PATH_MAX];
	char *dir, *cp_pwd, *cp_dir;
	getcwd(pwd, sizeof(pwd));
	dir = datash->args[1];
	if (chdir(dir) == -1)
	{
		get_err(datash, 2);
		return;
	}
	cp_pwd = _strdup(pwd);
	set_env("OLDPWD", cp_pwd, datash);
	cp_dir = _strdup(dir);
	set_env("PWD", cp_dir, datash);
	free(cp_pwd);
	free(cp_dir);
	datash->status = 0;
	chdir(dir);
}

/*
 # cd_dot - To change current directory to parent directory.
 # @datash: data relevant (environ)
 # Return: No Return
 */
void cd_dot(data_shell *datash)
{
	char pwd[PATH_MAX];
	char *dir, *cp_pwd, *cp_strtok_pwd;
	getcwd(pwd, sizeof(pwd));
	cp_pwd = _strdup(pwd);
	set_env("OLDPWD", cp_pwd, datash);
	dir = datash->args[1];
	if (_strcmp(".", dir) == 0)
	{
		set_env("PWD", cp_pwd, datash);
		free(cp_pwd);
		return;
	}
	if (_strcmp("/", cp_pwd) == 0)
	{
		free(cp_pwd);
		return;
	}
	cp_strtok_pwd = cp_pwd;
	rev_string(cp_strtok_pwd);
	cp_strtok_pwd = _strtok(cp_strtok_pwd, "/");
	if (cp_strtok_pwd != NULL)
	{
		cp_strtok_pwd = _strtok(NULL, "\0");
		if (cp_strtok_pwd != NULL)
			rev_string(cp_strtok_pwd);
	}
	if (cp_strtok_pwd != NULL)
	{
		chdir(cp_strtok_pwd);
		set_env("PWD", cp_strtok_pwd, datash);
	}
	else
	{
		chdir("/");
		set_env("PWD", "/", datash);
	}
	datash->status = 0;
	free(cp_pwd);
}

/*
 # cd_previous - To change directory to previous directory.
 # @datash: data relevant (environ)
 # Return: No Return
 */
void cd_previous(data_shell *datash)
{
	char pwd[PATH_MAX];
	char *p_pwd, *p_oldpwd, *cp_pwd, *cp_oldpwd;
	getcwd(pwd, sizeof(pwd));
	cp_pwd = _strdup(pwd);
	p_oldpwd = _getenv("OLDPWD", datash->_environ);
	if (p_oldpwd == NULL)
		cp_oldpwd = cp_pwd;
	else
		cp_oldpwd = _strdup(p_oldpwd);
	set_env("OLDPWD", cp_pwd, datash);
	if (chdir(cp_oldpwd) == -1)
		set_env("PWD", cp_pwd, datash);
	else
		set_env("PWD", cp_oldpwd, datash);
	p_pwd = _getenv("PWD", datash->_environ);
	write(STDOUT_FILENO, p_pwd, _strlen(p_pwd));
	write(STDOUT_FILENO, "\n", 1);
	free(cp_pwd);
	if (p_oldpwd)
		free(cp_oldpwd);
	datash->status = 0;
	chdir(p_pwd);
}
