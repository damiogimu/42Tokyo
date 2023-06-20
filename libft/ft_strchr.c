/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmogi <dmogi@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 23:09:21 by dmogi             #+#    #+#             */
/*   Updated: 2020/11/23 16:00:55 by dmogi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	ch_c;
	size_t	i;

	i = 0;
	ch_c = (char)c;
	while (i < (ft_strlen(s) + 1))
	{
		if (s[i] == ch_c)
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}
