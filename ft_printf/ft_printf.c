/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmogi <dmogi@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 18:37:48 by dmogi             #+#    #+#             */
/*   Updated: 2022/06/19 14:37:02 by dmogi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(long long num)
{
	long long	i;
	char		ch_num;

	i = 1;
	if (num < 0)
		num *= -1;
	while (num / i >= 10)
		i *= 10;
	while (i > 0)
	{
		ch_num = (num / i) + '0';
		write(1, &ch_num, 1);
		num -= (num / i) * i;
		i /= 10;
	}
}

int		ft_printf(const char *frmt, ...)
{
	va_list ap;
	int		result;
	int		output_c;

	output_c = 0;
	va_start(ap, frmt);
	while (*frmt)
	{
		if (*frmt == '%')
		{
			if ((result = check_frmt(&frmt, &ap)) == -1)
				return (-1);
			output_c += result;
		}
		else
		{
			write(1, frmt, 1);
			output_c++;
			frmt++;
		}
	}
	va_end(ap);
	return (output_c);
}
