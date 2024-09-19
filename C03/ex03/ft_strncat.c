int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	unsigned int	cnt_src;

	cnt_src = 0;
	i = ft_strlen(dest);
	while (src[cnt_src] != '\0' && cnt_src < nb)
	{
		dest[i] = src[cnt_src];
		i++;
		cnt_src++;
	}
	dest[i] = '\0';
	return (dest);
}
