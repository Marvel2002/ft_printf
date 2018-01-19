/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_unsigned.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 16:16:53 by mmatime           #+#    #+#             */
/*   Updated: 2017/12/26 21:55:37 by mmatime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_unsigned_one(char *str, t_env *a)
{
	while (a->flags.prec > ft_strlen(str))
	{
		a->dest = ft_strjoin_char(a->dest, '0', a);
		a->flags.prec--;
	}
	a->dest = ft_strjoin(a->dest, str);
}

void	ft_unsigned_two(char *str, t_env *a)
{
	while (a->flags.width > ft_strlen(str) && !a->flags.minus)
	{
		a->dest = ft_strjoin_char(a->dest, a->space, a);
		a->flags.width--;
	}
	a->dest = ft_strjoin(a->dest, str);
	while (a->flags.width > ft_strlen(str) && a->flags.minus)
	{
		a->dest = ft_strjoin_char(a->dest, a->space, a);
		a->flags.width--;
	}
}

void	ft_unsigned_three(char *str, t_env *a)
{
	a->flags.tmp = a->flags.prec;
	while (a->flags.width > a->flags.prec && !a->flags.minus)
	{
		a->dest = ft_strjoin_char(a->dest, a->space, a);
		a->flags.width--;
	}
	while (a->flags.prec > ft_strlen(str))
	{
		a->dest = ft_strjoin_char(a->dest, '0', a);
		a->flags.prec--;
	}
	a->dest = ft_strjoin(a->dest, str);
	while (a->flags.width > a->flags.tmp && a->flags.minus)
	{
		a->dest = ft_strjoin_char(a->dest, a->space, a);
		a->flags.width--;
	}
}

void	ft_unsigned_four(char *str, t_env *a)
{
	while (a->flags.width > ft_strlen(str))
	{
		a->dest = ft_strjoin_char(a->dest, '0', a);
		a->flags.width--;
	}
	a->dest = ft_strjoin_precision(a->dest, str, a->flags.prec);
}

void	ft_unsigned_full(t_env *a)
{
	char *str;

	length_all(a);
	str = ft_itoa_umax(a->uns_number);
	if (a->flags.trigger_prec && a->flags.prec == 0 && a->uns_number == 0)
		return ;
	if (a->flags.width < a->flags.prec && ft_strlen(str) > a->flags.prec)
		a->dest = ft_strjoin(a->dest, str);
	else if (a->flags.width < a->flags.prec && ft_strlen(str) < a->flags.prec)
		ft_unsigned_one(str, a);
	else if (a->flags.width > a->flags.prec && ft_strlen(str) >= a->flags.prec)
		ft_unsigned_two(str, a);
	else if (a->flags.width > a->flags.prec && ft_strlen(str) < a->flags.prec)
		ft_unsigned_three(str, a);
	else if (a->flags.width == a->flags.prec && ft_strlen(str) > a->flags.width)
		a->dest = ft_strjoin(a->dest, str);
	else if (a->flags.width == a->flags.prec && ft_strlen(str) < a->flags.width)
		ft_unsigned_four(str, a);
	else
		a->dest = ft_strjoin(a->dest, str);
	free(str);
}
