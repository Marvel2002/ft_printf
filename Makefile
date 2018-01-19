# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmatime <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/12 21:25:11 by mmatime           #+#    #+#              #
#    Updated: 2018/01/02 18:06:44 by mmatime          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra $(INCLUDE)  
INCLUDE = -Ilibft -Iinclude
LIB_PATH = ./libft/
SRC_PATH = ./src/

SRC = $(SRC_PATH)ft_printf.c \
	  $(SRC_PATH)handle_char_ptr.c \
	  $(SRC_PATH)handle_conversion.c \
	  $(SRC_PATH)handle_decimal.c \
	  $(SRC_PATH)handle_flags.c \
	  $(SRC_PATH)handle_hexa_maj.c \
	  $(SRC_PATH)handle_hexa_min.c \
	  $(SRC_PATH)handle_octal.c \
	  $(SRC_PATH)handle_string.c \
	  $(SRC_PATH)handle_unsigned.c \
	  $(SRC_PATH)handle_width_precision.c \
	  $(SRC_PATH)handle_length.c \
	  $(SRC_PATH)handle_unicode.c \
	  $(SRC_PATH)handle_binary.c \
	  $(SRC_PATH)handle_unicode_string.c \
	  $(SRC_PATH)handle_decimal_two.c \
	  $(SRC_PATH)handle_string_two.c \
	  $(SRC_PATH)handle_length_sign.c \
	  $(SRC_PATH)handle_unicode_binary.c \
	  $(SRC_PATH)ft_utils.c \

OBJ_LIBFT = $(LIB_PATH)ft_itoa.o \
			$(LIB_PATH)ft_itoa_minus.o \
			$(LIB_PATH)ft_putnbr_c.o \
			$(LIB_PATH)ft_strdup.o \
			$(LIB_PATH)ft_strjoin.o \
			$(LIB_PATH)ft_strjoin_custom.o \
			$(LIB_PATH)ft_strjoin_precision.o \
			$(LIB_PATH)ft_strlen.o \
			$(LIB_PATH)ft_strlen_n.o \
			$(LIB_PATH)ft_putchar.o \
			$(LIB_PATH)ft_putnbr.o \
			$(LIB_PATH)ft_atoi.o \
			$(LIB_PATH)ft_putstr.o \
			$(LIB_PATH)ft_strnew.o \
			$(LIB_PATH)ft_itoa_unsigned.o \
			$(LIB_PATH)ft_itoa_plus.o \
			$(LIB_PATH)ft_itoa_minus.o \
			$(LIB_PATH)ft_itoa_max.o \
			$(LIB_PATH)ft_itoa_umax.o \
			$(LIB_PATH)ft_putstr_n.o \
			$(LIB_PATH)ft_strlen_plus.o \
			$(LIB_PATH)ft_strdel.o \
			$(LIB_PATH)ft_memcpy.o \
			$(LIB_PATH)ft_memset.o \
			$(LIB_PATH)ft_memalloc.o \
			$(LIB_PATH)ft_strcpy.o \
			$(LIB_PATH)ft_strrev.o \


OBJ_SRC = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ_SRC)
	make -C $(LIB_PATH)
	ar rc $(NAME) $(OBJ_SRC) $(OBJ_LIBFT)
	ranlib $(NAME)

clean:
	make -C $(LIB_PATH) clean
	/bin/rm -f $(OBJ_SRC)

fclean: clean
	make -C $(LIB_PATH) fclean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
