# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dboudy <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/24 10:53:12 by dboudy            #+#    #+#              #
#    Updated: 2016/05/18 10:50:31 by dboudy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
GCC = gcc
CFLAGS = -Werror -Wextra -Wall
HEADERS = includes/
OBJDIR = ./objs/
SRCS = ft_itoa.c ft_putchar_fd.c ft_strcmp.c \
	   ft_strmap.c ft_strstr.c ft_memalloc.c \
	   ft_putendl.c ft_strcpy.c ft_strmapi.c \
	   ft_strsub.c ft_memccpy.c ft_putendl_fd.c \
	   ft_strdel.c ft_strncat.c ft_strtrim.c \
	   ft_atoi.c ft_memchr.c ft_putnbr.c \
	   ft_strdup.c ft_strncmp.c ft_tolower.c \
	   ft_bzero.c ft_memcmp.c ft_putnbr_fd.c \
	   ft_strequ.c ft_strncpy.c ft_toupper.c \
	   ft_isalnum.c ft_memcpy.c ft_putstr.c \
	   ft_striter.c ft_strnequ.c ft_color.c \
	   ft_isalpha.c ft_memdel.c ft_putstr_fd.c \
	   ft_striteri.c ft_strnew.c ft_isascii.c \
	   ft_memmove.c ft_strcat.c ft_strjoin.c \
	   ft_strnstr.c ft_isdigit.c ft_memset.c \
	   ft_strchr.c ft_strlcat.c ft_strrchr.c \
	   ft_isprint.c ft_putchar.c ft_strclr.c \
	   ft_strlen.c ft_strsplit.c ft_count_and_clear.c \
	   ft_lstnew.c ft_lstdelone.c ft_lstdel.c \
	   ft_lstadd.c ft_lstiter.c ft_lstmap.c \
	   ft_trace_i.c ft_trace_str.c ft_trace_c.c \
	   get_next_line.c ft_puterror.c ft_atod.c \

OBJNAME = $(SRCS:.c=.o)
OBJS = $(addprefix $(OBJDIR), $(OBJNAME))

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

.PHONY: clean fclean mrproper re
$(OBJS): | $(OBJDIR)

$(OBJDIR)%.o: $(SRCDIR)%.c
	 $(GCC) $(CFLAGS) -I $(HEADERS) -c $< -o $@

$(OBJDIR):
		@if [ ! -d "$(OBJDIR)" ]; then \
			mkdir $(OBJDIR);\
			fi

clean:
	rm -rf $(OBJS)
	rm -rf $(OBJDIR)

fclean: clean
	rm -rf $(NAME) 

mrproper: all clean

re: fclean all
