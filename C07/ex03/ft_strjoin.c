int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

int	ft_lenstrs(int size, char **strs, char *sep)
{
	int	i;
	int	comp;

	i = 0;
	comp = 0;
	while (i < size)
	{
		comp += ft_strlen(strs[i]);
		i++;
	}
	comp += ft_strlen(sep) * (size - 1);
	return (comp);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*str;
	char	*temp;
	int		num;

	num = 0;
	if (size == 0)
		return ((char *)malloc(sizeof(char)));
	str = (char *)malloc(sizeof(char) * (ft_lenstrs(size, strs, sep) + 1));
	if (!str)
		return (0);
	temp = str;
	while (num < size)
	{
		ft_strcpy(temp, strs[num]);
		temp += ft_strlen(strs[num]);
		if (num < size -1)
		{
			ft_strcpy(temp, sep);
			temp += ft_strlen(sep);
		}
		num++;
	}
	*temp = '\0';
	return (str);
}
