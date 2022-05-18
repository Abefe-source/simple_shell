#include <stdio.h>
/**
*
* main- 
* return 0
*/
 int main (int ac, char **av)
{
	int i;
	for (i =0; *av[i] != '\0'; i++)
		printf("%s\n",av[i]);
		return 0;
}
