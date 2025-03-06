#include <stdio.h>
#include <unistd.h>
#include <ctype.h>
void	ft_putchar(char c)
{
	write(1, &c, 1);
}


void	print_add(char s[])
{
	printf("addres from function	[%p]\n", s);
}

void	print_hex(int n)
{
	if (n > 15)
	{
		print_hex(n / 16);
		print_hex(n % 16);
	}
	if (n >= 0 && n <= 9)
		ft_putchar(n + 48);
	if (n > 9 && n < 16)
		ft_putchar(n + 87);
}	

void	print_add_byte(char **s)
{
	unsigned char *ptr = (unsigned char *)&*s;
//	printf("the *s is [%p]\n", &*s);
//	printf("the ptr is [%p]\n", ptr);
	int i = 7;
	while (i >= 0)
	{
		print_hex(*(ptr + i));
		i--;
	}
	write(1, ": ", 1);
}

int	print_value_in_hex(char *s)
{
	int i = 0;
	while (*s)
	{
		if (i % 2 == 0)
			write(1, " ", 1);
		print_hex(*s);
		i++;
		s++;
	}
	write(1, " ", 1);
}
		
	
int	main()
{
	char *sptr = "and     very cool";
	printf("%s\n", sptr);
	print_add_byte(&sptr);
	print_value_in_hex(sptr);
	while(*sptr)
	{
		if (isspace(*sptr))
			write(1, ".", 1);
		else
			write(1, sptr, 1);
		sptr++;
	}
	printf("\n");
	//printf ("%p\n", sptr);
	//print_hex(42);
	return (0);
}

