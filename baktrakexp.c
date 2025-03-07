#include <stdio.h>
#include <stdlib.h>

void	binNarutoHelper(char idx, char digits, char *v)
{
	if (idx == digits)
		printf("%s\n", v);
	else
	{
		v[idx] = '0';
		binNarutoHelper(idx + 1, digits, v);
		v[idx] = '1';
		binNarutoHelper(idx + 1, digits, v);
	}
}	

void	binNaruto(char digits)
{
	char	*v;

	v = calloc(digits + 1, sizeof *v);
	if (NULL == v)
	{
		perror("Calloc fialed");
		return ;
	}
	binNarutoHelper(0, digits, v);
	free(v);
}

int	main()
{
	binNaruto(2);
}
