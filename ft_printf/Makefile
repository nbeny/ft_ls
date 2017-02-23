# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/16 14:57:18 by nbeny             #+#    #+#              #
#    Updated: 2017/02/17 13:37:46 by nbeny            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

SRC	=	src/ft_printf.c src/ft_check.c src/ft_dispatcher.c\
		src/ft_handler_c.c src/ft_handler_s.c src/ft_handler_p.c src/ft_handler_d.c\
		src/ft_handler_o.c src/ft_handler_u.c src/ft_handler_x.c src/ft_handler.c\
		src/ft_flag_hhlld.c src/ft_flag_hhllo.c src/ft_flag_hhllu.c src/ft_flag_hhllx.c\
		src/ft_flag_jzd.c src/ft_flag_jzo.c src/ft_flag_jzu.c src/ft_flag_jzx.c\
		src/ft_flags_char.c src/ft_flags_int.c src/ft_precision.c

OBJ	=	ft_printf.o ft_check.o ft_dispatcher.o\
		ft_handler_c.o ft_handler_s.o ft_handler_p.o ft_handler_d.o\
		ft_handler_o.o ft_handler_u.o ft_handler_x.o ft_handler.o\
		ft_flag_hhlld.o ft_flag_hhllo.o ft_flag_hhllu.o ft_flag_hhllx.o\
		ft_flag_jzd.o ft_flag_jzo.o ft_flag_jzu.o ft_flag_jzx.o\
		ft_flags_char.o ft_flags_int.o ft_precision.o

HDR	=	ft_printf.h

OBJ_LFT	=	ft_memset.o ft_bzero.o ft_memcpy.o ft_memccpy.o\
		ft_memmove.o ft_memchr.o ft_memcmp.o\
		ft_strlen.o ft_strdup.o	ft_strcpy.o ft_strncpy.o\
		ft_strcat.o ft_strncat.o ft_strlcat.o ft_strchr.o\
		ft_strrchr.o ft_strstr.o ft_strnstr.o ft_strcmp.o\
		ft_strncmp.o\
		ft_atoi.o ft_isalpha.o ft_isdigit.o ft_isalnum.o\
		ft_isascii.o ft_isprint.o ft_toupper.o ft_tolower.o\
		ft_memalloc.o ft_memdel.o\
		ft_strnew.o ft_strdel.o ft_strclr.o ft_striter.o\
		ft_striteri.o ft_strmap.o ft_strmapi.o ft_strequ.o\
		ft_strnequ.o ft_strsub.o ft_strjoin.o ft_strtrim.o\
		ft_strsplit.o\
		ft_itoa.o ft_itoa_base.o ft_litoa_base.o ft_uitoa_base.o\
		ft_ulitoa_base.o ft_max_itoa_base.o ft_umax_itoa_base.o\
		ft_size_itoa_base.o ft_short_itoa_base.o ft_ushort_itoa_base.o\
		ft_char_itoa_base.o ft_uchar_itoa_base.o ft_llitoa_base.o\
		ft_ullitoa_base.o\
		ft_putchar.o ft_putstr.o ft_putendl.o ft_putnbr.o\
		ft_putchar_fd.o ft_putstr_fd.o ft_putendl_fd.o ft_putnbr_fd.o\
		ft_lstnew.o ft_lstdelone.o ft_lstdel.o ft_lstadd.o\
		ft_lstiter.o ft_lstmap.o\
		ft_max.o ft_min.o ft_sort_integer_tab.o ft_sort_params.o\
		ft_sqrt.o\
		ft_putcstr.o ft_capitalizer.o ft_sign.o ft_rotcstring.o\
		ft_putnstr.o

HDR_LFT	=	-I include

FLAGS	=	-Wall -Wextra -Werror

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(SRC)
		@echo ">Build $(NAME)"
		@make -C libft/
		@gcc -c $(FLAGS) $(SRC)
		@ar rc $(NAME) $(OBJ) $(addprefix 'libft/', $(OBJ_LFT))
		@ranlib $(NAME)

clean:
		@echo ">Delete object"
		@rm -f $(OBJ)
		@make -C libft/ clean

fclean:
		@echo ">Delete $(NAME)"
		@rm -f $(NAME) $(OBJ)
		@make -C libft/ fclean

re: fclean all
