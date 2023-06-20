/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmogi <dmogi@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 22:13:57 by dmogi             #+#    #+#             */
/*   Updated: 2020/11/23 15:39:39 by dmogi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*dest_p;
	unsigned char		*src_p;

	i = 0;
	dest_p = (unsigned char *)dest;
	src_p = (unsigned char *)src;
	if (dest_p > src_p)
	{
		while (i < n)
		{
			dest_p[(n - 1) - i] = src_p[(n - 1) - i];
			i++;
		}
	}
	else if (dest_p < src_p)
	{
		while (i < n)
		{
			dest_p[i] = src_p[i];
			i++;
		}
	}
	return (dest);
}
