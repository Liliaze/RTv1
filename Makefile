# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dboudy <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/04/19 11:43:50 by dboudy            #+#    #+#              #
#    Updated: 2016/05/11 16:37:26 by dboudy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rtv1
GCC = gcc
INCLIB = -I libft/includes
CFLAGS = -O3 -Weverything -Wall -Wextra -Werror
FLAGS2 = -lm -lmlx -framework OPENGL -framework AppKit
HEADERDIR = ./include/
HEADERNAME = $(NAME).h color_key_mask.h
SRCDIR = ./src/
SRCNAME = main.c \
		  raytracer.c \
		  vector3d.c \
		  cercle.c \
		  test.c \
		  loop.c \
		  tools.c

OBJDIR = ./obj/
OBJNAME = $(SRCNAME:.c=.o)

SRC = $(addprefix $(SRCDIR), $(SRCNAME))
HEADER = $(addprefix $(HEADERDIR), $(HEADERNAME))
OBJ = $(addprefix $(OBJDIR), $(OBJNAME))

all: libft $(NAME)

$(NAME): libft/libft.a $(OBJ) $(HEADER)
	$(GCC) $(CFLAGS) $(FLAGS2) $(OBJ) -o $(NAME) $(INCLIB) -L libft -lft

$(OBJ): | $(OBJDIR)

$(OBJDIR)%.o: $(SRCDIR)%.c
	$(GCC) $(CFLAGS) $(LAGS2) $(INCLIB) -I $(HEADERDIR) -c $< -o $@

$(OBJDIR):
	@if [ ! -d "$(OBJDIR)" ]; then \
		mkdir $(OBJDIR);\
		fi

.PHONY: clean fclean proper re libft

libft:
	make -C libft

clean:
	@make clean -C libft
	rm -rf $(OBJ)
	rm -rf $(OBJDIR)

fclean: clean
	@make fclean -C libft
	rm -rf $(NAME)

proper: all clean

re: fclean all
