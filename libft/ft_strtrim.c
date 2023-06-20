/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmogi <dmogi@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 20:17:45 by dmogi             #+#    #+#             */
/*   Updated: 2021/04/16 12:49:05 by dmogi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_match(char c, const char *set)
{
	int		i;

	i = 0;
	if (set == NULL)
		return (0);
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		start;
	int		end;
	char	*new;

	if (s1 == NULL)
		return (NULL);
	start = 0;
	end = ft_strlen(s1) - 1;
	while (is_match(s1[start], set) == 1)
		start++;
	while (is_match(s1[end], set) == 1)
		end--;
	if (start > end)
		return (ft_calloc(1, sizeof(char)));
	new = (char *)malloc(sizeof(char) * (end - start + 2));
	if (new == NULL)
		return (NULL);
	i = -1;
	while (++i < end - start + 1)
		new[i] = s1[start + i];
	new[i] = '\0';
	return (new);
}
