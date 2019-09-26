#define GB
#include "monty.h"

void err(stack_t **stack, unsigned int x)
{
  fprintf(stderr, "L%u: unknown instruction %s\n", x, hola.linea);
  free(hola.linea);
  fclose(hola.fil);
  free_l(stack);
  if (stack)
    {

    }
  exit(1);
}
