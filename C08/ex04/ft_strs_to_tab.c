#include <stdlib.h>
#include "ft_stock_str.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char *ft_strdup(char *src)
{
	int	i;
	char *dest;
	char *d;

	i = 0;
	d = (char *)malloc(sizeof(char) + 1 * ft_strlen(src));
	if (!d)
		return (0);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

struct s_stock_str *ft_strs_to_tab(int ac, char **av)
{
	int	i;
	struct s_stock_str *array;

	i = 0;
	array = malloc((ac + 1) * sizeof(struct s_stock_str));
	if (!array)
		return (NULL);
	while (i < ac)
	{
		array[i].str = av[i];
		array[i].copy = ft_strdup(av[i]);
		array[i].size = ft_strlen(av[i]);
		i++;
	}
	array[i].str = 0;
	array[i].copy = 0;
	return (array);
}
