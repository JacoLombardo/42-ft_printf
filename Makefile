# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/08 12:40:11 by jalombar          #+#    #+#              #
#    Updated: 2024/05/08 17:46:44 by jalombar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc   
CFLAGS = -Wall -Werror -Wextra
SRCS = ft_printf.c ft_printf_c.c ft_printf_s.c ft_printf_p.c ft_printf_i.c ft_printf_u.c ft_printf_x.c ft_printf_xx.c ft_printf_z.c ft_strlen.c ft_memcpy.c ft_itoa.c
OBJS = $(SRCS:.c=.o)
HEADER = ft_printf.h
NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@
	
clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
