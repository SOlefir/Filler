# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: solefir <solefir@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/22 17:51:25 by solefir           #+#    #+#              #
#    Updated: 2019/07/03 20:59:57 by solefir          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = solefir.test

CC = gcc -Wall -Wextra -Werror -I ./filler_test.h -I ../my_filler_program/GNL/get_next_line.h

SRC = ../my_filler_program/GNL/libft/ft_bzero.c ../my_filler_program/GNL/libft/ft_strlen.c\
	../my_filler_program/GNL/libft/ft_strncpy.c	../my_filler_program/GNL/libft/ft_memalloc.c\
	../my_filler_program/GNL/libft/ft_strsub.c ../my_filler_program/GNL/libft/ft_strdup.c\
	../my_filler_program/GNL/libft/ft_strjoin.c ../my_filler_program/GNL/libft/ft_strchr.c\
	../my_filler_program/GNL/libft/ft_itoa.c ../my_filler_program/GNL/libft/ft_putnbr.c\
	../my_filler_program/GNL/libft/ft_putchar.c ../my_filler_program/GNL/libft/ft_masmemdel.c\
	../my_filler_program/GNL/libft/ft_strdel.c ../my_filler_program/GNL/get_next_line.c\
	./test_save_data.c ./test_distance.c ./test_filler.c 

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $^ -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
