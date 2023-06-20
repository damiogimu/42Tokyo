/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmogi <dmogi@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 22:53:28 by dmogi             #+#    #+#             */
/*   Updated: 2020/11/23 15:45:01 by dmogi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*p;
	unsigned char	ch_c;

	i = 0;
	p = (unsigned char *)s;
	ch_c = (unsigned char)c;
	while (i < n)
	{
		p[i] = ch_c;
		i++;
	}
	return (s);
}
