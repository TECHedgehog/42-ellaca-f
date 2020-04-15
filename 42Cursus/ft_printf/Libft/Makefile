# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eric <eric@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/14 18:44:13 by ellaca-f          #+#    #+#              #
#    Updated: 2020/04/08 11:36:59 by eric             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a

CC=gcc

CFLAGS=-Wall -Wextra -O3

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

SRCBONUS=ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c \

OBJ=$(SRC:.c=.o) $(SRCBONUS:.c=.o)

$(NAME): libft.h
	$(CC) $(CFLAGS) -c $(SRC) $(SRCBONUS) $(HDDIRS)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

all: $(NAME)

bonus: all

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean