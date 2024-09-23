char	*sep_word(char *str, char *charset)
{
	int	i;
	int	j;
	char *string;

	i = 0;
	j = 0;
	while (str[i] != '\0' && !check_sep)
	{	
		i++;
	}
	string = (char *)malloc(sizeof(char) * i);
	while (j < i)
	{
		string[j] = str[j];
		j++;
	}
	return (string);
}

int	check_sep(char c, char *charset)
{
	int	i;

	while (charset[i] != '\0')
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	count_words(char *str, char *charset)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		while (str[i] != '\0' && check_sep(str[i], charset))
			i++;
		if (str[i] != '\0')
			count++;
		while (str[i] != '\0' && !check_sep(str[i], charset))
			i++;
	}
	return (count);
}

char **ft_split(char *str, char *charset)
{
	int	i;
	char **arr;

	i = 0;
	arr = (char **)malloc(sizeof(char *) * count_words(str, charset));
	while (*str != '\0')
	{
		while (str != '\0' && check_sep(*str, charset)
			str++;
		if (*str != '\0')
		{
			arr[i] = sep_word(str, charset);
			i++;
		}
		while (str != '\0'&& !check_sep(*str, charset)
			str++;
	}
	arr[i] = 0;
	return (arr);
}

