/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_frmt_funcs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmogi <dmogi@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 13:34:30 by dmogi             #+#    #+#             */
/*   Updated: 2021/02/22 20:59:16 by dmogi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_modifiers(t_mdfr *modifiers)
{
	(*modifiers).flag[0] = 0;
	(*modifiers).flag[1] = 0;
	(*modifiers).field = 0;
	(*modifiers).prec = -1;
	(*modifiers).specifier = '\0';
}

void	check_flag(const char **frmt, t_mdfr *mdfrs)
{
	while (**frmt)
	{
		if (**frmt == '0')
			(*mdfrs).flag[0] = 1;
		else if (**frmt == '-')
			(*mdfrs).flag[1] = 1;
		else
			break ;
		(*frmt)++;
	}
}

int		check_num(const char **frmt, t_mdfr *mdfrs, va_list *ap, int fflag)
{
	ssize_t num;

	num = 0;
	if (**frmt == '*')
	{
		num = va_arg(*ap, int);
		if (num < 0 && fflag == 1)
		{
			num *= -1;
			(*mdfrs).flag[1] = 1;
		}
		else if (num < 0)
			num = -1;
		(*frmt)++;
	}
	else
		while ('0' <= **frmt && **frmt <= '9')
		{
			num *= 10;
			num += (**frmt) - '0';
			(*frmt)++;
		}
	if (INT_MAX <= num)
		num = -2;
	return ((int)num);
}

int		check_specifier(const char *s, const char **frmt, t_mdfr *mdfrs)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == **frmt)
		{
			(*mdfrs).specifier = **frmt;
			(*frmt)++;
			return (1);
		}
		i++;
	}
	return (0);
}

int		check_frmt(const char **frmt, va_list *ap)
{
	t_mdfr	modifiers;

	(*frmt)++;
	init_modifiers(&modifiers);
	check_flag(frmt, &modifiers);
	if ((modifiers.field = check_num(frmt, &modifiers, ap, 1)) == -2)
		return (-1);
	if ((**frmt) == '.')
	{
		(*frmt)++;
		if ((modifiers.prec = check_num(frmt, &modifiers, ap, 0)) == -2)
			return (-1);
	}
	check_specifier("cspdiuxX%", frmt, &modifiers);
	if (modifiers.flag[0] == 1 && modifiers.flag[1] == 1)
		modifiers.flag[0] = 0;
	return (judge_output_func(&modifiers, ap));
}
