#include <unistd.h>
#include <stdlib.h>

#define GRID_SIZE 4

int	num_check(int mat[GRID_SIZE][GRID_SIZE], int row, int col, int num);
int	check_vis(int mat[GRID_SIZE][GRID_SIZE], int outlines[4][GRID_SIZE]);

int	fill(int mat[GRID_SIZE][GRID_SIZE], int outlines[4][GRID_SIZE],
	int row, int col)
{
	int	num;

	if (row == GRID_SIZE)
		return (check_vis(mat, outlines));
	if (col == GRID_SIZE)
		return (fill(mat, outlines, row + 1, 0));
	if (mat[row][col] != 0)
		return (fill(mat, outlines, row, col + 1));
	num = 1;
	while (num <= GRID_SIZE)
	{
		if (num_check(mat, row, col, num))
		{
			mat[row][col] = num;
			if (fill(mat, outlines, row, col + 1))
				return (1);
			mat[row][col] = 0;
		}
		num++;
	}
	return (0);
}

void	fill_edge_tb(int row[GRID_SIZE], int mat[GRID_SIZE][GRID_SIZE], int cnt)
{
	int	i;

	i = 0;
	if (cnt == 0)
	{
		while (i < GRID_SIZE)
		{
			if (row[i] == 4)
				mat[0][i] = 1;
			else if (row[i] == 1)
				mat[0][i] = 4;
			i++;
		}
	}
	else if (cnt == 3)
	{
		while (i < GRID_SIZE)
		{
			if (row[i] == 4)
				mat[3][i] = 1;
			else if (row[i] == 1)
				mat[3][i] = 4;
			i++;
		}
	}
}

void	fill_edge_lr(int row[GRID_SIZE], int mat[GRID_SIZE][GRID_SIZE], int cnt)
{
	int	i;

	i = 0;
	if (cnt == 1)
	{
		while (i < GRID_SIZE)
		{
			if (row[i] == 4)
				mat[i][0] = 1;
			else if (row[i] == 1)
				mat[i][0] = 4;
			i++;
		}
	}
	else if (cnt == 2)
	{
		while (i < GRID_SIZE)
		{
			if (row[i] == 4)
				mat[i][3] = 1;
			else if (row[i] == 1)
				mat[i][3] = 4;
			i++;
		}
	}
}

void	fill_outlines(char *str, int outlines[4][GRID_SIZE])
{
	int	i;
	int	c;

	i = -1;
	c = 0;
	while (str[++i])
	{
		if (str[i] >= '0' && str[i] <= '4')
		{
			if (i / 8 == 0)
				outlines[0][c % 4] = str[i] - '0';
			else if (i / 8 == 1)
				outlines[1][c % 4] = str[i] - '0';
			else if (i / 8 == 2)
				outlines[2][c % 4] = str[i] - '0';
			else if (i / 8 == 3)
				outlines[3][c % 4] = str[i] - '0';
			c++;
		}
	}
}
