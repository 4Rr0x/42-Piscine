#include <unistd.h>

void    ft_putstr(char *str)
{
    int i;

    i = -1;
    while(str[++i])
    {
        write(1, &str[i], 1);
    }
    write(1, "\n", 1);
}

void	ft_putarg(char **argv)
{
	while (*argv)
	{
		ft_putstr(*argv++);
		write (1, "\n", 1);
	}
}

int	ft_strcmp(char *str1, char *str2)
{
	int	i;

	i = 0;
	while (str1[i] != '\0' && str[2] != '\0' && str1[i] == str2[i])
	{
		i++;
	}
	return (str1[i] - str2[i]);
}

void	ft_sort(char *arr[], int size)
{
	char	*temp;
	int		i;
	int		j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (ft_strcmp(arr[j], arr[j + 1]) > 0)
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}


int	main(int argc,char **argv)
{
	int	i;

	i = 1;
	if (argc > 1)
	{
		ft_sort(argv + 1, argc - 1);
		ft_putarg(argv + 1);
	}
	return (0);
}
