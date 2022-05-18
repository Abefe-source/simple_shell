#include "main.h"

/**
 *main- it runs a simple shell
 * @ac: the variable is meant to be possibly unused
 * @av: the variable is meant to be possibly unused
 * @env: indicates the environment variable
 *Returns 0 if successful and -1 on failure
 */
int main(int ac, char **av, char **env)
{
	char **argv = NULL, *line = NULL;
	pid_t child;
	ssize_t characters = 0;
	size_t size = 0;    
	size_t i;
	int status = 1, extstat = 0;
	(void)ac;
	(void)av;

	signal(SIGINT, sighelp);

	for (i = 1; characters != -1; i++)
	{
		size = 0;
		characters = -1;
		prompt(1);
		characters = getline(&line, &size, stdin);
		fflush(stdin);      //this gets the command in line
		if (characters == -1)
		{
			getline_fail(argv, line);
			break;
		}
		argv = tok(line, "\t\n ");      //this runs the tok func on line
		if (argv == NULL)
		{
			free(line);
			line = NULL;
			continue;
		}
		if (builtin(env, argv, line, extstat) == 1) //variable is meant to be possibly unused
			continue;
		argv = _path(1, argv, env); //checks/append path
		child = fork(); //here, a child is created
		if (child == -1)
		{
			free_shell(argv, line);
			return (-1);
		}
		if (child == 0)
		{
			stat_exec(argv, line, i, env);  //the command is executed
			_exit(1);
		}
		else
		{
			free_shell(argv, line);
			wait(&status);      //here it waits for current process to finish
			if (WIFEXITED(status))
				extstat = WEXITSTATUS(status);
		}
	}
	if (isatty(0))
		free_shell(argv, line);     //frees all in parent
	return (0);
}