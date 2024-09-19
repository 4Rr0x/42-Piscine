#include <unistd.h>

void	ft_print_numbers(void)
{
	int		c;
	char	ch;

	c = 0;
	while (c <= 9)
	{
		ch = c + '0';
		write(1, &ch, 1);
		c++;
	}
}
