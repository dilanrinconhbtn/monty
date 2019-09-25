#include "header.h"
char *opco;
int global;

int tamanio(char *linea)
{

  unsigned int contador = 0;

  while (linea[contador])
    {
      contador++;
    }
  return (contador);

}
char quitarsalto(char *linea)
{

  int ta = tamanio(linea);
  linea[ta - 1] = '\0';

  return(*linea);
}
void pall(stack_t **stack, unsigned int num_linea)
{
  stack_t *ojo;
 
  ojo = *stack;
  if (ojo != NULL)
    {
      while (ojo)
	{
	  printf("%d\n", ojo->n);
	  ojo = ojo->next;
	}
    }
}
void swap(stack_t **stack, unsigned int num_linea)
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

void add(stack_t **stack, unsigned int num_linea)
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

void pop(stack_t **stack, unsigned int num_linea)
{
  stack_t *ojo;

  ojo = *stack;
  if (ojo == NULL)
    {
      printf("error en la linea %ud\n", num_linea);
      exit(0);
    }
  if((*stack)->next)
    {
      *stack = ojo->next;
      (*stack)->prev = NULL;
      free(ojo);
    }
  else
    *stack = NULL;
}

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
     /*     while ((*stack)->next)
       *stack = (*stack)->next;
      (*stack)->next = ojo;
      ojo->prev = *stack;
      while((*stack)->prev)
      *stack = (*stack)->prev;*/
    }
  else
    *stack = ojo;
}
void (*func(char *tokens))(stack_t **stack, unsigned int num_linea)
{
  instruction_t ops[] = {    
    {"push", push},
    {"pall", pall},
    {"pint", pint},
    {"pop", pop},
    {"swap", swap},
    {"add", add},
    /*{"nop", nop},
    {"sub", sub},
    {"div", div},
    {"mul", mul},
    {"mod", mod},
    {"pchar", pchar},
    {"rotl", rotl},
    {"rotr", rotr},
    {"stack", stack},
    {"queue", queue},*/
    {NULL, NULL}
  };
  int i = 0;
  int o;
  while (i < 6)
    {
      o = strcmp(ops[i].opcode, tokens);
      if (o == 0)
	return (ops[i].f);
      i++;
    }
  fputs("Error en la linea", stderr);
  return (NULL);
}
int main(int argc, char **argv)
{
  stack_t *stack;
  FILE *fil;
  size_t numbytes = 0;
  char *linea = NULL;
  int bytesleidos = 0;
  char *tokens;
  unsigned int contador = 1;
  fil = fopen(argv[1], "r");
  if (fil == NULL)
    exit(EXIT_FAILURE);

  stack = NULL;

  while((bytesleidos = getline(&linea, &numbytes, fil)) != EOF)
    {
      quitarsalto(linea);
      if (linea[0] != 00 && linea[0] != 35)
	{
	  tokens = strtok(linea, " ");
	  opco = tokens;
	  if (opco != NULL)
	    {
	      tokens = strtok(NULL, " ");
	      if (tokens)
		global = atoi(tokens);
	      func(opco)(&stack, contador);
	      contador++;
	    }
	}
    } 
}

