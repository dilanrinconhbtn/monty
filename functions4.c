#include "monty.h"

void pstr(stack_t **stack, unsigned int num_linea)
{
	stack_t *ojo;

	ojo = *stack;
	if (num_linea)
		while (ojo && ojo->n != 0 && ojo->n > 0 && ojo->n < 256)
		{
			printf("%c", ojo->n);
			ojo = ojo->next;
		}
	printf("\n");
}

void rotl(stack_t **stack, unsigned int num_linea)
{
	stack_t *ojo, *ojo2;

	ojo = *stack;
	ojo2 = ojo;
	*stack = ojo->next;
	(*stack)->prev = NULL;
	if (num_linea)
		while (ojo2->next)
		{
			ojo2 = ojo2->next;
		}
	ojo2->next = ojo;
	ojo->prev = ojo2;
	ojo->next = NULL;
}
void rotr(stack_t **stack, unsigned int num_linea)
{
	stack_t *ojo2;

	ojo2 = *stack;
	if (num_linea)
		while (ojo2->next)
		{
			ojo2 = ojo2->next;
		}
	ojo2->next = *stack;
	ojo2->prev->next = NULL;
	ojo2->prev = NULL;
	*stack = ojo2;
}

void queue(stack_t **stack, unsigned int num_linea)
{
	if (stack || num_linea)
		hola.flag = 0;
}
void stack(stack_t **stack, unsigned int num_linea)
{
	if (stack || num_linea)
		hola.flag = 1;
}
