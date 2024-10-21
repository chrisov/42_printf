
CC = cc
CFLAGS = -Wall -Werror -Wextra

SRCS = ft_putunbr_fd.c ft_putnbr_fd.c ft_putchar_fd.c ft_putstr_fd.c\
	ft_strlen.c ft_printf.c ft_putxnbr_fd.c ft_putxxnbr_fd.c ft_putptr_fd.c

OBJS = $(SRCS:.c=.o)

NAME = libftprintf.a

all: $(NAME)

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
