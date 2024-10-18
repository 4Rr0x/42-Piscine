/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopedro- <jopedro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 19:39:13 by djunho            #+#    #+#             */
/*   Updated: 2024/09/25 12:21:10 by jopedro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>
#include "map.h"
#include "functions.h"

bool	read_from_stdin(t_map *map)
{
	char	buffer[1024];
	char	*ptr;
	ssize_t	bytes_read;
	int		i;
	bool	ret;

	ret = read_first_line(0, map);
	map->map = (char **)malloc(sizeof(char *) * map->lines);
	if (map->map == NULL)
		return (false);
	i = 0 - 1;
	while (++i < map->lines)
		map->map[i] = NULL;
	bytes_read = read(STDIN_FILENO, buffer, 1024);
	i = 0;
	while ((i < bytes_read) && (buffer[i] != '\n'))
		i++;
	if ((i == bytes_read) || (buffer[i] != '\n'))
		return (false);
	map->line_size = i + 1;
	i = 0;
	while ((ret == true) && (bytes_read > 0) && (i < map->lines))
	{
		ptr = buffer;
		while (bytes_read >= map->line_size)
		{
			ret = fill_line(ptr, map, i++, map->line_size);
			bytes_read -= map->line_size;
			ptr += map->line_size;
		}
		if (bytes_read != 0)
			return (false);
		bytes_read = read(STDIN_FILENO, buffer, 1024);
	}
	if (bytes_read == -1)
		ret = false;
	return (ret);
}

bool	read_first_line(int fd, t_map *map)
{
	int		bytes_read;
	char	c;

	map->lines = 0;
	map->full = '\0';
	map->empty = '\0';
	map->obstacle = '\0';
	bytes_read = read(fd, &c, 1);
	while ((bytes_read == 1) && ((c >= '0') && (c <= '9')))
	{
		map->lines = (map->lines * 10) + (c - '0');
		bytes_read = read(fd, &c, 1);
	}
	if (bytes_read != 1)
		return (false);
	map->empty = c;
	read(fd, &c, 1);
	map->obstacle = c;
	read(fd, &c, 1);
	map->full = c;
	if ((map->empty == '\0') || (map->obstacle == '\0') || (map->full == '\0'))
		return (false);
	read(fd, &c, 1);
	return (true);
}

bool	fill_line(char *buffer, t_map *map, int row, int buffer_size)
{
	int	j;

	if (buffer_size != map->line_size)
		return (false);
	map->map[row] = (char *)malloc(sizeof(char) * (map->line_size));
	if (map->map[row] == NULL)
		return (false);
	j = 0;
	while (j < buffer_size)
		map->map[row][j++] = *buffer++;
	if (map->map[row][buffer_size - 1] != '\n')
		return (false);
	map->map[row][buffer_size - 1] = '\0';
	return (true);
}

// TODO: Fix the malloc error in the middle of process
bool	fill_map(int fd, t_map *map)
{
	int	i;
	int	bytes_read;

	map->map = (char **)malloc(sizeof(char *) * map->lines);
	if (map->map == NULL)
		return (false);
	i = 0 - 1;
	while (++i < map->lines)
		map->map[i] = NULL;
	i = 0;
	while (i < map->lines)
	{
		map->map[i] = (char *)malloc(sizeof(char) * (map->line_size));
		if (map->map[i] == NULL)
			return (false);
		bytes_read = read(fd, map->map[i], map->line_size);
		if (bytes_read != map->line_size)
			return (false);
		if (map->map[i][bytes_read - 1] != '\n')
			return (false);
		map->map[i++][bytes_read - 1] = '\0';
	}
	return (true);
}

bool	read_file(char *file_name, t_map *map)
{
	int		fd;
	bool	ret;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (false);
	ret = false;
	while (1)
	{
		if (read_first_line(fd, map) == false)
			break ;
		if (get_map_len(file_name, map) == false)
			break ;
		if (fill_map(fd, map) == false)
			break ;
		if (check_map(map) == false)
			break ;
		ret = true;
		break ;
	}
	close(fd);
	return (ret);
}
