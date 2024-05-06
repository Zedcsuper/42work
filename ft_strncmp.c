/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjamaien <zjamaien@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 12:33:11 by zjamaien          #+#    #+#             */
/*   Updated: 2024/05/06 14:16:48 by zjamaien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	int	i;

	i = 0;
	if (n < 1)
		return (0);
	while (s1[i] == s2[i] && s1[i] && (n -1  > 0))
	{
		i++;
		n--;
	}
	return (s1[i] - s2[i]);
}
/*
int	main(void)
{
	char a[] = "abc";
	char b[] = "abc";
	int x = ft_strncmp(a, b, 4);
	printf("%d\n", x);
	return (0);
}
*/
