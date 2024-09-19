#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	check(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i] != '\0')
	{
		j = 0;
		while (base[j] != '\0')
		{
			if (base[i] == base[j] && i != j)
				return (0);
			j++;
		}
		if (base[i] == '-' || base[i] == '+')
			return (0);
		if (base[i] == ' ')
			return (0);
		i++;
	}
	return (1);
}

int	base_len(char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		i++;
	}
	return (i);
}

void	ft_putstr(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		ft_putchar(str[i]);
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	len;

	len = base_len(base);
	if (len >= 2)
	{
		if (check(base))
		{
			if (nbr == -2147483648)
				ft_putstr("-10000000000000000000000000000000");
			else if (nbr < 0)
			{
				ft_putchar('-');
				nbr = -nbr;
				ft_putnbr_base(nbr, base);
			}
			else if (nbr >= len)
			{
				ft_putnbr_base(nbr / len, base);
				ft_putnbr_base(nbr % len, base);
			}
			else
				ft_putchar(base[nbr]);
		}
	}
}
