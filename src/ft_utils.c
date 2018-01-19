/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 14:11:00 by mmatime           #+#    #+#             */
/*   Updated: 2018/01/02 18:14:18 by mmatime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_realloc(char **ptr, size_t size, char c)
{
	char		*newptr;

	newptr = NULL;
	if (*ptr)
	{
		newptr = (char *)ft_memalloc(sizeof(char) * (size + 2));
		if (!newptr)
			return ;
		ft_memcpy(newptr, *ptr, size);
		free((void *)*ptr);
		*ptr = newptr;
		(*ptr)[size] = c;
	}
	else
	{
		*ptr = (char *)ft_memalloc(sizeof(char) * 2);
		if (!ptr)
			return ;
		*ptr[size] = c;
	}
}

char		*ft_strjoin_char(char *s1, char c, t_env *a)
{
	ft_realloc(&s1, ft_strlen_plus(s1, a->count2), c);
	return (s1);
}

char		*ft_strjoin_zero(char *s1, char c, t_env *a)
{
	ft_realloc(&s1, ft_strlen_plus(s1, a->count2), c);
	return (s1);
}

void		ft_init(t_env *a)
{
	a->hexadec = NULL;
	a->binary = NULL;
	a->tab = NULL;
	a->flags.diese = 0;
	a->flags.prec = 0;
	a->flags.trigger_prec = 0;
	a->flags.tmp = 0;
	a->flags.width = 0;
	a->flags.diese = 0;
	a->flags.space = 0;
	a->flags.minus = 0;
	a->flags.plus = 0;
	a->flags.zero = 0;
	a->count = a->count2;
	a->space = ' ';
	a->numb = 0;
	a->capital_d = 0;
	a->capital_u = 0;
	a->capital_o = 0;
}

void		ft_display(t_env *a)
{
	if (a->i == 0)
		a->dest = ft_strdup("");
	ft_putstr_n(a->dest, a->count2);
	a->ret = ft_strlen_plus(a->dest, a->count2);
	va_end(a->ap);
	free(a->dest);
	free(a);
}
