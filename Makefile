
NAME =  libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = ft_putstr.c ft_printf.c ft_putchar.c ft_print_hex.c ft_putnbr.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
