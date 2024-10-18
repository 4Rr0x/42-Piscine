#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>
#include "map.h"

bool	get_map_len(char *file_name, t_map *map)
{
	int		fd;
	int		bytes_read;
	char	c;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (false);
	bytes_read = read(fd, &c, 1);
	while ((bytes_read == 1) && (c != '\n'))
		bytes_read = read(fd, &c, 1);
	if (c != '\n')
	{
		close(fd);
		return (false);
	}
	map->line_size = 0;
	c = '\0';
	while ((bytes_read == 1) && (c != '\n'))
	{
		bytes_read = read(fd, &c, 1);
		map->line_size++;
	}
	close(fd);
	return (c == '\n');
}

void	print_map(t_map *map)
{
	int	j;

	j = 0;
	while (j++ < map->lines)
	{
		write(1, map->map[j], map->line_size);
		write(1, "\n", 1);
	}
}
