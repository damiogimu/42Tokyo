/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_funcs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmogi <dmogi@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 13:48:58 by dmogi             #+#    #+#             */
/*   Updated: 2021/02/22 21:42:37 by dmogi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		judge_output_func(t_mdfr *mdfrs, va_list *ap)
{
	if ((*mdfrs).specifier == '%')
		return (ft_prnt_char(mdfrs, ap));
	else if ((*mdfrs).specifier == 'c')
		return (ft_prnt_char(mdfrs, ap));
	else if ((*mdfrs).specifier == 's')
		return (ft_prnt_str(mdfrs, ap));
	else if ((*mdfrs).specifier == 'p')
		return (ft_prnt_adrs(mdfrs, ap));
	else if ((*mdfrs).specifier == 'd' || (*mdfrs).specifier == 'i')
		return (ft_prnt_int_num(mdfrs, ap));
	else if ((*mdfrs).specifier == 'u')
		return (ft_prnt_unsigned_num(mdfrs, ap));
	else if ((*mdfrs).specifier == 'x' || (*mdfrs).specifier == 'X')
		return (ft_prnt_hexdeci_num(mdfrs, ap));
	return (0);
}

int		ft_prnt_char(t_mdfr *mdfrs, va_list *ap)
{
	char	c;
	int		prnt_size;

	prnt_size = (*mdfrs).field > 1 ? (*mdfrs).field : 1;
	if ((*mdfrs).specifier == 'c')
		c = (char)va_arg(*ap, int);
	else
		c = '%';
	if ((*mdfrs).flag[0] == 0 && (*mdfrs).flag[1] == 0)
		ft_putchar_n(' ', (*mdfrs).field - 1);
	if ((*mdfrs).flag[0] == 1)
		ft_putchar_n('0', (*mdfrs).field - 1);
	write(1, &c, 1);
	if ((*mdfrs).flag[1] == 1)
		ft_putchar_n(' ', (*mdfrs).field - 1);
	return (prnt_size);
}

int		ft_prnt_str(t_mdfr *mdfrs, va_list *ap)
{
	char	*str;
	int		s_size;
	int		prnt_size;

	str = va_arg(*ap, char*);
	if (str == NULL)
		str = "(null)";
	s_size = ft_strlen(str);
	if ((*mdfrs).prec == -1)
		(*mdfrs).prec = s_size;
	prnt_size = (s_size <= (*mdfrs).prec) ? s_size : (*mdfrs).prec;
	if ((*mdfrs).flag[0] == 0 && (*mdfrs).flag[1] == 0)
		ft_putchar_n(' ', (*mdfrs).field - prnt_size);
	if ((*mdfrs).flag[0] == 1)
		ft_putchar_n('0', (*mdfrs).field - prnt_size);
	write(1, str, prnt_size);
	if ((*mdfrs).flag[1] == 1)
		ft_putchar_n(' ', (*mdfrs).field - prnt_size);
	return ((*mdfrs).field > prnt_size ? (*mdfrs).field : prnt_size);
}

int		ft_prnt_adrs(t_mdfr *mdfrs, va_list *ap)
{
	uintptr_t	p_num;
	int			n_size;
	int			prnt_size;

	p_num = (uintptr_t)va_arg(*ap, void*);
	n_size = (p_num == 0 && (*mdfrs).prec == 0) ? 0 : count_hexdeci(p_num);
	prnt_size = ((*mdfrs).prec > n_size ? (*mdfrs).prec : n_size);
	if ((*mdfrs).flag[0] == 0 && (*mdfrs).flag[1] == 0)
		ft_putchar_n(' ', (*mdfrs).field - prnt_size - 2);
	write(1, "0x", 2);
	if ((*mdfrs).flag[0] == 1)
		ft_putchar_n('0', (*mdfrs).field - prnt_size - 2);
	ft_putchar_n('0', prnt_size - n_size);
	if (p_num != 0 || (*mdfrs).prec != 0)
		ft_putnbr_base("0123456789abcdef", p_num);
	if ((*mdfrs).flag[1] == 1)
		ft_putchar_n(' ', (*mdfrs).field - prnt_size - 2);
	return (((*mdfrs).field > prnt_size + 2 ? (*mdfrs).field : prnt_size + 2));
}

int		ft_prnt_int_num(t_mdfr *mdfrs, va_list *ap)
{
	int num;
	int n_size;
	int prnt_size;
	int minus_f;

	num = va_arg(*ap, int);
	n_size = (num == 0 && (*mdfrs).prec == 0) ? 0 : count_digit(num);
	prnt_size = ((*mdfrs).prec > n_size ? (*mdfrs).prec : n_size);
	minus_f = (num < 0 ? 1 : 0);
	if ((*mdfrs).prec != -1)
		(*mdfrs).flag[0] = 0;
	if ((*mdfrs).flag[0] == 0 && (*mdfrs).flag[1] == 0)
		ft_putchar_n(' ', (*mdfrs).field - prnt_size - minus_f);
	if (minus_f == 1)
		write(1, "-", 1);
	if ((*mdfrs).flag[0] == 1)
		ft_putchar_n('0', (*mdfrs).field - prnt_size - minus_f);
	ft_putchar_n('0', prnt_size - n_size);
	if ((*mdfrs).prec != 0 || num != 0)
		ft_putnbr(num);
	if ((*mdfrs).flag[1] == 1)
		ft_putchar_n(' ', (*mdfrs).field - prnt_size - minus_f);
	return ((*mdfrs).field > prnt_size ? (*mdfrs).field : prnt_size + minus_f);
}
