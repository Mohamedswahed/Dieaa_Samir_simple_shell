#include "main.h"
/*
 # _reallocdp - reallocates a memory block of a double pointer.
 # @p: double pointer to the memory previously allocated.
 # @o_size: size, in bytes, of the allocated space of pointer.
 # @n_size: size, in bytes, of the new memory block.
 # Return: pointer.
 # if n_size == o_size, returns pointer without changes.
 # if malloc fails, returns NULL.
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

/*
 # _realloc - Reallocates memory block.
 # @p: Pointer to memory previously allocated.
 # @o_size: Size, in bytes, of allocated space of pointer.
 # @n_size: New size, in bytes, of new memory block.
 # Return: Pointer.
 # if new_size == old_size, Returns pointer without changes.
 # if malloc fails, Returns NULL.
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

/*
 # _memcpy - To copy info between pointers.
 # @n_p: destination pointer.
 # @p: source pointer.
 # @size: size of new pointer.
 # Return: No Return.
 */
void _memcpy(void *n_p, const void *p, unsigned int size)
{
	char *char_p = (char *)p;
	char *char_n_p = (char *)n_p;
	unsigned int x;
	for (x = 0; x < size; x++)
		char_n_p[x] = char_p[x];
}

/*
 * *_strcpy - Copy string in pointer src.
 * @dest: dest of copied str
 * @src: the string source pointer.
 * Return: the dest.
 */
char *_strcpy(char *dest, char *src)
{
	size_t i;
	for (i = 0; src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';
	return (dest);
}

/*
 # strcat_cd - concatenates message for cd error.
 # @datash: directory for data relevant 
 # @masg: message to print
 # @err: output message
 # @ver_str: counter lines
 # Return: error message
 */
char *strcat_cd(data_shell *datash, char *masg, char *err, char *ver_str)
{
	char *ilgal_flg;
	_strcpy(err, datash->av[0]);
	_strcat(err, ": ");
	_strcat(err, ver_str);
	_strcat(err, ": ");
	_strcat(err, datash->args[0]);
	_strcat(err, masg);
	if (datash->args[1][0] == '-')
	{
		ilgal_flg = malloc(3);
		ilgal_flg[0] = '-';
		ilgal_flg[1] = datash->args[1][1];
		ilgal_flg[2] = '\0';
		_strcat(err, ilgal_flg);
		free(ilgal_flg);
	}
	else
	{
		_strcat(err, datash->args[1]);
	}
	_strcat(err, "\n");
	_strcat(err, "\0");
	return (err);
}
