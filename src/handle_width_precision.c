/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_width_precision.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 16:17:30 by mmatime           #+#    #+#             */
/*   Updated: 2018/01/02 11:57:21 by mmatime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_precision(const char *str, t_env *a)
{
	char	*dest;
	int		nb;

	dest = NULL;
	nb = 0;
	while (str[a->i] && str[a->i] >= '0' && str[a->i] <= '9')
	{
		dest = ft_strjoin_char(dest, str[a->i], a);
		a->i++;
	}
	if (!dest)
		return (0);
	nb = ft_atoi(dest);
	free(dest);
	return (nb);
}

int			ft_width(const char *str, t_env *a)
{
	char	*dest;
	int		nb;

	dest = NULL;
	nb = 0;
	while (str[a->i] && str[a->i] >= '0' && str[a->i] <= '9')
	{
		dest = ft_strjoin_char(dest, str[a->i], a);
		a->i++;
	}
	if (!dest)
		return (0);
	nb = ft_atoi(dest);
	free(dest);
	return (nb);
}
