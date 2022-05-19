#include "main.h"

/**
 *builtin- it checks if the user input is a built-in command and executes it
 *@env: specifies the current environment
 *@argv: specifies the list of arguments provided
 *@line: specifies the line from getline
 *@extstat: status for empty exit
 *Returns 1 if builtin and 0 if failure
 */

int builtin(char **env, char **argv, char *line, int extstat)
{
	int i;

	if (_strcmp("env", argv[0]) == 0)      //envronment
	{
		if (argv[1] == NULL)
		{
			for (i = 0 ; env[i] ; i++)
			{
				write(1, env[i], _strlen(env[i]));
				write(1, "\n", 1);
			}
			free_shell(argv, line);
		}
		else
		{
			write(STDERR_FILENO, "env: ", 5);
			write(STDERR_FILENO, argv[1], strlen(argv[0]) + 1);
			write(STDERR_FILENO, ": No such file or directory\n",
			      28);
		}
		return (1);
	}
	else if (_strcmp("exit", argv[0]) == 0) //exit
	{
		if (argv[1] == NULL)
		{
			free_shell(argv, line);
			exit(extstat);
		}
		i = atoi(argv[1]);
		free_shell(argv, line);
		exit(i);
	}
	return (0);
}
