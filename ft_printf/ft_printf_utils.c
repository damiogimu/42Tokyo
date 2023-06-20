/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmogi <dmogi@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 13:41:05 by dmogi             #+#    #+#             */
/*   Updated: 2021/02/23 12:30:43 by dmogi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_strlen(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int		count_digit(long long num)
{
	int i;
	int num_size;

	i = 1;
	num_size = 1;
	if (num < 0)
		num *= -1;
	while (num / i >= 10)
		i *= 10;
	while (i >= 10)
	{
		num -= (num / i) * i;
		i /= 10;
		num_size++;
	}
	return (num_size);
}

void	ft_putchar_n(char c, int n)
{
	int i;

	i = 0;
	while (i++ < n)
		write(1, &c, 1);
}

void	ft_putnbr_base(char *s, unsigned long long num)
{
	int		i;
	int		remainder;
	char	hexdeci_num[16];

	i = 0;
	if (num == 0)
		write(1, "0", 1);
	while (num > 0)
	{
		remainder = num % 16;
		hexdeci_num[i] = s[remainder];
		num /= 16;
		i++;
	}
	while (--i >= 0)
		write(1, &hexdeci_num[i], 1);
}

int		count_hexdeci(unsigned long long num)
{
	int		output_c;

	output_c = 1;
	while (num >= 16)
	{
		num /= 16;
		output_c++;
	}
	return (output_c);
}
