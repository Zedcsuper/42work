/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjamaien <zjamaien@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 20:50:33 by zjamaien          #+#    #+#             */
/*   Updated: 2024/05/06 23:15:32 by zjamaien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	if (!*str)
		return (0);
	return (1 + ft_strlen(str + 1));
}

unsigned int ft_strlcat(char *dest, char *src, unsigned int size)
{
	int	srclen;
	int	destlen;
	int	totallen;
	unsigned int	i;
	srclen = ft_strlen(src);
	destlen = ft_strlen(dest);
	i = destlen;
	totallen = srclen + destlen;
	if (size <= (unsigned int) destlen)
		return totallen;
	while (*src && (i < size -1))
		dest[i++] = *src++;
	dest[i] = '\0';
	return (totallen);
}
