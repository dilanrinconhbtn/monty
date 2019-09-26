#define GB
#include "monty.h"


/**
 * tamanio - size
 * @linea: linea
 * Return: linea
 */
int tamanio(char *linea)
{
	unsigned int contador = 0;

	while (linea[contador])
	{
		contador++;
	}
	return (contador);
}


/**
 * quitarsalto - remove line
 * @linea: linea
 * Return: linea
 */
char quitarsalto(char *linea)
{
	int ta = tamanio(linea);

	linea[ta - 1] = '\0';
	return(*linea);
}

/**
 * pop - delete first noce
 * @stack: head of the linked list
 * @num_linea: number of the line
 * Return: Nothing
 */
void pop(stack_t **stack, unsigned int num_linea)
{
	stack_t *ojo;

	ojo = *stack;
	if (ojo == NULL)
	{
	  fprintf(stderr, "L%d: can't pop an empty stack", num_linea);
	  exit(1);
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

/**
 * func - pointers to functions
 * @tokens: arguments
 * @stack: head of the linked
 * @num_linea: number of the line
 * Return: NULL
 */

void (*func(char *tokens))(stack_t **stack, unsigned int num_linea)
{
	instruction_t ops[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", divi},
		/*{"mul", mul},
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
	while (i < 9)
	{
		o = strcmp(ops[i].opcode, tokens);
		if (o == 0)
			return (ops[i].f);
		i++;
	}
	fputs("Error en la linea", stderr);
	return (NULL);
}

/**
 * main - main function
 * @argc: number of the arguments
 * @argv: argument
 * Return: Always 0
 */
int main(int argc,char **argv)
{
	stack_t *stack;
	FILE *fil;
	size_t numbytes = 0;
	char *linea = NULL, *tokens, *opco;
	int bytesleidos = 0;
	unsigned int contador = 1;

	if (argc)
	{
		
	}
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
				{
					if (verif(tokens) == 0)
						hola.numero = atoi(tokens);
					else
					{
						fprintf(stderr,"L%u: usage: push integer\n", contador);
						free_l(&stack);
						free(linea);
						fclose(fil);
						exit(1);
					}
				}
				func(opco)(&stack, contador);
				contador++;
			}
		}
        }
	free_l(&stack);
	free(linea);
	fclose(fil);
	return (0);
}
