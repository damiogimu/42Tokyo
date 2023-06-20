/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmogi <dmogi@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 20:55:27 by dmogi             #+#    #+#             */
/*   Updated: 2021/04/16 03:33:17 by dmogi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	is_negative(long *l_n, char *num)
{
	if (*l_n < 0)
	{
		*l_n *= -1;
		num[0] = '-';
		return (1);
	}
	return (0);
}

static	int	count_digit(int n)
{
	int	i;
	int	count;

	i = 1;
	count = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		count++;
	while (n != 0)
	{
		count++;
		n /= 10;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	long	l_n;
	int		i;
	int		j;
	int		a;
	char	*num;

	l_n = n;
	(num = (char *)malloc(sizeof(char) * (count_digit(n) + 1)));
	if (num == NULL)
		return (NULL);
	i = 1;
	j = is_negative(&l_n, num);
	while (l_n / i >= 10)
		i *= 10;
	while (j < count_digit(n))
	{
		a = l_n / i;
		num[j] = a + '0';
		l_n -= a * i;
		i /= 10;
		j++;
	}
	num[j] = '\0';
	return (num);
}
