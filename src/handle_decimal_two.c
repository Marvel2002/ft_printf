/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_decimal_two.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/30 13:52:57 by mmatime           #+#    #+#             */
/*   Updated: 2017/12/30 13:53:06 by mmatime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_decimal_first(char *str, t_env *a)
{
	if (a->flags.plus && a->numb)
		a->dest = ft_strjoin_char(a->dest, '+', a);
	if (a->flags.prec && a->numb < 0)
		a->dest = ft_strjoin_char(a->dest, '-', a);
	while (a->flags.prec >
			ft_strlen(ft_itoa_minus(a->numb, a->flags.minus)))
	{
		a->dest = ft_strjoin_char(a->dest, '0', a);
		a->flags.prec--;
	}
	if (a->flags.prec && a->numb < 0)
	{
		a->dest = ft_strjoin_char(a->dest, '0', a);
		a->dest = ft_strjoin(a->dest, ft_itoa_plus(a->numb, a->flags.minus));
	}
	else
		a->dest = ft_strjoin(a->dest, str);
}

void	ft_decimal_four(char *str, t_env *a)
{
	if (a->flags.plus)
		a->dest = ft_strjoin_char(a->dest, '+', a);
	while (a->flags.width > ft_strlen(str))
	{
		a->dest = ft_strjoin_char(a->dest, '0', a);
		a->flags.width--;
	}
	a->dest = ft_strjoin_precision(a->dest, str, a->flags.prec);
}
