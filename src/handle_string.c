/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 16:16:21 by mmatime           #+#    #+#             */
/*   Updated: 2017/12/30 16:16:08 by mmatime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_string_one(t_env *a)
{
	while (a->flags.width > ft_strlen(a->s))
	{
		a->dest = ft_strjoin_char(a->dest, a->space, a);
		a->flags.width--;
	}
	a->dest = ft_strjoin(a->dest, a->s);
}

void	ft_string_two(t_env *a)
{
	if (a->flags.trigger_prec)
	{
		while (a->flags.width > a->flags.prec && !a->flags.minus)
		{
			a->dest = ft_strjoin_char(a->dest, a->space, a);
			a->flags.width--;
		}
		a->dest = ft_strjoin_precision(a->dest, a->s, a->flags.prec);
		while (a->flags.width > a->flags.prec && a->flags.minus)
		{
			a->dest = ft_strjoin_char(a->dest, a->space, a);
			a->flags.width--;
		}
	}
	else
		ft_string_five(a);
}

void	ft_string_three(t_env *a)
{
	while (a->flags.width > ft_strlen(a->s) && !a->flags.minus)
	{
		a->dest = ft_strjoin_char(a->dest, a->space, a);
		a->flags.width--;
	}
	a->dest = ft_strjoin_precision(a->dest, a->s, a->flags.prec);
	while (a->flags.width > ft_strlen(a->s) && a->flags.minus)
	{
		a->dest = ft_strjoin_char(a->dest, a->space, a);
		a->flags.width--;
	}
}

void	ft_string_four(t_env *a)
{
	while (a->flags.width > ft_strlen(a->s))
	{
		a->dest = ft_strjoin_char(a->dest, a->space, a);
		a->flags.width--;
	}
	a->dest = ft_strjoin_precision(a->dest, a->s, a->flags.prec);
}

void	ft_string_full(t_env *a)
{
	a->s = va_arg(a->ap, char *);
	if (!a->s)
	{
		ft_string_void(a);
		return ;
	}
	if (a->flags.width < a->flags.prec && ft_strlen(a->s) > a->flags.prec)
		a->dest = ft_strjoin_precision(a->dest, a->s, a->flags.prec);
	else if (a->flags.width < a->flags.prec && ft_strlen(a->s) < a->flags.prec)
		ft_string_one(a);
	else if (a->flags.width > a->flags.prec && ft_strlen(a->s) >= a->flags.prec)
		ft_string_two(a);
	else if (a->flags.width > a->flags.prec && ft_strlen(a->s) < a->flags.prec)
		ft_string_three(a);
	else if (a->flags.width && a->flags.width == a->flags.prec &&
			ft_strlen(a->s) > a->flags.width)
		a->dest = ft_strjoin_precision(a->dest, a->s, a->flags.prec);
	else if (a->flags.width && a->flags.width == a->flags.prec &&
			ft_strlen(a->s) < a->flags.width)
		ft_string_four(a);
	else
		a->dest = ft_strjoin(a->dest, a->s);
}
