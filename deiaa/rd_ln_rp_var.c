#include "main.h"

/**
 * rep_var - calls functions to replace string
 * @input: input string
 * @datash: data structure
 * Return: replaced string
 */
char *rep_var(char *input, data_shell *datash)
{
	r_var *head, *indx;
	char *status, *new_input;
	int ol, nl;

	status = aux_itoa(datash->status);
	head = NULL;
	ol = check_vars(&head, input, status, datash);
	if (head == NULL)
	{
		free(status);
		return (input);
	}
	indx = head;
	nl = 0;
	while (indx != NULL)
	{
		nl += (indx->len_val - indx->len_var);
		indx = indx->next;
	}
	nl += ol;
	new_input = malloc(sizeof(char) * (nl + 1));
	new_input[nl] = '\0';
	new_input = replaced_input(&head, input, new_input, nl);
	free(input);
	free(status);
	free_rvar_list(&head);

	return (new_input);
}


/**
 * check_env - checks if the variable type
 * @h: head of linked list
 * @in: input string
 * @data: data structure
 * Return: return null
 */
void check_env(r_var **h, char *in, data_shell *data)
{
	int r, chr, y, l_val;
	char **_envr;

	_envr = data->_environ;
	for (r = 0; _envr[r]; r++)
	{
		for (y = 1, chr = 0; _envr[r][chr]; chr++)
		{
			if (_envr[r][chr] == '=')
			{
				l_val = _strlen(_envr[r] + chr + 1);
				add_rvar_node(h, y, _envr[r] + chr + 1, l_val);
				return;
			}
			if (in[y] == _envr[r][chr])
				y++;
			else
				break;
		}
	}

	for (y = 0; in[y]; y++)
	{
		if (in[y] == ' ' || in[y] == '\t' || in[y] == ';' || in[y] == '\n')
			break;
	}
	add_rvar_node(h, y, NULL, 0);
}

/**
 * read_line - reads the input string
 * @i_eof: return value of function getline
 * Return: input string
 */
char *read_line(int *i_eof)
{
	char *input = NULL;
	size_t bufsize = 0;

	*i_eof = getline(&input, &bufsize, stdin);

	return (input);
}

/**
 * check_vars - check if the typed variable
 * @h: head of the linked list
 * @in: input string
 * @st: last status of the Shell
 * @data: data structure
 * Return: no return
 */
int check_vars(r_var **h, char *in, char *st, data_shell *data)
{
	int x, lst, pd;

	lst = _strlen(st);
	pd = _strlen(data->pid);

	for (x = 0; in[x]; x++)
	{
		if (in[x] == '$')
		{
			if (in[x + 1] == '?')
				add_rvar_node(h, 2, st, lst), x++;
			else if (in[x + 1] == '$')
				add_rvar_node(h, 2, data->pid, pd), x++;
			else if (in[x + 1] == '\n')
				add_rvar_node(h, 0, NULL, 0);
			else if (in[x + 1] == '\0')
				add_rvar_node(h, 0, NULL, 0);
			else if (in[x + 1] == ' ')
				add_rvar_node(h, 0, NULL, 0);
			else if (in[x + 1] == '\t')
				add_rvar_node(h, 0, NULL, 0);
			else if (in[x + 1] == ';')
				add_rvar_node(h, 0, NULL, 0);
			else
				check_env(h, in + x, data);
		}
	}

	return (x);
}

/**
 * replaced_input - replaces string into variable
 * @head: head of the linked list
 * @input: input string
 * @new_input: new input string (replaced)
 * @nl: new length
 * Return: replaced string
 */
char *replaced_input(r_var **head, char *input, char *new_input, int nl)
{
	r_var *indx;
	int x, y, z;

	indx = *head;
	for (y = x = 0; x < nl; x++)
	{
		if (input[y] == '$')
		{
			if (!(indx->len_var) && !(indx->len_val))
			{
				new_input[x] = input[y];
				y++;
			}
			else if (indx->len_var && !(indx->len_val))
			{
				for (z = 0; z < indx->len_var; z++)
					y++;
				x--;
			}
			else
			{
				for (z = 0; z < indx->len_val; z++)
				{
					new_input[x] = indx->v[z];
					x++;
				}
				y += (indx->len_var);
				x--;
			}
			indx = indx->next;
		}
		else
		{
			new_input[x] = input[y];
			y++;
		}
	}

	return (new_input);
}


