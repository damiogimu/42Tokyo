/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmogi <dmogi@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 22:21:05 by dmogi             #+#    #+#             */
/*   Updated: 2020/11/23 15:27:24 by dmogi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s1, int c, size_t n)
{
	size_t			i;
	unsigned char	*p_s1;
	unsigned char	ch_c;

	i = 0;
	p_s1 = (unsigned char *)s1;
	ch_c = (unsigned char)c;
	while (i < n)
	{
		if (p_s1[i] == ch_c)
			return (&p_s1[i]);
		i++;
	}
	return (NULL);
}
