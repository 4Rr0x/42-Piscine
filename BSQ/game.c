#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "map.h"

int	check_max_size_in_join(t_map *map, char *join, int size)
{
	int	i;
	int	j;

	i = 0 - 1;
	while (++i < map->line_size)
	{
		if (join[i] == map->obstacle)
			continue ;
		j = 0;
		while (((i + j) < (map->line_size - 1)) && (join[i + j] == map->empty))
			j++;
		if (j >= size)
			return (i);
		if (j != 0)
			i = i + j;
		else
			i++;
	}
	return (-1);
}

int	proccess_lines(t_map *map, int first_line, int size, char *join)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->line_size)
		join[i++] = map->empty;
	i = 0 - 1;
	while (++i < size)
	{
		j = 0 - 1;
		while (++j < map->line_size)
		{
			if (map->map[first_line + i][j] == map->obstacle)
				join[j] = map->obstacle;
		}
	}
	return (check_max_size_in_join(map, join, size));
}

bool	fill_square(t_map *map, int line, int col, int size)
{
	int	i;
	int	j;

	if (col < 0)
		return (false);
	i = line - 1;
	while (++i < line + size)
	{
		j = col;
		while (j < col + size)
		{
			map->map[i][j++] = map->full;
		}
	}
	return (true);
}

bool	process_game(t_map *map)
{
	int		i;
	int		col;
	int		square_size;
	char	*join;
	bool	ret;

	ret = false;
	join = (char *) malloc(sizeof(char) * map->line_size);
	if (join == NULL)
		return (false);
	square_size = map->lines + 1;
	col = -1;
	while ((col < 0) && (--square_size > 0))
	{
		i = 0 - 1;
		while ((++i + square_size) <= map->lines)
		{
			col = proccess_lines(map, i, square_size, join);
			if (col >= 0)
				break ;
		}
	}
	ret = fill_square(map, i, col, square_size);
	free(join);
	return (ret);
}

void	free_map(t_map *map)
{
	int	i;

	i = 0 - 1;
	while ((map->map != NULL) && (++i < map->lines))
	{
		if (map->map[i] != NULL)
			free(map->map[i]);
	}
	if (map->map != NULL)
		free(map->map);
}
