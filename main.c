#include "LK_prompt.h"

/**
 * main - entry point of codes
 * @argv: argument array
 *@argc: argument count (argc)  
 ** Return: retutn 0
 */

int main(int argc, char **argv)
{
	char *gline;
	char **args;

	if (argc > 1)
	{
		get_input(argv[1]);
	}
	do {
		_prompt();
		gline = read_input();
		args = split_input(gline);
		run_builtins(args);

		free(gline);
		free(args);
	} while (1);
	return (EXIT_SUCCESS);
}
