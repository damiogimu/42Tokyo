/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_funcs2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmogi <dmogi@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 13:52:54 by dmogi             #+#    #+#             */
/*   Updated: 2021/02/22 19:09:31 by dmogi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_prnt_unsigned_num(t_mdfr *mdfrs, va_list *ap)
{
	unsigned int	num;
	int				n_size;
	int				prnt_size;

	num = (unsigned int)va_arg(*ap, int);
	n_size = (num == 0 && (*mdfrs).prec == 0) ? 0 : count_digit(num);
	prnt_size = ((*mdfrs).prec > n_size ? (*mdfrs).prec : n_size);
	if ((*mdfrs).prec != -1)
		(*mdfrs).flag[0] = 0;
	if ((*mdfrs).flag[0] == 0 && (*mdfrs).flag[1] == 0)
		ft_putchar_n(' ', (*mdfrs).field - prnt_size);
	if ((*mdfrs).flag[0] == 1)
		ft_putchar_n('0', (*mdfrs).field - prnt_size);
	ft_putchar_n('0', prnt_size - n_size);
	if ((*mdfrs).prec != 0 || num != 0)
		ft_putnbr(num);
	if ((*mdfrs).flag[1] == 1)
		ft_putchar_n(' ', (*mdfrs).field - prnt_size);
	return ((*mdfrs).field > prnt_size ? (*mdfrs).field : prnt_size);
}

int		ft_prnt_hexdeci_num(t_mdfr *mdfrs, va_list *ap)
{
	unsigned int	num;
	int				n_size;
	int				prnt_size;

	num = (unsigned int)va_arg(*ap, int);
	n_size = (num == 0 && (*mdfrs).prec == 0) ? 0 : count_hexdeci(num);
	prnt_size = ((*mdfrs).prec > n_size ? (*mdfrs).prec : n_size);
	if ((*mdfrs).prec != -1)
		(*mdfrs).flag[0] = 0;
	if ((*mdfrs).flag[0] == 0 && (*mdfrs).flag[1] == 0)
		ft_putchar_n(' ', (*mdfrs).field - prnt_size);
	if ((*mdfrs).flag[0] == 1)
		ft_putchar_n('0', (*mdfrs).field - prnt_size);
	ft_putchar_n('0', prnt_size - n_size);
	if ((*mdfrs).prec != 0 || num != 0)
	{
		if ((*mdfrs).specifier == 'x')
			ft_putnbr_base("0123456789abcdef", num);
		else
			ft_putnbr_base("0123456789ABCDEF", num);
	}
	if ((*mdfrs).flag[1] == 1)
		ft_putchar_n(' ', (*mdfrs).field - prnt_size);
	return ((*mdfrs).field > prnt_size ? (*mdfrs).field : prnt_size);
}
