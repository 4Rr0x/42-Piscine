#include <stdio.h>

int	ft_sqrt(int nb)
{
	int	i;

	i = 0;
	if (nb == 1)
		return (1);
	while (i < nb)
	{
		if (i * i == nb)
			return (nb);
		i++;
	}
	return (0);
}
