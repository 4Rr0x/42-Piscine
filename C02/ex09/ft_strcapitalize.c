#include <stdlib.h>

char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		i++;
	}
	return (str);
}

char	*ft_strcapitalize(char *str)
{
	int		i;
	int		cnt;

	i = -1;
	cnt = 1;
	if (str == NULL)
		return (0);
	ft_strlowcase(str);
	while (str[++i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			if (cnt == 1)
				str[i] -= 32;
			cnt = 0;
		}
		else if (str[i] >= '0' && str[i] <= '9')
			cnt = 0;
		else
			cnt = 1;
	}
	return (str);
}
