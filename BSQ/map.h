#ifndef MAP_H
# define MAP_H

typedef struct s_map
{
	int		line_size;
	int		lines;
	char	**map;
	char	empty;
	char	obstacle;
	char	full;
}	t_map;

#endif // MAP_H
