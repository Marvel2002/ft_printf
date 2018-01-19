/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_string_two.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/30 16:08:28 by mmatime           #+#    #+#             */
/*   Updated: 2018/01/02 11:55:34 by mmatime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_string_five(t_env *a)
{
	while (a->flags.width > ft_strlen(a->s) && !a->flags.minus)
	{
		a->dest = ft_strjoin_char(a->dest, a->space, a);
		a->flags.width--;
	}
	a->dest = ft_strjoin(a->dest, a->s);
	while (a->flags.width > ft_strlen(a->s) && a->flags.minus)
	{
		a->dest = ft_strjoin_char(a->dest, a->space, a);
		a->flags.width--;
	}
}

void	ft_string_void(t_env *a)
{
	char *str;

	str = ft_strdup("(null)");
	while (a->flags.width > a->flags.prec)
	{
		a->dest = ft_strjoin_char(a->dest, a->space, a);
		a->flags.width--;
	}
	if (a->flags.prec < ft_strlen(str) && a->flags.trigger_prec)
		a->dest = ft_strjoin_precision(a->dest, str, a->flags.prec);
	else
		a->dest = ft_strjoin(a->dest, str);
	free(str);
}
