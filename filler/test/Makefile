# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: solefir <solefir@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/22 17:51:25 by solefir           #+#    #+#              #
#    Updated: 2019/06/29 17:21:13 by solefir          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = solefir.test

CC = gcc -Wall -Wextra -Werror -I ./filler.h -I ./GNL/get_next_line.h

SRC = ../../GNL/libft/ft_bzero.c ../../GNL/libft/ft_strlen.c ../../GNL/libft/ft_strncpy.c\
	../../GNL/libft/ft_memalloc.c ../../GNL/libft/ft_strsub.c ../../GNL/libft/ft_strdup.c\
	../../GNL/libft/ft_strjoin.c ../../GNL/libft/ft_strchr.c ../../GNL/libft/ft_itoa.c\
	../../GNL/libft/ft_putnbr.c ../../GNL/libft/ft_putchar.c\
	../../GNL/get_next_line.c\
	./test_save_data.c ./test_distance.c ./test_filler.c ./test_chek_step.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $^ -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
