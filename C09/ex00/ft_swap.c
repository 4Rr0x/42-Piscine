void	ft_swap(int *a, int *b)
{
	int	temp;

	if(!a || !b)
		return ;
	temp = *a;
	*a = *b;
	*b = temp;
}
