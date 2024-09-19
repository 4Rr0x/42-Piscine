/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopedro- <jopedro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 16:46:24 by jopedro-          #+#    #+#             */
/*   Updated: 2024/09/15 20:03:12 by jopedro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

#define GRID_SIZE 4

int		fill(int mat[GRID_SIZE][GRID_SIZE], int outlines[4][GRID_SIZE],
			int row, int col);
void	fill_edge_tb(int row[GRID_SIZE], int mat[GRID_SIZE][GRID_SIZE],
			int cnt);
void	fill_edge_lr(int row[GRID_SIZE], int mat[GRID_SIZE][GRID_SIZE],
			int cnt);
int		check_vis(int mat[GRID_SIZE][GRID_SIZE], int outlines[4][GRID_SIZE]);
int		right_check(int mat[GRID_SIZE][GRID_SIZE], int right[GRID_SIZE]);
int		left_check(int mat[GRID_SIZE][GRID_SIZE], int left[GRID_SIZE]);
int		top_check(int mat[GRID_SIZE][GRID_SIZE], int top[GRID_SIZE]);
int		bot_check(int mat[GRID_SIZE][GRID_SIZE], int bot[GRID_SIZE]);
void	fill_outlines(char *str, int outlines[4][GRID_SIZE]);
void	ft_putmat(int mat[GRID_SIZE][GRID_SIZE]);
void	ft_putstr(char *str);
void	ft_putchar(char c);
void	ft_putnbr(int nb);
int		arg_check(char *str);

void	initialize_matrix(int mat[GRID_SIZE][GRID_SIZE])
{
	int	i;
	int	j;

	i = 0;
	while (i < GRID_SIZE)
	{
		j = 0;
		while (j < GRID_SIZE)
		{
			mat[i][j] = 0;
			j++;
		}
		i++;
	}
}

int	num_check(int mat[GRID_SIZE][GRID_SIZE], int row, int col, int num)
{
	int	i;

	i = 0;
	while (i < GRID_SIZE)
	{
		if (mat[row][i] == num || mat[i][col] == num)
			return (0);
		i++;
	}
	return (1);
}

void	fill_all(int mat[GRID_SIZE][GRID_SIZE],
	int outlines[4][GRID_SIZE])
{
	fill_edge_tb(outlines[0], mat, 0);
	fill_edge_tb(outlines[1], mat, 3);
	fill_edge_lr(outlines[2], mat, 1);
	fill_edge_lr(outlines[3], mat, 2);
}

int	main(int ac, char **av)
{
	int	mat[GRID_SIZE][GRID_SIZE];
	int	outlines[4][GRID_SIZE];

	if (ac != 2)
	{
		ft_putstr("Error! Only 1 argument accepted!\n");
		return (0);
	}
	if (!arg_check(av[1]))
	{
		ft_putstr("Error! Invalid input numbers!\n");
		return (0);
	}
	initialize_matrix(mat);
	fill_outlines(av[1], outlines);
	fill_all(mat, outlines);
	if (fill(mat, outlines, 0, 0))
		ft_putmat(mat);
	else
		ft_putstr("Error! No solution found\n");
}
