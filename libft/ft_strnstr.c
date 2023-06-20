/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmogi <dmogi@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 22:42:07 by dmogi             #+#    #+#             */
/*   Updated: 2021/04/16 03:29:45 by dmogi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_match(const char *s, const char *find, size_t n)
{
	size_t	i;

	i = 0;
	while (find[i] != '\0')
	{
		if (s[i] != find[i] || i >= n)
			return (0);
		i++;
	}
	return (1);
}

char	*ft_strnstr(const char *s, const char *find, size_t n)
{
	size_t	i;
	char	*s_p;
	char	*find_p;

	i = 0;
	s_p = (char *)s;
	find_p = (char *)find;
	if (find_p[0] == '\0')
		return (s_p);
	if (n <= 0)
		return (NULL);
	while (s_p[i] != '\0' && i < n)
	{
		if (s_p[i] == find_p[0])
			if (is_match(&s_p[i], &find_p[0], n - i) == 1)
				return (&s_p[i]);
		i++;
	}
	return (NULL);
}
