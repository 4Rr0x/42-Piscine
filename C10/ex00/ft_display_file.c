#include <unistd.h>
#include <fcntl.h>

void	ft_pustr(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		write(1, &str[i], 1);
}

void	read_file(int op)
{
	int sz
	char *fl[999];
	
}

int	main(int ac, char **av)
{
	int op;
	if (ac == 1)
	{
		ft_putstr("File name missing.");
		return (0);
	}
	if (ac > 2)
	{
		ft_putstr("Too many arguments.");
	}
	op = open(av[1], O_RDONLY);
	if(op < 0)
	{
		ft_putstr("Cannot read file.");
		return (0);
	}
	read_file(op);
}
