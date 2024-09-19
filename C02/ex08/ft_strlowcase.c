#include <stdlib.h>

char	*ft_strlowcase(char *str)
{
	int	i;

	i = -1;
	if (str == NULL)
		return (0);
	while (str[++i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
	}
	return (str);
}
