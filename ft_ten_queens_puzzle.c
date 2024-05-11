/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjamaien <zjamaien@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 21:46:06 by zjamaien          #+#    #+#             */
/*   Updated: 2024/05/11 23:23:49 by zjamaien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h> 

void	nqueen(int board[], int r, int *count);

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

void	print_res(int board[])
{
	int		i;
	char	c;

	i = 0;
	while (i < 10)
	{
		c = board[i] + '0';
		write(1, &c, 1);
		i++;
	}
	write(1, "\n", 1);
}

int	is_safe(int board[], int r, int c)
{
	int	i;

	i = 0;
	while (i < r)
	{
		if (board[i] == c || ft_abs(i - r) == ft_abs(board[i] - c))
			return (0);
		i++;
	}
	return (1);
}

int	ft_ten_queens_puzzle(void)
{
	int	board[10];
	int	count;
	int	i;

	i = 0;
	while (i < 10)
		board[i++] = -1;
	nqueen(board, 0, &count);
	return (count);
}

void	nqueen(int board[], int r, int *count)
{
	int	c;

	if (r == 10)
	{
		print_res(board);
		(*count)++;
		return ;
	}
	c = 0;
	while (c < 10)
	{
		if (is_safe(board, r, c))
		{
			board[r] = c;
			nqueen(board, r + 1, count);
			board[r] = -1;
		}
		c++;
	}
}

int main() {
  //int x = 
	ft_ten_queens_puzzle();
   // printf("Total solutions: %d\n", x);
    return 0;
}

