/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_unicode_binary.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 13:58:27 by mmatime           #+#    #+#             */
/*   Updated: 2018/01/02 14:07:55 by mmatime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_first(char *str, t_env *a)
{
	str = ft_binary_conversion_one(str);
	a->bin_iter = 2;
	a->tab = ft_cut_binary(str, a);
	free(str);
}

void			ft_second(char *str, t_env *a)
{
	str = ft_binary_conversion_two(str);
	a->bin_iter = 3;
	a->tab = ft_cut_binary(str, a);
	free(str);
}

void			ft_third(char *str, t_env *a)
{
	str = ft_binary_conversion_three(str);
	a->bin_iter = 4;
	a->tab = ft_cut_binary(str, a);
	free(str);
}

unsigned char	*ft_unicode_binary(char *str, t_env *a)
{
	int				bin_len;

	bin_len = ft_binary_len(str);
	if (bin_len <= 7)
	{
		a->bin_iter = 1;
		a->tab = ft_cut_binary(str, a);
	}
	else if (bin_len > 7 && bin_len <= 11)
		ft_first(str, a);
	else if (bin_len > 11 && bin_len <= 16)
		ft_second(str, a);
	else if (bin_len > 16 && bin_len <= 21)
		ft_third(str, a);
	else
		return (NULL);
	return (a->tab);
}
