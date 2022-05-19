#include "main.h"

/**
 **_path - this appends the user input onto the PATH if necessary
 * @argc: specifies argument count
 * @argv: specifies the given argument
 * @env: specifies the environment variable
 * Returns a pointer to the full argument, with PATH
 */
char **_path(int argc, char **argv, char **env)
{
	int i, k;
	char *path = "PATH";
	char *str;
	char **strs;
	struct stat st;
	(void)argc;

	str = _getenv(path, env);      /*it gets the env*/
	strs = tok(str, ":");   /*it separates the tokens*/
	for (k = 0 ; strs[k] != NULL ; k++)
	{
	    /*this iterates to the end of a given element in the array*/
		strs[k] = str_concat(strs[k], "/");
		/*this appends the command that the user types to the given path element*/
		strs[k] = str_concat(strs[k], argv[0]);
		/*here the command is checked to see if it exists*/
		if (stat(strs[k], &st) == 0)
		{
			free(argv[0]);
			argv[0] = _strdup(strs[k]);
			/*frees everything*/
			for (i = 0 ; strs[i] != NULL ; i++)
				free(strs[i]);
			free(strs);


			return (argv);
		}
	}
	for (i = 0 ; strs[i] != NULL ; i++)
		free(strs[i]);


	free(strs);
	return (argv);
}
