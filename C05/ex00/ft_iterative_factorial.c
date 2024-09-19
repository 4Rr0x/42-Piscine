int	ft_iterative_factorial(int nb)
{
	int	i;

	i = nb;
	if (nb < 0)
		return (0);
	if (nb == 0)
		i++;
	while (nb > 1)
		i *= --nb;
	return (i);
}
