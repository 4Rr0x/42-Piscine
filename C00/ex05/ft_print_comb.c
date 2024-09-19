#include <unistd.h>

void	ft_print_comb(void)
{
	char	st;
	char	nd;
	char	rd;

	st = '0';
	while (st <= '7')
	{
		nd = st + 1;
		while (nd <= '8')
		{
			rd = nd + 1;
			while (rd <= '9')
			{
				write(1, &st, 1);
				write(1, &nd, 1);
				write(1, &rd, 1);
				if (st != '7' || nd != '8' || rd != '9')
					write(1, ", ", 2);
				rd++;
			}
			nd++;
		}
		st++;
	}
}
