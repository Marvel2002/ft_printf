/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_length_sign.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 11:54:20 by mmatime           #+#    #+#             */
/*   Updated: 2018/01/02 11:55:03 by mmatime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		small_h(t_env *a)
{
	a->length.h = 1;
	a->i++;
}

void		small_l(t_env *a)
{
	a->length.l = 1;
	a->i++;
}

void		small_j(t_env *a)
{
	a->length.j = 1;
	a->i++;
}

void		ft_length(const char *format, t_env *a)
{
	if (format[a->i] == 'h' && format[a->i + 1] == 'h')
	{
		a->length.hh = 1;
		a->i += 2;
	}
	else if (format[a->i] == 'h')
		small_h(a);
	else if (format[a->i] == 'l' && format[a->i + 1] == 'l')
	{
		a->length.ll = 1;
		a->i += 2;
	}
	else if (format[a->i] == 'l')
		small_l(a);
	else if (format[a->i] == 'j')
		small_j(a);
	else if (format[a->i] == 'z')
	{
		a->length.z = 1;
		a->i++;
	}
	else
		return ;
}
