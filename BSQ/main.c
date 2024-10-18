#include <stdbool.h>
#include <unistd.h>
#include "map.h"
#include "functions.h"
// Apagar
#include <stdio.h>

bool	proc_ac(t_map *map)
{
	if (!read_from_stdin(map))
	{
		{
			write(1, "map error\n", 10);
			return (0);
		}
		if (process_game(map))
		{
			print_map(map);
			return (true);
		}
		else
		{
			write(1, "Solution not found\n", 19);
			return (false);
		}
	}
	free_map(map);
	return (true);
}

int	main(int argc, char *argv[])
{
	int		i;
	t_map	map;

	if (argc == 1)
	{
		if (!proc_ac(&map))
			return (0);
	}
	i = 0;
	while (++i < argc)
	{
		if (!read_file(argv[i], &map))
		{
			write(1, "map error\n", 10);
			continue ;
		}
		if (process_game(&map))
			print_map(&map);
		else
			write(1, "Solution not found\n", 19);
		free_map(&map);
	}
	return (0);
}
