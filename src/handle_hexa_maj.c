/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hexa_maj.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 16:14:35 by mmatime           #+#    #+#             */
/*   Updated: 2017/12/26 21:12:50 by mmatime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_hexa_maj_one(char *str, t_env *a)
{
	if (a->flags.diese == 1 && a->uns_number)
		a->flags.width -= 2;
	if (a->flags.diese == 1 && a->uns_number)
		a->dest = ft_strjoin(a->dest, "0X");
	while (a->flags.prec > ft_strlen(str))
	{
		a->dest = ft_strjoin_char(a->dest, '0', a);
		a->flags.prec--;
	}
	a->dest = ft_strjoin(a->dest, str);
}

void	ft_hexa_maj_two(char *str, t_env *a)
{
	if (a->flags.diese == 1 && a->uns_number)
		a->flags.width -= 2;
	if (a->flags.diese == 1 && a->uns_number && a->flags.zero == 1)
		a->dest = ft_strjoin(a->dest, "0X");
	while (a->flags.width > ft_strlen(str) && !a->flags.minus)
	{
		a->dest = ft_strjoin_char(a->dest, a->space, a);
		a->flags.width--;
	}
	if (a->flags.diese == 1 && a->uns_number && !a->flags.zero)
		a->dest = ft_strjoin(a->dest, "0X");
	a->dest = ft_strjoin(a->dest, str);
	while (a->flags.width > ft_strlen(str) && a->flags.minus)
	{
		a->dest = ft_strjoin_char(a->dest, a->space, a);
		a->flags.width--;
	}
}

void	ft_hexa_maj_three(char *str, t_env *a)
{
	a->flags.tmp = a->flags.prec;
	if (a->flags.diese == 1 && a->uns_number)
		a->flags.width -= 2;
	if (a->flags.diese == 1 && a->uns_number)
		a->dest = ft_strjoin(a->dest, "0X");
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

void	ft_hexa_maj_four(char *str, t_env *a)
{
	if (a->flags.diese == 1 && a->uns_number)
		a->flags.width -= 2;
	if (a->flags.diese == 1 && a->uns_number)
		a->dest = ft_strjoin(a->dest, "0X");
	while (a->flags.width > ft_strlen(str))
	{
		a->dest = ft_strjoin_char(a->dest, '0', a);
		a->flags.width--;
	}
	a->dest = ft_strjoin_precision(a->dest, str, a->flags.prec);
}

void	ft_hexa_maj_full(t_env *a)
{
	char *str;

	length_all(a);
	str = ft_hexa_maj(a->uns_number, a);
	if (a->flags.width < a->flags.prec && ft_strlen(str) > a->flags.prec)
		a->dest = ft_strjoin(a->dest, str);
	else if (a->flags.width < a->flags.prec && ft_strlen(str) < a->flags.prec)
		ft_hexa_maj_one(str, a);
	else if (a->flags.width > a->flags.prec && ft_strlen(str) >= a->flags.prec)
		ft_hexa_maj_two(str, a);
	else if (a->flags.width > a->flags.prec && ft_strlen(str) < a->flags.prec)
		ft_hexa_maj_three(str, a);
	else if (a->flags.width == a->flags.prec && ft_strlen(str) > a->flags.width)
	{
		if (a->flags.diese == 1 && a->uns_number)
			a->dest = ft_strjoin(a->dest, "0X");
		a->dest = ft_strjoin(a->dest, str);
	}
	else if (a->flags.width == a->flags.prec && ft_strlen(str) < a->flags.width)
		ft_hexa_maj_four(str, a);
	else
		a->dest = ft_strjoin(a->dest, str);
	free(str);
}
