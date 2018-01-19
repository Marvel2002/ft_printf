/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 16:12:27 by mmatime           #+#    #+#             */
/*   Updated: 2018/01/02 11:33:20 by mmatime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_flags_decimal(t_env *a)
{
	if (a->flags.space && a->numb >= 0)
	{
		a->dest = ft_strjoin_char(a->dest, ' ', a);
		if (a->flags.width > 0)
			a->flags.width--;
	}
	if (a->flags.plus && a->numb >= 0 && !a->flags.width)
		a->dest = ft_strjoin_char(a->dest, '+', a);
}

void		space_only(const char *format, t_env *a)
{
	if (a->flags.plus == 0)
	{
		a->flags.space = 1;
		a->flags.count_space++;
		a->i++;
		ft_flags(format, a);
	}
	else
	{
		a->i++;
		ft_flags(format, a);
	}
}

void		ft_minus(const char *format, t_env *a)
{
	a->flags.minus = 1;
	a->space = ' ';
	a->i++;
	ft_flags(format, a);
}

void		ft_flags(const char *format, t_env *a)
{
	if (format[a->i] == '-')
		ft_minus(format, a);
	if (format[a->i] == '+')
	{
		a->flags.plus = 1;
		a->flags.space = 0;
		a->i++;
		ft_flags(format, a);
	}
	if (format[a->i] == '0' && a->flags.minus == 0)
	{
		a->space = '0';
		a->flags.zero = 1;
		a->i++;
		ft_flags(format, a);
	}
	if (format[a->i] == ' ')
		space_only(format, a);
	if (format[a->i] == '#')
	{
		a->flags.diese = 1;
		a->i++;
		ft_flags(format, a);
	}
}
