/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjamaien <zjamaien@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 14:35:18 by zjamaien          #+#    #+#             */
/*   Updated: 2024/05/25 14:42:53 by zjamaien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

char *ft_strncpy(char *s1, char *s2, int n)
{
	int i = -1;

	while (++i < n && s2[i])
		s1[i] = s2[i];
	s1[i] = '\0';
	return (s1);
}

char **ft_split(char *str)
{
	int i = 0;
	int j = 0;
	int k = 0;
	int wc = 0;

	// Count the number of words
	while (str[i])
	{
		while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
			i++;
		if (str[i])
			wc++;
		while (str[i] && (str[i] != ' ' && str[i] != '\t' && str[i] != '\n'))
			i++;
	}

	char **out = (char **)malloc(sizeof(char *) * (wc + 1));
	if (!out)
		return (NULL);

	i = 0;
	// Split the string into words
	while (str[i])
	{
		while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
			i++;
		j = i;
		while (str[i] && (str[i] != ' ' && str[i] != '\t' && str[i] != '\n'))
			i++;
		if (i > j)
		{
			out[k] = (char *)malloc(sizeof(char) * ((i - j) + 1));
			if (!out[k])
			{
				// Free previously allocated memory in case of failure
				while (k > 0)
					free(out[--k]);
				free(out);
				return (NULL);
			}
			ft_strncpy(out[k++], &str[j], i - j);
		}
	}
	out[k] = NULL;
	return (out);
}

int main(void)
{
	char arr[] = "zaid is best man ever";
	char **arr2 = ft_split(arr);
	int i = 0;

	// Print the split strings
	while (arr2[i])
		printf("%s\n", arr2[i++]);

	// Free the allocated memory
	i = 0;
	while (arr2[i])
		free(arr2[i++]);
	free(arr2);

	return (0);
}

