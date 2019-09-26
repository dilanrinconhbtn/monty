#include "header.h"


/**
 * swap - swap function
 * @stack_t: head node
 * Return: Void function
 */
void swap(stack_t **stack, __attribute__((unused)) unsigned int num_linea)
{
	stack_t *ojo;

	ojo = (*stack)->next;
	if (ojo == NULL)
	{
		exit(0);
	}
	(*stack)->next = ojo->next;
	(*stack)->prev = ojo;
	ojo->next = *stack;
	ojo->prev = NULL;
	*stack = ojo;
}

/**
 * add - add function
 * @stack: head
 * Return: void function
 */
void add(stack_t **stack, __attribute__((unused)) unsigned int num_linea)
{
	stack_t *ojo;
	stack_t *ojo2 = (*stack)->next;
	int suma = 0;

	if (!((*stack)->next))
		printf("Errorrrr\n");
	suma = (*stack)->n + ojo2->n;
	ojo = *stack;
	*stack = (*stack)->next;
	if (*stack)
		(*stack)->prev = NULL;
	free(ojo);
	(*stack)->n = suma;
}


/**
 * pint - pint function
 * @stack: head
 * @num_linea: num linea
 * Return: void function
 */
void pint(stack_t **stack, unsigned int num_linea)
{
	stack_t *ojo;

	ojo = *stack;
	if (ojo == NULL)
	{
		printf("error en la linea %ud\n", num_linea);
		exit(0);
	}
	printf("%d\n", ojo->n);
}


/**
 * pall - pall function
 * @stack: head
 * @num_linea: num linea
 * Return: void function
 */
void pall(stack_t **stack, unsigned int num_linea)
{
	stack_t *ojo;

	ojo = *stack;
	if (ojo != NULL)
	{
		while (ojo)
		{

			if (ojo->n < 48 || ojo->n > 57)
			{
				printf("%d\n", ojo->n);
				printf("L%ud: usage: push integer\n", num_linea);
			}
			else
			{
				printf("%d\n", ojo->n);
				printf("%d\n", ojo->n);
			}
			ojo = ojo->next;
		}
	}
}


/**
 * push - push function
 * @stack: head
 * @num_linea: number of line
 * Return: Always 0 (Success)
 */
void push(stack_t **stack, unsigned int num_linea)
{
	stack_t *ojo;

	ojo = malloc(sizeof(stack_t));
	if (ojo == NULL)
		printf("Error en la linea %ud\n", num_linea);
	ojo->n = global;
	ojo->next = NULL;
	ojo->prev = NULL;
	if (*stack)
	{
		ojo->next = *stack;
		(*stack)->prev = ojo;
		*stack = ojo;
/** while ((*stack)->next)
 * *stack = (*stack)->next;
 * (*stack)->next = ojo;
 * ojo->prev = *stack;
 * while((*stack)->prev)
 * *stack = (*stack)->prev;
 */
	}
	else
		*stack = ojo;
}
