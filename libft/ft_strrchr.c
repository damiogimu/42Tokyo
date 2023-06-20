/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmogi <dmogi@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 15:27:08 by dmogi             #+#    #+#             */
/*   Updated: 2020/11/23 16:37:19 by dmogi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t			i;
	const char		*tmp_p;
	unsigned char	ch_c;

	i = 0;
	ch_c = c;
	tmp_p = s;
	while (i < (ft_strlen(s) + 1))
	{
		if (s[i] == ch_c)
			tmp_p = &s[i];
		i++;
	}
	if (*tmp_p == ch_c)
		return ((char *)tmp_p);
	return (NULL);
}
