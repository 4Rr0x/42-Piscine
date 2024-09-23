#include <unistd.h>
#include <stdlib.h>

#define GRID_SIZE 4

int	top_check(int mat[GRID_SIZE][GRID_SIZE], int top[GRID_SIZE])
{
	int	max;
	int	row;
	int	col;
	int	vis;

	col = 0;
	while (col < GRID_SIZE)
	{
		row = 0;
		vis = 0;
		max = 0;
		while (row < GRID_SIZE)
		{
			if (mat[row][col] > max)
			{
				max = mat[row][col];
				vis++;
			}
			row++;
		}
		if (vis != top[col])
			return (0);
		col++;
	}
	return (1);
}

int	bot_check(int mat[GRID_SIZE][GRID_SIZE], int bot[GRID_SIZE])
{
	int	max;
	int	row;
	int	col;
	int	vis;

	col = 0;
	while (col < GRID_SIZE)
	{
		row = GRID_SIZE - 1;
		vis = 0;
		max = 0;
		while (row >= 0)
		{
			if (mat[row][col] > max)
			{
				max = mat[row][col];
				vis++;
			}
			row--;
		}
		if (vis != bot[col])
			return (0);
		col++;
	}
	return (1);
}

int	left_check(int mat[GRID_SIZE][GRID_SIZE], int left[GRID_SIZE])
{
	int	max;
	int	row;
	int	col;
	int	vis;

	row = 0;
	while (row < GRID_SIZE)
	{
		col = 0;
		vis = 0;
		max = 0;
		while (col < GRID_SIZE)
		{
			if (mat[row][col] > max)
			{
				max = mat[row][col];
				vis++;
			}
			col++;
		}
		if (vis != left[row])
			return (0);
		row++;
	}
	return (1);
}

int	right_check(int mat[GRID_SIZE][GRID_SIZE], int right[GRID_SIZE])
{
	int	max;
	int	row;	
	int	col;
	int	vis;

	row = 0;
	while (row < GRID_SIZE)
	{
		col = GRID_SIZE - 1;
		vis = 0;
		max = 0;
		while (col >= 0)
		{
			if (mat[row][col] > max)
			{
				max = mat[row][col];
				vis++;
			}
			col--;
		}
		if (vis != right[row])
			return (0);
		row++;
	}
	return (1);
}

int	check_vis(int mat[GRID_SIZE][GRID_SIZE], int outlines[4][GRID_SIZE])
{
	return (top_check(mat, outlines[0]) && bot_check(mat, outlines[1])
		&& left_check(mat, outlines[2]) && right_check(mat, outlines[3]));
}
