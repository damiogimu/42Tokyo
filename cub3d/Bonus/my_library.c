#include "cub3d.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_strcmp(char *str1, char *str2)
{
	int	i;

	i = 0;
	while (str1[i] != '\0' || str2[i] != '\0')
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}

int	ft_chrstr(char c, char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (c == str[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_strstr(char *str1, char *str2)
{
	int i;

	i = 0;
	while (str1[i] != '\0')
	{
		if (str1[i] == str2[0])
		{
			if (ft_strcmp(&str1[i], str2) == 0)
				return (1);
		}
		i++;
	}
	return (0);
}
