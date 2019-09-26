#define GB
#include "monty.h"

void err(stack_t **stack, unsigned int x)
{
  dprintf(2, "L%u: unknown instruction %s\n", x, hola.linea);
  free(hola.linea);
  fclose(hola.fil);
  free_l(stack);
  if (stack)
    {

    }
  exit(EXIT_FAILURE);
}

void ver2(stack_t **stack, unsigned int contador)
{
if (verif(hola.token) == 0)
  hola.numero = atoi(hola.token);
 else
   {
     dprintf(2,"L%u: usage: push integer\n", contador);
     free_l(stack);
     free(hola.linea);
     fclose(hola.fil);
     exit(EXIT_FAILURE);
   }
}
void _mul(stack_t **stack, unsigned int num_linea)
{
  stack_t *ojo;
  stack_t *ojo2;
  int mul = 0;

  if (*stack && (*stack)->next)
    {
      ojo2 = (*stack)->next;
      mul = ojo2->n * (*stack)->n;
      ojo = *stack;
      *stack = (*stack)->next;
      if (*stack)
	(*stack)->prev = NULL;
      free(ojo);
      (*stack)->n = mul;
    }
  else
    {
      dprintf(2, "L%u: can't sub, stack too short\n", num_linea);
      free(hola.linea);
      fclose(hola.fil);
      free_l(stack);
      exit(EXIT_FAILURE);
    }
}
