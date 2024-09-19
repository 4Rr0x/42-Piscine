#include <stdio.h>

int	ft_sqrt(int nb)
{
	int	i;
	int	div;

	i = 1;
	div = -1;
	if (nb < 0 || nb == 0)
		return (0);
	if (nb == 1)
		return (1);
	while (i != div && i < nb && (i * i) != nb)
	{
		i++;
		div = nb / i;
	}
	if (i == div)
		return (i);
	else
		return (0);
}
