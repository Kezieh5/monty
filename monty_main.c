#include "monty.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

char **op_toks = NULL;

/**
 * main - the entry point for Monty Interp
 *
 * @argc: the count of arguments passed to the program
 * @argv: pointer to an array of char pointers to arguments
 *
 * Return: (EXIT_SUCCESS) on success (EXIT_FAILURE) on error
 */
int main(int argc, char **argv)
{
	int exit_code = EXIT_SUCCESS;
	FILE *script_fd;

	if (argc != 2)
	{
		usage_error();
		return (exit_code);
	}

	script_fd = fopen(argv[1], "r");
	if (script_fd == NULL)
	{
		f_open_error(argv[1]);
		return (exit_code);
	}

	exit_code = run_monty(script_fd);
	fclose(script_fd);
	return (exit_code);
}
