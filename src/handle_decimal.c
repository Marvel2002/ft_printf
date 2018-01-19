/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_decimal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 16:07:10 by mmatime           #+#    #+#             */
/*   Updated: 2017/12/30 13:58:15 by mmatime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_strong_decimal(char *str, t_env *a)
{
	if (a->numb >= 0)
	{
		if (a->flags.trigger_prec && !a->numb && !a->flags.prec)
			a->dest = ft_strjoin_char(a->dest, ' ', a);
		else
			a->dest = ft_strjoin(a->dest, str);
	}
	else if (a->flags.plus)
		a->dest = ft_strjoin(a->dest, ft_itoa_minus(a->numb, a->flags.plus));
	else
		a->dest = ft_strjoin(a->dest, ft_itoa_plus(a->numb, a->flags.plus));
}

void	ft_decimal_second(char *str, t_env *a)
{
	if (a->flags.plus && a->flags.width && a->numb >= 0)
		a->flags.width--;
	if (a->flags.plus && a->numb >= 0)
		a->dest = ft_strjoin_char(a->dest, '+', a);
	if (a->flags.zero && a->numb < 0)
		a->dest = ft_strjoin_char(a->dest, '-', a);
	while (a->flags.width > ft_strlen(str) && !a->flags.minus)
	{
		a->dest = ft_strjoin_char(a->dest, a->space, a);
		a->flags.width--;
	}
	if (!a->flags.zero && !a->flags.plus && a->numb < 0)
		a->dest = ft_strjoin_char(a->dest, '-', a);
	ft_strong_decimal(str, a);
	while (a->flags.width > ft_strlen(str) && a->flags.minus)
	{
		a->dest = ft_strjoin_char(a->dest, a->space, a);
		a->flags.width--;
	}
}

void	fill_width(t_env *a)
{
	while (a->flags.width > a->flags.prec && !a->flags.minus)
	{
		if (a->flags.zero)
			a->dest = ft_strjoin_char(a->dest, ' ', a);
		else
			a->dest = ft_strjoin_char(a->dest, a->space, a);
		a->flags.width--;
	}
}

void	ft_decimal_third(char *str, t_env *a)
{
	a->flags.tmp = a->flags.prec;
	if ((a->flags.plus && a->flags.width) || a->numb < 0)
		a->flags.width--;
	fill_width(a);
	if (a->flags.plus && a->numb >= 0)
		a->dest = ft_strjoin_char(a->dest, '+', a);
	if (a->numb < 0)
		a->dest = ft_strjoin_char(a->dest, '-', a);
	while (a->flags.prec > ft_strlen(str))
	{
		a->dest = ft_strjoin_char(a->dest, '0', a);
		a->flags.prec--;
	}
	if (a->numb >= 0)
		a->dest = ft_strjoin(a->dest, str);
	else
	{
		a->dest = ft_strjoin_char(a->dest, '0', a);
		a->dest = ft_strjoin(a->dest, ft_itoa_minus(a->numb, 1));
	}
	while (a->flags.width > a->flags.tmp && a->flags.minus)
	{
		a->dest = ft_strjoin_char(a->dest, a->space, a);
		a->flags.width--;
	}
}

void	ft_decimal_full(t_env *a)
{
	char *str;

	length_decimal(a);
	ft_flags_decimal(a);
	str = ft_itoa_max(a->numb);
	if (a->flags.trigger_prec && !a->flags.prec && !a->flags.width && !a->numb)
		return ;
	if (a->flags.width < a->flags.prec && ft_strlen(str) > a->flags.prec)
		a->dest = ft_strjoin(a->dest, str);
	else if (a->flags.width < a->flags.prec && ft_strlen(str) < a->flags.prec)
		ft_decimal_first(str, a);
	else if (a->flags.width > a->flags.prec && ft_strlen(str) >= a->flags.prec)
		ft_decimal_second(str, a);
	else if (a->flags.width > a->flags.prec && ft_strlen(str) < a->flags.prec)
		ft_decimal_third(str, a);
	else if (a->flags.width == a->flags.prec && ft_strlen(str) > a->flags.width)
		a->dest = ft_strjoin(a->dest, str);
	else if (a->flags.width == a->flags.prec && ft_strlen(str) < a->flags.width)
		ft_decimal_four(str, a);
	else
		a->dest = ft_strjoin(a->dest, str);
	free(str);
}
