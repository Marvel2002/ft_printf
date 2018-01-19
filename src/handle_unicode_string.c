/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_unicode_string.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 12:27:04 by mmatime           #+#    #+#             */
/*   Updated: 2018/01/02 13:15:38 by mmatime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_wchar_t(t_env *a)
{
	char			*str;
	unsigned char	*c;

	a->uni_c = (wchar_t)va_arg(a->ap, wint_t);
	if (a->uni_c == 0)
	{
		a->trigger++;
		a->dest = ft_strjoin_zero(a->dest, '\0', a);
		a->count2++;
		return ;
	}
	str = ft_binary(a->uni_c);
	c = ft_unicode_binary(str, a);
	a->dest = ft_strjoin_custom(a->dest, (char*)c, a->count2);
	free(str);
	free(c);
}

int		ft_wint_t_count(t_env *a)
{
	int				i;
	char			*str;
	unsigned char	*c;
	int				count;

	i = 0;
	count = 0;
	while (a->uni_s[i])
	{
		str = ft_binary(a->uni_s[i]);
		c = ft_unicode_binary(str, a);
		if (count + ft_strlen((char*)c) <= a->flags.prec)
			count += ft_strlen((char*)c);
		else if (!a->flags.trigger_prec)
			count += ft_strlen((char*)c);
		i++;
		free(str);
		free(c);
	}
	return (count);
}

void	ft_wint_t_one(t_env *a)
{
	int				i;
	char			*str;
	unsigned char	*c;
	unsigned		temp;

	i = 0;
	temp = 0;
	while (a->uni_s[i] && a->flags.minus)
	{
		str = ft_binary(a->uni_s[i]);
		c = ft_unicode_binary(str, a);
		temp += ft_strlen((char *)c);
		if (temp <= a->flags.prec && a->flags.trigger_prec)
			a->dest = ft_strjoin_custom(a->dest, (char*)c, a->count2);
		else if (!a->flags.trigger_prec)
			a->dest = ft_strjoin_custom(a->dest, (char*)c, a->count2);
		i++;
		free(str);
		free(c);
	}
}

void	ft_wint_t_two(t_env *a)
{
	int				i;
	char			*str;
	unsigned char	*c;
	unsigned int	temp;

	i = 0;
	temp = 0;
	while (a->uni_s[i] && !a->flags.minus)
	{
		str = ft_binary(a->uni_s[i]);
		c = ft_unicode_binary(str, a);
		temp += ft_strlen((char *)c);
		if (temp <= a->flags.prec && a->flags.trigger_prec)
			a->dest = ft_strjoin_custom(a->dest, (char*)c, a->count2);
		else if (!a->flags.trigger_prec)
			a->dest = ft_strjoin_custom(a->dest, (char*)c, a->count2);
		i++;
		free(str);
		free(c);
	}
}

void	ft_wint_t(t_env *a)
{
	unsigned int	count;

	count = 0;
	a->uni_s = va_arg(a->ap, wchar_t *);
	if (!a->uni_s)
	{
		ft_string_void(a);
		return ;
	}
	if (!a->dest)
		a->dest = ft_strnew(1);
	count = ft_wint_t_count(a);
	ft_wint_t_one(a);
	while (a->flags.width > count)
	{
		a->dest = ft_strjoin_char(a->dest, a->space, a);
		a->flags.width--;
	}
	ft_wint_t_two(a);
}
