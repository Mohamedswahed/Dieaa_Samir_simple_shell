#include "main.h"

/**
 * add_rvar_node - adds a variable at the end
 * of a r_var list.
 * @hd: linked list head.
 * @vr_l: variable length.
 * @v: variable value.
 * @vl: value length.
 * Return: head address.
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

/**
 * free_rvar_list - frees a r_var list
 * @hd: linked list head.
 * Return: no return.
 */
void free_rvar_list(r_var **hd)
{
	r_var *tmp;
	r_var *c;

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
