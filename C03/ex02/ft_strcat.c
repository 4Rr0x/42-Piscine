int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	cnt_src;

	cnt_src = 0;
	i = ft_strlen(dest);
	while (src[cnt_src])
	{
		dest[i] = src[cnt_src];
		cnt_src++;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
