/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjamaien <zjamaien@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 15:59:07 by zjamaien          #+#    #+#             */
/*   Updated: 2024/05/06 17:23:46 by zjamaien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	while (*str)
	{
		char	*bo;
		char	*pat;

		bo = str;
		pat = to_find;
		while (*str && *pat && *str == *pat)
		{
			str++;
			pat++;
		}
		if (!*pat)
			return (bo);
		str = bo + 1;
	}
	return (NULL);
}		















