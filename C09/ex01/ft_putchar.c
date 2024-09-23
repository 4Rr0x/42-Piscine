#include <unistd.h>

void	ft_putchar(char c)
{
	if (!c)
		return ;
	write(1, &c, 1);
}
