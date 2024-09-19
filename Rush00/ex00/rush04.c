void	ft_middle(int x, int y, int len, int col);
void	ft_first_last(int x, int len, int b);
void	ft_putchar(char c);

int	rush(int x, int y)
{
	int	len;
	int	col;

	len = 1;
	col = 1;
	if (x <= 0 || y <= 0)
		return (0);
	ft_first_last(x, len, 1);
	ft_putchar('\n');
	ft_middle(x, y, len, col);
	if (y > 1)
	{
		ft_first_last(x, len, 0);
		ft_putchar('\n');
	}
	return (0);
}

void	ft_first_last(int x, int len, int b)
{
	if (b == 1)
		ft_putchar('A');
	else
		ft_putchar('C');
	while (len < x - 1)
	{
		ft_putchar('B');
		len++;
	}
	if (x > 1)
	{
		if (b == 1)
			ft_putchar('C');
		else
			ft_putchar('A');
	}
}

void	ft_middle(int x, int y, int len, int col)
{
	while (col < y - 1)
	{
		ft_putchar('B');
		while (len < x - 1)
		{
			ft_putchar(' ');
			++len;
		}
		if (x > 1)
			ft_putchar('B');
		len = 1;
		ft_putchar('\n');
		col++;
	}
}
