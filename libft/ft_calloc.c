/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmogi <dmogi@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 23:03:11 by dmogi             #+#    #+#             */
/*   Updated: 2021/04/16 03:31:43 by dmogi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n, size_t size)
{
	size_t	i;
	void	*p;

	i = 0;
	p = malloc(size * n);
	if (p == NULL)
		return (NULL);
	ft_bzero(p, size * n);
	return (p);
}
