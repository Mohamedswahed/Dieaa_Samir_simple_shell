#include "main.h"

/**
 * _memcpy - copies information between void pointers.
 * @n_p: destination pointer.
 * @p: source pointer.
 * @size: size of the new pointer.
 *
 * Return: no return.
 */
void _memcpy(void *n_p, const void *p, unsigned int size)
{
	char *char_p = (char *)p;
	char *char_n_p = (char *)n_p;
	unsigned int x;

	for (x = 0; x < size; x++)
		char_n_p[x] = char_p[x];
}

/**
 * _realloc - reallocates a memory block.
 * @p: pointer to the memory previously allocated.
 * @o_size: size, in bytes, of the allocated space of pointer.
 * @n_size: new size, in bytes, of the new memory block.
 *
 * Return: pointer.
 * if new_size == old_size, returns pointer without changes.
 * if malloc fails, returns NULL.
 */
void *_realloc(void *p, unsigned int o_size, unsigned int n_size)
{
	void *n_p;

	if (p == NULL)
		return (malloc(n_size));

	if (n_size == 0)
	{
		free(p);
		return (NULL);
	}

	if (n_size == o_size)
		return (p);

	n_p = malloc(n_size);
	if (n_p == NULL)
		return (NULL);

	if (n_size < o_size)
		_memcpy(n_p, p, n_size);
	else
		_memcpy(n_p, p, o_size);

	free(p);
	return (n_p);
}

/**
 * _reallocdp - reallocates a memory block of a double pointer.
 * @p: double pointer to the memory previously allocated.
 * @o_size: size, in bytes, of the allocated space of pointer.
 * @n_size: size, in bytes, of the new memory block.
 *
 * Return: p.
 * if n_size == o_size, returns p without changes.
 * if malloc fails, returns NULL.
 */
char **_reallocdp(char **p, unsigned int o_size, unsigned int n_size)
{
	char **n_p;
	unsigned int x;

	if (p == NULL)
		return (malloc(sizeof(char *) * n_size));

	if (n_size == o_size)
		return (p);

	n_p = malloc(sizeof(char *) * n_size);
	if (n_p == NULL)
		return (NULL);

	for (x = 0; x < o_size; x++)
		n_p[x] = p[x];

	free(p);

	return (n_p);
}
