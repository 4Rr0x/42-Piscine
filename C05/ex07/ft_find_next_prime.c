int	ft_is_prime(int nb)
{
	int	i;

	i = 2;
	if (nb == 1 || nb == 0 || nb < 0)
		return (0);
	while (i > 1 && i < nb)
	{
		if ((nb % i) == 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	int	p;

	p = 1;
	while (p)
	{
		if (ft_is_prime(nb))
			return (nb);
		nb++;
	}
	return (0);
}
