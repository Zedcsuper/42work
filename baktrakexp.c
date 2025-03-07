#include<stdio.h>
#include "naruto.h"

#define N	1

void	binNarutoHelper(uint8_t idx, uint8_t digits, char *v)
{
	if (idx == digits)
		p("%s\n", v);
	else
	{
		v[idx] = '0';
		binNarutoHelper(idx + 1, digits, v);
		v[idx] = '1';
		binNarutoHelper(idx + 1, digits, v);
	}
}	

void	binNaruto(uint8_t digits)
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
	binNaruto(N);
}

