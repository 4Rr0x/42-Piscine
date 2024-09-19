#include <stdlib.h>

char	*ft_strupcase(char *str)
{
	int	i;

	i = -1;
	if (str == NULL)
		return (0);
	while (str[++i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
	}
	return (str);
}
