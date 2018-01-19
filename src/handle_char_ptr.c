/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_char_ptr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 16:10:41 by mmatime           #+#    #+#             */
/*   Updated: 2017/12/30 16:02:07 by mmatime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_ptr(t_env *a)
{
	char *str;

	a->p = va_arg(a->ap, void *);
	str = ft_hexa_min((unsigned long long int)a->p, a);
	if (a->flags.zero)
		a->dest = ft_strjoin(a->dest, "0x");
	while (a->flags.width > ft_strlen(str) + 2 && !a->flags.minus)
	{
		a->dest = ft_strjoin_char(a->dest, a->space, a);
		a->flags.width--;
	}
	if (!a->flags.zero)
		a->dest = ft_strjoin(a->dest, "0x");
	while (a->flags.prec > ft_strlen(str))
	{
		a->dest = ft_strjoin_char(a->dest, '0', a);
		a->flags.prec--;
	}
	a->dest = ft_strjoin(a->dest, str);
	while (a->flags.width > ft_strlen(str) + 2 && a->flags.minus)
	{
		a->dest = ft_strjoin_char(a->dest, a->space, a);
		a->flags.width--;
	}
	free(str);
}

void	ft_char(t_env *a)
{
	a->c = (unsigned char)va_arg(a->ap, int);
	while (a->flags.width > 1 && !a->flags.minus)
	{
		a->dest = ft_strjoin_char(a->dest, a->space, a);
		a->flags.width--;
	}
	if (a->c == 0)
	{
		a->trigger++;
		a->dest = ft_strjoin_zero(a->dest, '\0', a);
		a->count2++;
		return ;
	}
	a->dest = ft_strjoin_char(a->dest, a->c, a);
	while (a->flags.width > 1 && a->flags.minus)
	{
		a->dest = ft_strjoin_char(a->dest, a->space, a);
		a->flags.width--;
	}
}

void	ft_purcent(t_env *a)
{
	while (a->flags.width > 1 && !a->flags.minus)
	{
		a->dest = ft_strjoin_char(a->dest, a->space, a);
		a->flags.width--;
	}
	a->dest = ft_strjoin_char(a->dest, '%', a);
	while (a->flags.width > 1 && a->flags.minus)
	{
		a->dest = ft_strjoin_char(a->dest, a->space, a);
		a->flags.width--;
	}
}

void	ft_add_zero_octal(char *str, t_env *a)
{
	if (a->flags.diese && !a->flags.width && a->uns_number)
		a->dest = ft_strjoin_char(a->dest, '0', a);
	a->dest = ft_strjoin(a->dest, str);
}
