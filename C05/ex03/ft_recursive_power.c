int	ft_recursive_power(int nb, int power)
{
	int	i;

	i = 1;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	if (i < power)
		nb *= ft_recursive_power(nb, --power);
	return (nb);
}
