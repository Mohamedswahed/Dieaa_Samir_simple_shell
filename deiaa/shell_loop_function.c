#include "main.h"


/**
 * shell_loop - lp of shell
 * @datash: data relevant (av, input, args)
 *
 * Return: no return.
 */
void shell_loop(data_shell *datash)
{
	int lp, eof;
	char *input;

	lp = 1;
	while (lp == 1)
	{
		write(STDIN_FILENO, "$ ", 2);
		input = read_line(&eof);
		if (eof != -1)
		{
			input = without_comment(input);
			if (input == NULL)
				continue;

			if (check_syntax_err(datash, input) == 1)
			{
				datash->status = 2;
				free(input);
				continue;
			}
			input = rep_var(input, datash);
			lp = split_commands(datash, input);
			datash->counter += 1;
			free(input);
		}
		else
		{
			lp = 0;
			free(input);
		}
	}
}

/**
 * without_comment - deletes comments from the input
 * @in: input string
 * Return: input without comments
 */
char *without_comment(char *in)
{
	int x, upto;

	upto = 0;
	for (x = 0; in[x]; x++)
	{
		if (in[x] == '#')
		{
			if (x == 0)
			{
				free(in);
				return (NULL);
			}

			if (in[x - 1] == ' ' || in[x - 1] == '\t' || in[x - 1] == ';')
				upto = x;
		}
	}

	if (upto != 0)
	{
		in = _realloc(in, x, upto + 1);
		in[upto] = '\0';
	}

	return (in);
}


