#include "monty.h"

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
	  free(hola.linea);
	  fclose(hola.fil);
	  free_l(stack);
	  fprintf(stderr, "L%u can't pint, stack empty\n", num_linea);
	  exit(EXIT_FAILURE);
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
	if (num_linea)

	  while(ojo)
	{
	  printf("%d\n", ojo->n);
	  ojo = ojo->next;
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

	ver2(stack, num_linea);
	if (hola.token)
	  {
	    ojo = malloc(sizeof(stack_t));
	    if (ojo == NULL)
	      {
		fputs("Error: malloc failed\n", stderr);
		exit(EXOT_FAILURE);
	      }
	    ojo->n = hola.numero;
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
	else
	  {
	    free(hola.linea);
	    fclose(hola.fil);
	    fprintf(stderr, "L%u: usage: push integer\n", num_linea);
	    free_l(stack);
            exit(EXIT_FAILURE);
          }
}
