int	ft_iterative_power(int nb, int power)
{
	int	i;
	int	org;

	i = 1;
	org = nb;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	while (i < power)
	{
		nb *= org;
		i++;
	}
	return (nb);
}
