# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ellaca-f <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/14 18:44:13 by ellaca-f          #+#    #+#              #
#    Updated: 2019/11/21 18:32:12 by ellaca-f         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a

CC=gcc

CFLAGS=-Wall -Wextra -Werror -O3

RM=rm -f

LDFLAGS=-L.

LDLIBS=-lft

HDDIRS=-I includes/

SRC=ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c \
ft_memmove.c ft_memchr.c ft_memcmp.c \
ft_strlen.c ft_strdup.c ft_strchr.c \
ft_strlcat.c ft_strrchr.c ft_strnstr.c ft_strlcpy.c \
ft_strncmp.c ft_atoi.c \
ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
ft_toupper.c ft_tolower.c \
ft_strmapi.c ft_strjoin.c ft_substr.c \
ft_strtrim.c ft_split.c \
ft_itoa.c ft_calloc.c \
ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putchar_fd.c \

OBJ=$(SRC:.c=.o)

$(NAME): libft.h
	$(CC) $(CFLAGS) -c $(SRC) $(HDDIRS)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean