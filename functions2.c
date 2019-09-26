#include "header.h"

int verif(char *numero)
{

  int ojo = 0;

  while(numero[ojo])
    {
      if (numero[ojo] < 48 || numero[ojo] > 57)
	return (-1);
      ojo++;
    }
  return (0);
}
void nop(stack_t **stack, unsigned int num_linea)
{
  if (*stack){};
  if (num_linea){};
}
void sub(stack_t **stack, unsigned int num_linea)
{
  stack_t *ojo;
  stack_t *ojo2 = (*stack)->next;
  int resta = 0;

  if (!((*stack)->next))
    fprintf(stderr, "L%u: can't sub, stack too short\n", num_linea);
  resta = ojo2->n - (*stack)->n;
  ojo = *stack;
  *stack = (*stack)->next;
  if (*stack)
    (*stack)->prev = NULL;
  free(ojo);
  (*stack)->n = resta;
}
void divi(stack_t **stack, unsigned int num_linea)
{
  stack_t *ojo;
  stack_t *ojo2 = (*stack)->next;
  int div = 0;

  if (!((*stack)->next))
    fprintf(stderr, "L%u: can't sub, stack too short\n", num_linea);
  if ((*stack)->n == 0)
    {
      fprintf(stderr, "L%u: division by zero\n", num_linea);
      exit(EXIT_FAILURE);
    }

  div = ojo2->n / (*stack)->n;
  ojo = *stack;
  *stack = (*stack)->next;
  if (*stack)
    (*stack)->prev = NULL;
  free(ojo);
  (*stack)->n = div;
}
     
