#include "main.h"
/*
 # free_line_list - Frees a line_list
 # @hd: Head of the linked list.
 # Return: No return.
 */
void free_line_list(line_list **hd)
{
	line_list *tmp;
	line_list *c;

	if (hd != NULL)
	{
		c = *hd;
		while ((tmp = c) != NULL)
		{
			c = c->next;
			free(tmp);
		}
		*hd = NULL;
	}
}

/*
 # add_line_node_end - adds a command line at line_list end.
 # @hd: Head of the linked list.
 # @line: Command line.
 # Return: Head address.
 */
line_list *add_line_node_end(line_list **hd, char *line)
{
	line_list *n, *tmp;
	n = malloc(sizeof(line_list));
	if (n == NULL)
		return (NULL);
	n->line = line;
	n->next = NULL;
	tmp = *hd;
	if (tmp == NULL)
	{
		*hd = n;
	}
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = n;
	}
	return (*hd);
}

/*
 # free_sep_list - Frees a sep_list
 # @hd: Head of the linked list.
 # Return: No return.
 */
void free_sep_list(sep_list **hd)
{
	sep_list *tmp;
	sep_list *c;
	if (hd != NULL)
	{
		c = *hd;
		while ((tmp = c) != NULL)
		{
			c = c->next;
			free(tmp);
		}
		*hd = NULL;
	}
}

/*
 # add_rvar_node - adds a variable at r_var list end.
 # @hd: Linked list head.
 # @vr_l: Variable length.
 # @v: Variable value.
 # @vl: Value length.
 # Return: Head address.
 */
r_var *add_rvar_node(r_var **hd, int vr_l, char *v, int vl)
{
	r_var *n, *tmp;
	n = malloc(sizeof(r_var));
	if (n == NULL)
		return (NULL);
	n->len_var = vr_l;
	n->v = v;
	n->len_v = vl;
	n->next = NULL;
	tmp = *hd;
	if (tmp == NULL)
	{
		*hd = n;
	}
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = n;
	}
	return (*hd);
}

/*
 # add_sep_node_end - adds a separator found at sep_list end.
 # @hd: Head of the linked list.
 # @sp: Separator found (; | &).
 # Return: Address of the head.
 */
sep_list *add_sep_node_end(sep_list **hd, char sp)
{
	sep_list *n, *tmp;
	n = malloc(sizeof(sep_list));
	if (n == NULL)
		return (NULL);
	n->separator = sp;
	n->next = NULL;
	tmp = *hd;
	if (tmp == NULL)
	{
		*hd = n;
	}
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = n;
	}
	return (*hd);
}
