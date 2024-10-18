#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>
#include "map.h"

bool	check_chars(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < map->lines)
	{
		j = 0;
		while (j < map->line_size)
		{
			if (map->map[i][j] != map->empty
				&& map->map[i][j] != map->obstacle
				&& map->map[i][j] != '\0')
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

bool	check_printable(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < map->lines)
	{
		j = 0;
		while (j < map->line_size)
		{
			if (map->map[i][j] < 32 && map->map[i][j] > 0)
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

bool	char_cmp(char c, char d)
{
	if (c == d)
		return (true);
	return (false);
}

bool	check_equal(t_map *map)
{
	if (char_cmp(map->empty, map->full)
		|| char_cmp(map->empty, map->obstacle)
		|| char_cmp(map->obstacle, map->full))
		return (false);
	return (true);
}

bool	check_map(t_map *map)
{
	if (check_chars(map) == false)
		return (false);
	if (check_printable(map) == false)
		return (false);
	if (check_equal(map) == false)
		return (false);
	return (true);
}
