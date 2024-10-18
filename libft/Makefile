
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dchrysov <dchrysov@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/09 16:35:33 by dchrysov          #+#    #+#              #
#    Updated: 2024/10/09 16:35:33 by dchrysov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Werror -Wextra

# Source files
SRCS = ft_isalnum.c ft_isprint.c ft_strlen.c ft_toupper.c ft_tolower.c ft_isalpha.c\
		ft_isdigit.c ft_isascii.c ft_memset.c ft_strchr.c ft_strrchr.c ft_strlcpy.c\
		ft_strncmp.c ft_strlcat.c ft_atoi.c ft_bzero.c ft_memcpy.c\
		ft_memcmp.c ft_memmove.c ft_memchr.c ft_calloc.c ft_strdup.c ft_itoa.c\
		ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_substr.c\
		ft_strjoin.c ft_striteri.c ft_strmapi.c ft_strtrim.c ft_strnstr.c ft_split.c 

# Object files
OBJS = $(SRCS:.c=.o)

# Executable name
NAME = libft.a

# Default target
all: $(NAME)

# Linking the executable
$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

# Compiling source files to object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up generated files
clean:
	rm -f $(OBJS) $(NAME)

# Remove all generated files (including executable)
fclean: clean
	rm -f $(NAME)

# Rebuild the project
re: fclean all

# Phony targets
.PHONY: all clean fclean re