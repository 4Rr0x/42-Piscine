int	ft_recursive_factorial(int nb)
{
	int	i;

	i = nb;
	if (nb < 0)
		return (0);
	if (nb == 0)
		i++;
	if (nb > 1)
		i *= ft_recursive_factorial(--nb);
	return (i);
}
