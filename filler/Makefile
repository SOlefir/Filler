# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: solefir <solefir@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/22 17:51:25 by solefir           #+#    #+#              #
#    Updated: 2019/06/27 16:18:23 by solefir          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = solefir

CC = gcc -Wall -Wextra -Werror -I ./filler.h -I ./GNL/get_next_line.h

SRC = ../GNL/libft/ft_bzero.c ../GNL/libft/ft_strlen.c ../GNL/libft/ft_strncpy.c\
	../GNL/libft/ft_memalloc.c ../GNL/libft/ft_strsub.c ../GNL/libft/ft_strdup.c\
	../GNL/libft/ft_strjoin.c ../GNL/libft/ft_strchr.c ../GNL/libft/ft_itoa.c\
	../GNL/get_next_line.c ./help.c\
	./save_data.c ./distance.c ./filler.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $^ -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
