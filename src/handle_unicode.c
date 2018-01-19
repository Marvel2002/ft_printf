/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_unicode.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 07:52:49 by mmatime           #+#    #+#             */
/*   Updated: 2018/01/02 14:07:20 by mmatime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char				*ft_binary_conversion_one(char *str)
{
	int		i;
	int		j;
	char	*dest;

	i = 0;
	j = 0;
	dest = ft_strdup("110xxxxx10xxxxxx");
	ft_strrev(str);
	ft_strrev(dest);
	while (dest[i])
	{
		if (dest[i] == 'x')
		{
			dest[i] = str[j];
			j++;
		}
		i++;
	}
	ft_strrev(dest);
	return (dest);
}

char				*ft_binary_conversion_two(char *str)
{
	int		i;
	int		j;
	char	*dest;

	i = 0;
	j = 0;
	dest = ft_strdup("1110xxxx10xxxxxx10xxxxxx");
	ft_strrev(str);
	ft_strrev(dest);
	while (dest[i])
	{
		if (dest[i] == 'x')
		{
			dest[i] = str[j];
			j++;
		}
		i++;
	}
	ft_strrev(dest);
	return (dest);
}

char				*ft_binary_conversion_three(char *str)
{
	int		i;
	int		j;
	char	*dest;

	i = 0;
	j = 0;
	dest = ft_strdup("11110xxx10xxxxxx10xxxxxx10xxxxxx");
	ft_strrev(str);
	ft_strrev(dest);
	while (dest[i])
	{
		if (dest[i] == 'x')
		{
			dest[i] = str[j];
			j++;
		}
		i++;
	}
	ft_strrev(dest);
	return (dest);
}

unsigned char		ft_count_binary(int i)
{
	unsigned char c;

	if (i == 0)
		c = 1;
	else if (i == 1)
		c = 2;
	else if (i == 2)
		c = 4;
	else if (i == 3)
		c = 8;
	else if (i == 4)
		c = 16;
	else if (i == 5)
		c = 32;
	else if (i == 6)
		c = 64;
	else
		c = 128;
	return (c);
}

unsigned char		*ft_cut_binary(char *str, t_env *a)
{
	int				i;
	int				j;
	unsigned char	*tab;

	i = -1;
	ft_strrev((char*)str);
	tab = (unsigned char *)ft_memalloc(sizeof(*tab) * (a->bin_iter + 1));
	while (++i < 8)
		tab[0] += (str[i] == '1') ? ft_count_binary(i) : 0;
	(j = -1) && (--i);
	while (++i < 16 && a->bin_iter > 1 && ++j >= 0)
		tab[1] += (str[i] == '1') ? ft_count_binary(j) : 0;
	(j = -1) && (--i);
	while (++i < 24 && a->bin_iter > 2 && ++j >= 0)
		tab[2] += (str[i] == '1') ? ft_count_binary(j) : 0;
	(j = -1) && (--i);
	while (++i < 32 && a->bin_iter > 3 && ++j >= 0)
		tab[3] += (str[i] == '1') ? ft_count_binary(j) : 0;
	ft_strrev((char*)tab);
	return (tab);
}
