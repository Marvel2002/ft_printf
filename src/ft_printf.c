/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 18:05:13 by mmatime           #+#    #+#             */
/*   Updated: 2018/01/02 18:13:23 by mmatime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_sub_third(const char *format, t_env *a)
{
	while (a->flags.width > 1 && !a->flags.minus)
	{
		a->dest = ft_strjoin_char(a->dest, a->space, a);
		a->flags.width--;
	}
	a->dest = ft_strjoin_char(a->dest, format[a->i], a);
	while (a->flags.width > 1 && a->flags.minus)
	{
		a->dest = ft_strjoin_char(a->dest, a->space, a);
		a->flags.width--;
	}
}

void	ft_sub_first(const char *format, t_env *a)
{
	if (format[a->i] == 'S' || (format[a->i] == 's' && a->length.l))
		ft_wint_t(a);
	else if (format[a->i] == 's')
		ft_string_full(a);
	else if (format[a->i] == '%')
		ft_purcent(a);
	else if (format[a->i] == 'd' || format[a->i] == 'i' || format[a->i] == 'D')
	{
		if (format[a->i] == 'D')
			a->capital_d++;
		ft_decimal_full(a);
	}
	else if (format[a->i] == 'x')
		ft_hexa_min_full(a);
	else if (format[a->i] == 'X')
		ft_hexa_maj_full(a);
	else if (format[a->i] == 'u' || format[a->i] == 'U')
	{
		if (format[a->i] == 'U')
			a->capital_u++;
		ft_unsigned_full(a);
	}
	else
		ft_sub_second(format, a);
}

void	ft_sub_second(const char *format, t_env *a)
{
	if (format[a->i] == 'o' || format[a->i] == 'O')
	{
		if (format[a->i] == 'O')
			a->capital_o++;
		ft_octal_full(a);
	}
	else if (format[a->i] == 'C' || (format[a->i] == 'c' && a->length.l))
		ft_wchar_t(a);
	else if (format[a->i] == 'c')
		ft_char(a);
	else if (format[a->i] == 'p')
		ft_ptr(a);
	else if (format[a->i] == '\0')
	{
		a->i--;
		return ;
	}
	else
		ft_sub_third(format, a);
}

void	ft_loop(const char *format, t_env *a)
{
	while (format[a->i])
	{
		if (format[a->i] == '%')
		{
			a->i++;
			ft_init(a);
			ft_flags(format, a);
			a->flags.width = ft_width(format, a);
			if (format[a->i] == '.')
			{
				a->i++;
				a->flags.trigger_prec = 1;
				a->flags.prec = ft_precision(format, a);
			}
			ft_length(format, a);
			ft_sub_first(format, a);
		}
		else
			a->dest = ft_strjoin_char(a->dest, format[a->i], a);
		a->i++;
	}
}

int		ft_printf(const char *format, ...)
{
	t_env *a;

	a = (t_env *)ft_memalloc(sizeof(*a));
	if (!a)
		return (0);
	ft_init(a);
	a->i = 0;
	a->ret = 0;
	a->flags.count_space = 0;
	a->count2 = 0;
	a->dest = NULL;
	va_start(a->ap, format);
	ft_loop(format, a);
	ft_display(a);
	return (a->ret);
}
