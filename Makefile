
CC = cc
CFLAGS = -Wall -Werror -Wextra

SRCS = ft_printf.c ft_get_next_char.c ft_putnbr_fd.c

OBJS = $(SRCS:.c=.o)
NAME = libftprintf.a


all = $(NAME)

$(NAME) : $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean: 
	rm -f $(OBJS) $(NAME)

fclean: clean 
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
