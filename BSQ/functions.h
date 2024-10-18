#ifndef FUNCTIONS_H
# define FUNCTIONS_H

# include <stdbool.h>
# include "map.h"

bool	read_file(char *file_name, t_map *map);
bool	process_game(t_map *map);
void	free_map(t_map *map);
bool	read_from_stdin(t_map *map);
bool	read_first_line(int fd, t_map *map);
bool	fill_line(char *buffer, t_map *map, int row, int buffer_size);
bool	check_chars(t_map *map);
bool	check_printable(t_map *map);
bool	char_cmp(char c, char d);
bool	check_equal(t_map *map);
bool	check_map(t_map *map);
bool	get_map_len(char *file_name, t_map *map);
void	print_map(t_map *map);

#endif // FUNCTIONS_H
