/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_conversion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 16:06:10 by mmatime           #+#    #+#             */
/*   Updated: 2017/12/27 12:17:50 by mmatime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		int_to_hexa_min(uintmax_t nb)
{
	if (nb < 10)
		return (nb % 10 + '0');
	else if (nb == 10)
		return ('a');
	else if (nb == 11)
		return ('b');
	else if (nb == 12)
		return ('c');
	else if (nb == 13)
		return ('d');
	else if (nb == 14)
		return ('e');
	else
		return ('f');
}

char		int_to_hexa_maj(uintmax_t nb)
{
	if (nb < 10)
		return (nb % 10 + '0');
	else if (nb == 10)
		return ('A');
	else if (nb == 11)
		return ('B');
	else if (nb == 12)
		return ('C');
	else if (nb == 13)
		return ('D');
	else if (nb == 14)
		return ('E');
	else
		return ('F');
}

char		*ft_hexa_min(uintmax_t nb, t_env *a)
{
	uintmax_t	res;
	uintmax_t	hexa;
	char		*dest;

	if (!nb && a->flags.trigger_prec)
		return (ft_strdup(""));
	res = nb / 16;
	hexa = nb - (res * 16);
	a->hexadec = ft_strjoin_char(a->hexadec, int_to_hexa_min(hexa), a);
	if (res > 15)
		return (ft_hexa_min(nb / 16, a));
	if (nb > 15)
		a->hexadec = ft_strjoin_char(a->hexadec, int_to_hexa_min(res), a);
	ft_strrev(a->hexadec);
	dest = ft_strdup(a->hexadec);
	free(a->hexadec);
	a->hexadec = NULL;
	return (dest);
}

char		*ft_hexa_maj(uintmax_t nb, t_env *a)
{
	uintmax_t	res;
	uintmax_t	hexa;
	char		*dest;

	if (!nb && a->flags.trigger_prec)
		return (ft_strdup(""));
	res = nb / 16;
	hexa = nb - (res * 16);
	a->hexadec = ft_strjoin_char(a->hexadec, int_to_hexa_maj(hexa), a);
	if (res > 15)
		return (ft_hexa_maj(nb / 16, a));
	if (nb > 15)
		a->hexadec = ft_strjoin_char(a->hexadec, int_to_hexa_maj(res), a);
	ft_strrev(a->hexadec);
	dest = ft_strdup(a->hexadec);
	free(a->hexadec);
	a->hexadec = NULL;
	return (dest);
}

char		*ft_int_to_oct(uintmax_t nb)
{
	uintmax_t		res;
	char			*str;
	char			*tmp;

	res = nb / 8;
	str = ft_itoa_max(nb % 8);
	if ((long)nb == LONG_MIN)
		return (ft_strdup("1000000000000000000000"));
	while (res > 8)
	{
		tmp = ft_itoa_max(res % 8);
		str = ft_strjoin(str, tmp);
		res = res / 8;
		free(tmp);
		tmp = NULL;
	}
	if (res)
	{
		tmp = ft_itoa_max(res);
		str = ft_strjoin(str, tmp);
		free(tmp);
		tmp = NULL;
	}
	ft_strrev(str);
	return (str);
}
