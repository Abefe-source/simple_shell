#include "main.h"

/**
 * *_getenv - it gets the specified environment variable
 * @name: specifies the name of the variable
 * @env: specifies the environment variable
 * Returns a pointer to the variable or NULL on failure
 */
char *_getenv(const char *name, char **env)
{
	int i, len; //Variables

	for (len = 0; name[len] != '\0'; len++)
		;
	for (i = 0; env[i]; i++)
		if (_strcmp(name, env[i]) == 0)
			return (&env[i][len + 1]);
	return (NULL);
}
