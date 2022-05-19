#include "main.h"

/**
 *stat_exec- it checks if command exists and executes it if it does
 *@argv: specifies the array of commands
 *@line: shows that the line argv was made from (only to free)
 *@i: specifies number of lines in shell
 *@env: specifies environment
 *Returns 0 if success and -1 if need to break
 */
int stat_exec(char **argv, char *line, size_t i, char **env)
{
	struct stat st;
	int j;
	char *path = "_";
	char *envi = _getenv(path, env);
	(void)line;

	if (stat(argv[0], &st) != 0)
	{
		write(STDERR_FILENO, envi, _strlen(envi) + 1);
		write(STDERR_FILENO, ": ", 2);
		print_number(i);
		write(STDERR_FILENO, ": ", 2);
		write(STDERR_FILENO, argv[0], strlen(argv[0]) + 1);
		write(STDERR_FILENO, ": not found\n", 12);
	}
	else
	{		//executes the command
		if (execve(argv[0], argv, NULL) == -1 && isatty(0))
		{
			write(STDERR_FILENO, envi, _strlen(envi) + 1);
			write(STDERR_FILENO, ": ", 2);
			print_number(i);
			write(STDERR_FILENO, ": ", 2);
			write(STDERR_FILENO, argv[0], strlen(argv[0]) + 1);
			write(STDERR_FILENO, ": not found\n", 12);
		}
	}
	for (j = 0 ; argv[j] != NULL ; j++)
		free(argv[j]);
	free(argv);
	return (0);
}