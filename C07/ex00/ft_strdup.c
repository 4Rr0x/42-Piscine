#include <stdlib.h>


char	*ft_strdup(char *src)
{
	int		i;
	char	*strcp;

	i = 0;
	while (src[i])
	{
		i++;
	}
	strcp = (char *)malloc(sizeof(char) * (i + 1));
	if (!strcp)
		return (0);
	i = 0;
	while (src[i])
	{
		strcp[i] = src[i];
		i++;
	}
	strcp[i] = '\0';
	return (strcp);
}
