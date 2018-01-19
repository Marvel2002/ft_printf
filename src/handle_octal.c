/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_octal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 16:15:03 by mmatime           #+#    #+#             */
/*   Updated: 2017/12/30 16:02:20 by mmatime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_octal_one(char *str, t_env *a)
{
	if (a->flags.diese == 1 && a->uns_number)
		a->flags.width--;
	if (a->flags.diese == 1 && a->uns_number)
	{
		a->dest = ft_strjoin_char(a->dest, '0', a);
		a->flags.prec--;
	}
	while (a->flags.prec > ft_strlen(str))
	{
		a->dest = ft_strjoin_char(a->dest, '0', a);
		a->flags.prec--;
	}
	a->dest = ft_strjoin(a->dest, str);
}

void	ft_octal_three(char *str, t_env *a)
{
	a->flags.tmp = a->flags.prec;
	if (a->flags.diese == 1 && a->uns_number)
		a->flags.width--;
	if (a->flags.diese == 1 && a->uns_number)
		a->dest = ft_strjoin_char(a->dest, '0', a);
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

void	ft_octal_two(char *str, t_env *a)
{
	if (a->flags.diese == 1 && a->uns_number)
		a->flags.width--;
	while (a->flags.width > ft_strlen(str) && !a->flags.minus)
	{
		a->dest = ft_strjoin_char(a->dest, a->space, a);
		a->flags.width--;
	}
	if (a->flags.diese == 1 && a->uns_number)
		a->dest = ft_strjoin_char(a->dest, '0', a);
	if (a->uns_number)
		a->dest = ft_strjoin(a->dest, str);
	else
		a->dest = ft_strjoin_char(a->dest, ' ', a);
	while (a->flags.width > ft_strlen(str) && a->flags.minus)
	{
		a->dest = ft_strjoin_char(a->dest, a->space, a);
		a->flags.width--;
	}
}

void	ft_octal_four(char *str, t_env *a)
{
	if (a->flags.diese == 1 && a->uns_number)
		a->flags.width--;
	if (a->flags.diese == 1 && a->uns_number)
		a->dest = ft_strjoin_char(a->dest, '0', a);
	while (a->flags.width > ft_strlen(str))
	{
		a->dest = ft_strjoin_char(a->dest, '0', a);
		a->flags.width--;
	}
	a->dest = ft_strjoin_precision(a->dest, str, a->flags.prec);
}

void	ft_octal_full(t_env *a)
{
	char *str;

	length_all(a);
	str = ft_int_to_oct(a->uns_number);
	if (a->flags.trigger_prec && !a->flags.prec && !a->uns_number &&
			!a->flags.width && !a->flags.diese)
		return ;
	if (a->flags.width < a->flags.prec && ft_strlen(str) > a->flags.prec)
		a->dest = ft_strjoin(a->dest, str);
	else if (a->flags.width < a->flags.prec && ft_strlen(str) < a->flags.prec)
		ft_octal_one(str, a);
	else if (a->flags.width > a->flags.prec && ft_strlen(str) >= a->flags.prec)
		ft_octal_two(str, a);
	else if (a->flags.width > a->flags.prec && ft_strlen(str) < a->flags.prec)
		ft_octal_three(str, a);
	else if (a->flags.width == a->flags.prec && ft_strlen(str) > a->flags.width)
		ft_add_zero_octal(str, a);
	else if (a->flags.width == a->flags.prec && ft_strlen(str) < a->flags.width)
		ft_octal_four(str, a);
	else
		a->dest = ft_strjoin(a->dest, str);
	free(str);
}
