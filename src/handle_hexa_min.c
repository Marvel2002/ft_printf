/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hexa_min.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 16:14:35 by mmatime           #+#    #+#             */
/*   Updated: 2017/12/26 20:58:54 by mmatime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_hexa_min_one(char *str, t_env *a)
{
	if (a->flags.diese == 1 && a->uns_number)
		a->flags.width -= 2;
	if (a->flags.diese == 1 && a->uns_number)
		a->dest = ft_strjoin(a->dest, "0x");
	while (a->flags.prec > ft_strlen(str))
	{
		a->dest = ft_strjoin_char(a->dest, '0', a);
		a->flags.prec--;
	}
	a->dest = ft_strjoin(a->dest, str);
}

void	ft_hexa_min_two(char *str, t_env *a)
{
	if (a->flags.diese == 1 && a->uns_number)
		a->flags.width -= 2;
	if (a->flags.diese == 1 && a->uns_number && a->flags.zero == 1)
		a->dest = ft_strjoin(a->dest, "0x");
	while (a->flags.width > ft_strlen(str) && !a->flags.minus)
	{
		a->dest = ft_strjoin_char(a->dest, a->space, a);
		a->flags.width--;
	}
	if (a->flags.diese == 1 && a->uns_number && !a->flags.zero)
		a->dest = ft_strjoin(a->dest, "0x");
	a->dest = ft_strjoin(a->dest, str);
	while (a->flags.width > ft_strlen(str) && a->flags.minus)
	{
		a->dest = ft_strjoin_char(a->dest, a->space, a);
		a->flags.width--;
	}
}

void	ft_hexa_min_three(char *str, t_env *a)
{
	a->flags.tmp = a->flags.prec;
	if (a->flags.diese == 1 && a->uns_number)
		a->flags.width -= 2;
	if (a->flags.diese == 1 && a->uns_number)
		a->dest = ft_strjoin(a->dest, "0x");
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

void	ft_hexa_min_four(char *str, t_env *a)
{
	if (a->flags.diese == 1 && a->uns_number)
		a->flags.width -= 2;
	if (a->flags.diese == 1 && a->uns_number)
		a->dest = ft_strjoin(a->dest, "0x");
	while (a->flags.width > ft_strlen(str))
	{
		a->dest = ft_strjoin_char(a->dest, '0', a);
		a->flags.width--;
	}
	a->dest = ft_strjoin_precision(a->dest, str, a->flags.prec);
}

void	ft_hexa_min_full(t_env *a)
{
	char *str;

	length_all(a);
	str = ft_hexa_min(a->uns_number, a);
	if (a->flags.width < a->flags.prec && ft_strlen(str) > a->flags.prec)
		a->dest = ft_strjoin(a->dest, str);
	else if (a->flags.width < a->flags.prec && ft_strlen(str) < a->flags.prec)
		ft_hexa_min_one(str, a);
	else if (a->flags.width > a->flags.prec && ft_strlen(str) >= a->flags.prec)
		ft_hexa_min_two(str, a);
	else if (a->flags.width > a->flags.prec && ft_strlen(str) < a->flags.prec)
		ft_hexa_min_three(str, a);
	else if (a->flags.width == a->flags.prec && ft_strlen(str) > a->flags.width)
	{
		if (a->flags.diese == 1 && a->uns_number)
			a->dest = ft_strjoin(a->dest, "0x");
		a->dest = ft_strjoin(a->dest, str);
	}
	else if (a->flags.width == a->flags.prec && ft_strlen(str) < a->flags.width)
		ft_hexa_min_four(str, a);
	else
		a->dest = ft_strjoin(a->dest, str);
	free(str);
}
