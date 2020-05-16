# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ellaca-f <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/08 11:39:19 by ellaca-f          #+#    #+#              #
#    Updated: 2020/04/08 11:39:19 by ellaca-f         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 		libftprintf.a
LIBFT_A = 	libft.a

COMP =		gcc -Wall -Wextra -g $(PRINTF_H) $(LIBFT_H) -c -o

PRINTF_H = 	-I ./
LIBFT_H =	-I libft/

OBJ_DIR =	obj/
SRC_DIR =	./
LIB_DIR =	libft/

CFILE =		ft_printf.c \
			tab_initializer.c \
			tab_reinitializer.c \
			processor.c \
			processor_flags.c \
			processor_specs.c \
			processor_di.c \
			printer.c \
			flags_treatment.c \
			flags_treatment_aux.c \
			processor_x.c \
			processor_cs.c \
			processor_u.c \
			processor_p.c \

CFIND =		$(CFILE:%=$(SRC_DIR)%)

OFILE =		$(CFILE:%.c=%.o)

OBJ =		$(addprefix $(OBJ_DIR), $(OFILE))

all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
		@mkdir -p $(OBJ_DIR)
		@echo Create: ft_printf Object directory

$(NAME): $(OBJ)
		@echo LIBFT START
		@make -C $(LIB_DIR)
		@echo Copying $(LIBFT_A) to root.
		@cp $(LIB_DIR)$(LIBFT_A) .
		@mv $(LIBFT_A) $(NAME)
		@ar rc $(NAME) $(addprefix $(OBJ_DIR), $(OFILE))
		@ranlib $(NAME)
		@echo Merged: $(NAME) with $(LIBFT_A)
		@echo FT_PRINTF COMPLETE

$(OBJ): $(CFIND)
		@$(MAKE) $(OFILE)

$(OFILE):
		@echo Create: $(@:obj/%=%)
		@$(COMP) $(OBJ_DIR)$@ $(SRC_DIR)$(@:%.o=%.c)

clean:
		@/bin/rm -rf $(OBJ_DIR)
		@make -C $(LIB_DIR) clean
		@echo Cleaned ft_printf object files

fclean: clean
		@/bin/rm -f $(NAME)
		@make -C $(LIB_DIR) fclean
		@echo Cleaned $(NAME)

re: fclean all

.PHONY: all clean flcean re
