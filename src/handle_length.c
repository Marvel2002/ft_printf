/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_length.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 16:28:54 by mmatime           #+#    #+#             */
/*   Updated: 2017/12/30 14:32:14 by mmatime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	length_decimal(t_env *a)
{
	if (a->length.hh && !a->capital_d)
		a->numb = (signed char)va_arg(a->ap, int);
	else if (a->length.h && !a->capital_d)
		a->numb = (short int)va_arg(a->ap, int);
	else if (a->length.l || a->capital_d)
		a->numb = (long int)va_arg(a->ap, long int);
	else if (a->length.ll)
		a->numb = (long long int)va_arg(a->ap, long long int);
	else if (a->length.j)
		a->numb = va_arg(a->ap, intmax_t);
	else if (a->length.z)
		a->numb = (size_t)va_arg(a->ap, size_t);
	else
		a->numb = (int)va_arg(a->ap, int);
}

void	length_all(t_env *a)
{
	if (a->length.hh && !a->capital_o && !a->capital_u)
		a->uns_number = (unsigned char)va_arg(a->ap, int);
	else if (a->length.h && !a->capital_u)
		a->uns_number = (unsigned short int)va_arg(a->ap, long int);
	else if ((a->length.h && a->capital_u) || a->capital_u || a->capital_o)
		a->uns_number = (unsigned long int)va_arg(a->ap, long int);
	else if (a->length.l)
		a->uns_number = (unsigned long int)va_arg(a->ap, unsigned long int);
	else if (a->length.ll)
		a->uns_number =
			(unsigned long long int)va_arg(a->ap, unsigned long long int);
	else if (a->length.j)
		a->uns_number = va_arg(a->ap, uintmax_t);
	else if (a->length.z)
		a->uns_number = (size_t)va_arg(a->ap, size_t);
	else
		a->uns_number = (unsigned int)va_arg(a->ap, unsigned int);
}
