# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: solefir <solefir@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/22 17:51:25 by solefir           #+#    #+#              #
#    Updated: 2019/05/22 18:39:09 by solefir          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = solefir.filler

CC = gcc -Wall -Wextra -Werror -I filler.h

SRC = ../GNL/libft/ft_bzero.c ../GNL/libft/ft_strlen.c ../GNL/libft/ft_strcpy.c\
	../GNL/libft/ft_memalloc.c ../GNL/libft/ft_strsub.c ../GNL/libft/ft_strdup.c\
	../GNL/libft/ft_strjoin.c ../GNL/libft/ft_strchr.c ./filler.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $^ -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
