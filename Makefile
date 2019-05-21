
NAME = bot

CC = gcc -Wall -Wextra -Werror -I ./GNL/get_next_line.h

SRC = ./GNL/libft/ft_bzero.c ./GNL/libft/ft_memdel.c ./GNL/libft/ft_strclr.c\
    ./GNL/libft/ft_strdel.c ./GNL/libft/ft_striter.c ./GNL/libft/ft_striteri.c\
    ./GNL/libft/ft_putchar.c ./GNL/libft/ft_putchar_fd.c ./GNL/libft/ft_putendl.c\
    ./GNL/libft/ft_putendl_fd.c ./GNL/libft/ft_putnbr.c ./GNL/libft/ft_putnbr_fd.c\
    ./GNL/libft/ft_putstr.c ./GNL/libft/ft_putstr_fd.c ./GNL/libft/ft_memalloc.c\
    ./GNL/libft/ft_memcpy.c ./GNL/libft/ft_memccpy.c ./GNL/libft/ft_memchr.c\
    ./GNL/libft/ft_memmove.c ./GNL/libft/ft_memset.c ./GNL/libft/ft_atoi.c\
    ./GNL/libft/ft_isalnum.c ./GNL/libft/ft_isalpha.c ./GNL/libft/ft_isascii.c\
    ./GNL/libft/ft_isdigit.c ./GNL/libft/ft_isprint.c ./GNL/libft/ft_memcmp.c\
    ./GNL/libft/ft_strcmp.c ./GNL/libft/ft_strequ.c ./GNL/libft/ft_strnequ.c\
    ./GNL/libft/ft_strncmp.c ./GNL/libft/ft_tolower.c ./GNL/libft/ft_toupper.c\
    ./GNL/libft/ft_itoa.c ./GNL/libft/ft_strcat.c ./GNL/libft/ft_strncat.c\
    ./GNL/libft/ft_strnew.c ./GNL/libft/ft_strchr.c ./GNL/libft/ft_strrchr.c\
    ./GNL/libft/ft_strcpy.c ./GNL/libft/ft_strmap.c ./GNL/libft/ft_strmapi.c\
    ./GNL/libft/ft_strncpy.c ./GNL/libft/ft_strdup.c ./GNL/libft/ft_strjoin.c\
    ./GNL/libft/ft_strstr.c ./GNL/libft/ft_strnstr.c ./GNL/libft/ft_strsub.c\
    ./GNL/libft/ft_strtrim.c ./GNL/libft/ft_strsplit.c ./GNL/libft/ft_strlcat.c\
    ./GNL/libft/ft_strlen.c ./GNL/libft/ft_lstnew.c ./GNL/libft/ft_lstmap.c\
    ./GNL/libft/ft_lstdelone.c ./GNL/libft/ft_lstdel.c ./GNL/libft/ft_lstadd.c\
    ./GNL/libft/ft_lstiter.c ./GNL/libft/ft_masmemdel.c ./GNL/libft/ft_lstdelcontent.c\
	./GNL/libft/ft_iswhitespace.c ./GNL/get_next_line.c ./bot.c\

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $^ -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
