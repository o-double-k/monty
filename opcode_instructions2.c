#include "monty.h"

/**
* _queue - Sets the format of the data to a queue (FIFO)
* @doubly: Head of the linked list
* @cline: Line number
* Return: No return
*/

void _queue(stack_t **doubly, unsigned int cline)
{
(void)doubly;
(void)cline;

vglo.lifo = 0;
}

/**
* _stack - Sets the format fo the data to a stack (LIFO)
* @doubly: Head of the linked list
* @cline: Line number;
* Return: No return
*/

void _stack(stack_t **doubly, unsigned int cline)
{
(void)doubly;
(void)cline;

vglo.lifo = 1;
}

/**
* _add - Adds the top two elements of the stack
* @doubly: Head of the linked list
* @cline: Line number;
* Return: No return
*/

void _add(stack_t **doubly, unsigned int cline)
{
int m = 0;
stack_t *aux = NULL;

aux = *doubly;

for (; aux != NULL; aux = aux->next, m++)
;

if (m < 2)
{
dprintf(2, "L%u: can't add, stack too short\n", cline);
free_vglo();
exit(EXIT_FAILURE);
}

aux = (*doubly)->next;
aux->n += (*doubly)->n;
_pop(doubly, cline);
}

/**
* _nop - Doesn't do anythinhg
* @doubly: Head of the linked list
* @cline: Line number
* Return: No return
*/
void _nop(stack_t **doubly, unsigned int cline)
{
(void)doubly;
(void)cline;
}

/**
* _sub - Subtracts the top element to the second top element of the stack
* @doubly: Head of the linked list
* @cline: Line number;
* Return: No return
*/

void _sub(stack_t **doubly, unsigned int cline)
{
int m = 0;
stack_t *aux = NULL;

aux = *doubly;

for (; aux != NULL; aux = aux->next, m++)
;

if (m < 2)
{
dprintf(2, "L%u: can't sub, stack too short\n", cline);
free_vglo();
exit(EXIT_FAILURE);
}

aux = (*doubly)->next;
aux->n -= (*doubly)->n;
_pop(doubly, cline);
}
