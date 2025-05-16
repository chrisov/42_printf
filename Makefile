#
#
CC = cc
CFLAGS = -Wall -Werror -Wextra -I$(INCDIR)
MAKEFLAGS += -s

INCDIR = ./include
SRCDIR = ./src
OBJDIR = ./obj
LIBFTDIR = ./inc/libft

SRCS = $(SRCDIR)/ft_printunbr_fd.c $(SRCDIR)/ft_printnbr_fd.c $(SRCDIR)/ft_printchar_fd.c $(SRCDIR)/ft_printstr_fd.c\
	$(SRCDIR)/ft_printf.c $(SRCDIR)/ft_printxnbr_fd.c $(SRCDIR)/ft_printxxnbr_fd.c $(SRCDIR)/ft_printptr_fd.c\


OBJS = $(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
LIBFT = $(LIBFTDIR)/libft.a
NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJDIR) $(OBJS) $(LIBFT)
	@echo "\033[33mCompilating $(NAME) static library...\033[0m"
	ar rcs $(NAME) $(OBJS)
	@echo "$(NAME) created \033[32msuccessfully\033[0m!"

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(LIBFT):
	@$(MAKE) -C $(LIBFTDIR)

clean:
	@echo "\033[33mRemoving $(NAME) build...\033[0m"
	rm -f $(OBJS)
	rm -rf $(OBJDIR)
	@$(MAKE) -C $(LIBFTDIR) clean
	@echo "$(NAME) build removed \033[32msuccessfully\033[0m!"

fclean: clean
	@echo "\033[33mRemoving $(NAME)...\033[0m"
	rm -f $(NAME)
	@$(MAKE) -C $(LIBFTDIR) fclean
	@echo "$(NAME) removed \033[32msuccessfully\033[0m!"

re: fclean all

.PHONY: all clean fclean re