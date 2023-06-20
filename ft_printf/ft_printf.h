/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmogi <dmogi@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 18:38:07 by dmogi             #+#    #+#             */
/*   Updated: 2021/02/22 21:46:57 by dmogi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>
# include <limits.h>

typedef struct	s_mdfr
{
	int			flag[2];
	int			field;
	int			prec;
	char		specifier;
}				t_mdfr;

int				ft_strlen(char *s);
int				count_digit(long long num);
void			ft_putnbr(long long num);
void			ft_putnbr_base(char *s, unsigned long long num);
void			ft_putchar_n(char c, int n);
int				count_hexdeci(unsigned long long num);
int				ft_prnt_char(t_mdfr *mdfrs, va_list *ap);
int				ft_prnt_str(t_mdfr *mdfrs, va_list *ap);
int				ft_prnt_adrs(t_mdfr *mdfrs, va_list *ap);
int				ft_prnt_int_num(t_mdfr *mdfrs, va_list *ap);
int				ft_prnt_unsigned_num(t_mdfr *mdfrs, va_list *ap);
int				ft_prnt_hexdeci_num(t_mdfr *mdfrs, va_list *ap);
int				judge_output_func(t_mdfr *mdfrs, va_list *ap);
void			init_modifiers(t_mdfr *modifiers);
int				check_frmt(const char **frmt, va_list *ap);
void			check_flag(const char **frmt, t_mdfr *modifiers);
int				check_specifier(const char *s, const char **frmt, \
				t_mdfr *mdfrs);
int				check_num(const char **frmt, t_mdfr *mdfrs, va_list *ap, \
				int fflag);
int				ft_printf(const char *frmt, ...);

#endif
