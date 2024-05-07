/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjamaien <zjamaien@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 22:28:34 by zjamaien          #+#    #+#             */
/*   Updated: 2024/05/07 23:02:05 by zjamaien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	is_validstyle(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		j = i + 1;
		while (base[j])
		{
			if ((base[i] == base[j]) || base[j] == 45 || base [i] == 43)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	printn(int n, int len, char *base)
{
	long	nlong;

	nlong = n;
	if (nlong < 0)
	{
		nlong = -nlong;
		ft_putchar('-');
	}
	if (nlong >= len)
		printn((nlong / len), len, base);
	ft_putchar(base[nlong % len]);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	len;

	len = 0;
	while (base[len])
		len++;
	if (len <= 1 || !is_validstyle(base))
		return ;
	printn(nbr, len, base);
}


int	main(void)
{
	ft_putnbr_base(10,"01");
	return (0);
}

