#include "monty.h"
/**
* _calloc - Concatenate tw strings specially
* @nmemb: Number of elements
* @size: Type of elements
* Return: Nothing
*/

void *_calloc(unsigned int nmemb, unsigned int size)
{
void *p = NULL;
unsigned int i;

if (nmemb == 0 || size == 0)
{
return (NULL);
}
p = malloc(nmemb * size);
if (p == NULL)
{
return (NULL);
}
for (i = 0; i < (nmemb * size); i++)
{
*((char *)(p) + i) = 0;
}
return (p);
}

/**
* _realloc - Change the size and copy the content
* @ptr: Malloc pointer to reallocate
* @old_size: Old number of bytes
* @new_size: New number of Bytes
* Return: Nothing
*/

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
char *p = NULL;
unsigned int i;

if (new_size == old_size)
return (ptr);
if (ptr == NULL)
{
p = malloc(new_size);
if (!p)
return (NULL);
return (p);
}
if (new_size == 0 && ptr != NULL)
{
free(ptr);
return (NULL);
}
if (new_size > old_size)
{
p = malloc(new_size);
if (!p)
return (NULL);
for (i = 0; i < old_size; i++)
p[i] = *((char *)ptr + i);
free(ptr);
}
else
{
p = malloc(new_size);
if (!p)
return (NULL);
for (i = 0; i < new_size; i++)
p[i] = *((char *)ptr + i);
free(ptr);
}
return (p);
}
