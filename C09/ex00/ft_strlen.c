int	ft_strlen(char *str)
{
	int	i;

	if(!str)
		return (0);
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}
