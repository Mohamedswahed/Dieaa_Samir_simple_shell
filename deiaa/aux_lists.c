#include "main.h"

/**
 * add_sep_node_end - adds a separator found at the end
 * of a sep_list.
 * @hd: head of the linked list.
 * @sp: separator found (; | &).
 * Return: address of the head.
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

/**
 * free_sep_list - frees a sep_list
 * @hd: head of the linked list.
 * Return: no return.
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

/**
 * add_line_node_end - adds a command line at the end
 * of a line_list.
 * @hd: head of the linked list.
 * @line: command line.
 * Return: head address.
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

/**
 * free_line_list - frees a line_list
 * @hd: head of the linked list.
 * Return: no return.
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
