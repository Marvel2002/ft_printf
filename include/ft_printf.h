/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 20:54:26 by mmatime           #+#    #+#             */
/*   Updated: 2018/01/02 18:15:56 by mmatime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>
# include <limits.h>
# include <wchar.h>

typedef struct	s_length
{
	int				h;
	int				hh;
	int				l;
	int				ll;
	int				j;
	int				z;
}				t_length;

typedef struct	s_flags
{
	int				diese;
	int				space;
	int				count_space;
	int				minus;
	int				plus;
	int				zero;
	int				trigger_prec;
	unsigned int	prec;
	unsigned int	width;
	unsigned int	tmp;
}				t_flags;

typedef struct	s_env
{
	va_list				ap;
	int					i;
	char				*s;
	char				*dest;
	char				*format;
	char				*hexadec;
	unsigned char		*tab;
	int					ret;
	int					count;
	int					count2;
	int					trigger;
	int					capital_u;
	int					capital_d;
	int					capital_o;
	intmax_t			numb;
	uintmax_t			uns_number;
	char				space;
	unsigned char		c;
	unsigned int		nb;
	long int			nb_d;
	void				*p;
	wint_t				uni_c;
	wchar_t				*uni_s;
	char				*binary;
	int					bin_iter;
	struct s_flags		flags;
	struct s_length		length;
}				t_env;

void			ft_sub_first(const char *format, t_env *a);
void			ft_sub_second(const char *format, t_env *a);
void			ft_sub_third(const char *format, t_env *a);
void			ft_display(t_env *a);
void			ft_ptr(t_env *a);
void			ft_char(t_env *a);
char			int_to_hexa_min(uintmax_t nb);
char			int_to_hexa_maj(uintmax_t nb);
char			*ft_hexa_min(uintmax_t nb, t_env *a);
char			*ft_hexa_maj(uintmax_t nb, t_env *a);
char			*ft_int_to_oct(uintmax_t nb);
void			ft_decimal_first(char *str, t_env *a);
void			ft_decimal_second(char *str, t_env *a);
void			ft_decimal_third(char *str, t_env *a);
void			ft_decimal_four(char *str, t_env *a);
void			ft_decimal_full(t_env *a);
void			ft_flags_decimal(t_env *a);
void			ft_flags(const char *format, t_env *a);
void			ft_hexa_maj_full(t_env *a);
void			ft_hexa_maj_one(char *str, t_env *a);
void			ft_hexa_maj_two(char *str, t_env *a);
void			ft_hexa_maj_three(char *str, t_env *a);
void			ft_hexa_maj_four(char *str, t_env *a);
void			ft_hexa_min_full(t_env *a);
void			ft_hexa_min_one(char *str, t_env *a);
void			ft_hexa_min_two(char *str, t_env *a);
void			ft_hexa_min_three(char *str, t_env *a);
void			ft_hexa_min_four(char *str, t_env *a);
void			ft_hexa_min_full(t_env *a);
void			ft_octal_one(char *str, t_env *a);
void			ft_octal_two(char *str, t_env *a);
void			ft_octal_three(char *str, t_env *a);
void			ft_octal_four(char *str, t_env *a);
void			ft_octal_full(t_env *a);
void			ft_add_zero_octal(char *str, t_env *a);
void			ft_string_one(t_env *a);
void			ft_string_two(t_env *a);
void			ft_string_three(t_env *a);
void			ft_string_four(t_env *a);
void			ft_string_five(t_env *a);
void			ft_string_full(t_env *a);
void			ft_unsigned_one(char *str, t_env *a);
void			ft_unsigned_two(char *str, t_env *a);
void			ft_unsigned_three(char *str, t_env *a);
void			ft_unsigned_four(char *str, t_env *a);
void			ft_unsigned_full(t_env *a);
int				ft_precision(const char *str, t_env *a);
int				ft_width(const char *str, t_env *a);
void			ft_length(const char *format, t_env *a);
void			length_decimal(t_env *a);
void			length_all(t_env *a);
char			*ft_strjoin_char(char *s1, char c, t_env *a);
char			*ft_strjoin_zero(char *s1, char c, t_env *a);
void			ft_realloc(char **ptr, size_t size, char c);
void			ft_strrev(char *str);
void			ft_init(t_env *a);
int				ft_printf(const char *format, ...);
void			ft_purcent(t_env *a);
void			ft_wint_t(t_env *a);
int				ft_wint_t_count(t_env *a);
void			ft_wint_t_one(t_env *a);
void			ft_wint_t_two(t_env *a);
void			ft_wchar_t(t_env *a);
char			*ft_binary_small(int nb, char *dest);
char			*ft_binary_medium(int nb, char *dest);
char			*ft_binary_large(int nb, char *dest);
char			*ft_binary(int nb);
int				ft_binary_len(char *str);
unsigned char	*ft_unicode_binary(char *str, t_env *a);
unsigned char	*ft_cut_binary(char *str, t_env *a);
void			ft_tab_init_null(char *tab, int nb, unsigned char value);
unsigned char	ft_count_binary(int i);
char			*ft_binary_conversion_one(char *str);
char			*ft_binary_conversion_two(char *str);
char			*ft_binary_conversion_three(char *str);
void			ft_string_void(t_env *a);

#endif
