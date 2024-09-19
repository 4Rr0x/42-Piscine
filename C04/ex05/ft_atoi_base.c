#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int check(char *base)
{
    int i;
    int j;

    i = 0;
    while(base[i] != '\0')
    {
        j = 0;
        while(base[j] != '\0')
        {
            if(base[i] == base[j] && i != j)
                return (0);
            j++;
        }
        if(base[i] == '-' || base[i] == '+')
            return (0);
        if(base[i] == ' ')
            return (0);
        i++;
    }
    return (1);
}

int base_len(char *base)
{
    int i;

    i = 0;
    while(base[i] != '\0')
    {
        i++;
    }
    return(i);
}

int	ft_atoi_base(char *str)
{
	int	num;
	int	sign;

	sign = 1;
	num = 0;
	while (*str == ' ' || *str == '\t' || *str == '\n'
		|| *str == '\v' || *str == '\f' || *str == 'r')
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		num = (num * 10) + (*str - 48);
		str++;
	}
	return (num * sign);
}
