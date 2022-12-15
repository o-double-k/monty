#include "monty.h"

/**
* _div - Divides the second element by the top element of the stack
* @doubly: Head of the linked list
* @cline: Line number
* Return: No return
*/

void _div(stack_t **doubly, unsigned int cline)
{
int m = 0;
stack_t *aux = NULL;

aux = *doubly;

for (; aux != NULL; aux = aux->next, m++)
;

if (m < 2)
{
dprintf(2, "L%u: can't div, stack too short\n", cline);
free_vglo();
exit(EXIT_FAILURE);
}

if ((*doubly)->n == 0)
{
dprintf(2, "L%u: division by zero\n", cline);
free_vglo();
exit(EXIT_FAILURE);
}

aux = (*doubly)->next;
aux->n /= (*doubly)->n;
_pop(doubly, cline);
}

/**
* _mul - Multiplies the top element to the second top element of the stack
* @doubly: Head of the linked list
* @cline: Line number
* Return: No return
*/

void _mul(stack_t **doubly, unsigned int cline)
{
int m = 0;
stack_t *aux = NULL;

aux = *doubly;

for (; aux != NULL; aux = aux->next, m++)
;

if (m < 2)
{
dprintf(2, "L%u: can't mul, stack too short\n", cline);
free_vglo();
exit(EXIT_FAILURE);
}

aux = (*doubly)->next;
aux->n *= (*doubly)->n;
_pop(doubly, cline);
}

/**
* _mod - Computes the rest of the division of the second element
* by the top element of the stack
* @doubly: Head of the linked list
* @cline: Line number
* Return: No return
*/

void _mod(stack_t **doubly, unsigned int cline)
{
int m = 0;
stack_t *aux = NULL;

aux = *doubly;

for (; aux != NULL; aux = aux->next, m++)
;

if (m < 2)
{
dprintf(2, "L%u: can't mod, stack too short\n", cline);
free_vglo();
exit(EXIT_FAILURE);
}

if ((*doubly)->n == 0)
{
dprintf(2, "L%u: division by zero\n", cline);
free_vglo();
exit(EXIT_FAILURE);
}

aux = (*doubly)->next;
aux->n %= (*doubly)->n;
_pop(doubly, cline);
}

/**
* _pchar - Print the char value of the first element
* @doubly: Head of the linked list
* @cline: Line number
* Return: No return
*/

void _pchar(stack_t **doubly, unsigned int cline)
{
if (doubly == NULL || *doubly == NULL)
{
dprintf(2, "L%u: can't pchar, stack empty\n", cline);
free_vglo();
exit(EXIT_FAILURE);
}
if ((*doubly)->n < 0 || (*doubly)->n >= 128)
{
dprintf(2, "L%u: can't pchar, value out of range\n", cline);
free_vglo();
exit(EXIT_FAILURE);
}
printf("%c\n", (*doubly)->n);
}

/**
* _pstr - Prints the string of the stack
* @doubly: Head of the linked list
* @cline: Line number
* Return: No return
*/

void _pstr(stack_t **doubly, unsigned int cline)
{
stack_t *aux;
(void)cline;

aux = *doubly;

while (aux && aux->n > 0 && aux->n < 128)
{
printf("%c", aux->n);
aux = aux->next;
}

printf("\n");
}
