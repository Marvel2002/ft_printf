/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_binary.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 06:58:16 by mmatime           #+#    #+#             */
/*   Updated: 2017/12/27 15:35:38 by mmatime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_binary_small(int nb, char *dest)
{
	int i;
	int octal;

	i = 0;
	octal = 128;
	dest = (char *)malloc(sizeof(char) * (8 + 1));
	while (i < 8)
	{
		if (nb >= octal)
		{
			dest[i] = '1';
			nb = nb - octal;
			octal = octal / 2;
		}
		else
		{
			dest[i] = '0';
			octal = octal / 2;
		}
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_binary_medium(int nb, char *dest)
{
	int i;
	int octal;

	i = 0;
	octal = 32768;
	dest = (char *)malloc(sizeof(char) * (16 + 1));
	while (i < 16)
	{
		if (nb >= octal)
		{
			dest[i] = '1';
			nb = nb - octal;
			octal = octal / 2;
		}
		else
		{
			dest[i] = '0';
			octal = octal / 2;
		}
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_binary_large(int nb, char *dest)
{
	int i;
	int octal;

	i = 0;
	octal = 8388608;
	dest = (char *)malloc(sizeof(char) * (24 + 1));
	while (i < 24)
	{
		if (nb >= octal)
		{
			dest[i] = '1';
			nb = nb - octal;
			octal = octal / 2;
		}
		else
		{
			dest[i] = '0';
			octal = octal / 2;
		}
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_binary(int nb)
{
	char *dest;

	dest = NULL;
	if (nb >= 0 && nb < 128)
		dest = ft_binary_small(nb, dest);
	else if (nb >= 128 && nb < 32768)
		dest = ft_binary_medium(nb, dest);
	else if (nb >= 32768 && nb < 8388608)
		dest = ft_binary_large(nb, dest);
	else
		return (NULL);
	return (dest);
}

int		ft_binary_len(char *str)
{
	int i;
	int nb;

	i = 0;
	nb = 0;
	while (str[i] == '0')
		i++;
	while (str[i])
	{
		i++;
		nb++;
	}
	return (nb);
}
