# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cdubuque <cdubuque@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/25 17:31:13 by cdubuque          #+#    #+#              #
#    Updated: 2019/10/02 19:53:15 by cdubuque         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_isalpha.c	ft_memmove.c ft_strchr.c ft_strlen.c ft_strrchr.c \
	ft_atoi.c ft_isascii.c ft_memchr.c ft_strcmp.c ft_strncat.c \
	ft_strstr.c ft_bzero.c ft_isdigit.c ft_memcmp.c ft_memset.c ft_strcpy.c \
	ft_strncmp.c ft_tolower.c ft_isprint.c ft_memcpy.c ft_strdup.c \
	ft_strncpy.c ft_toupper.c ft_isalnum.c ft_memccpy.c ft_strcat.c \
	ft_strlcat.c ft_strnstr.c ft_memalloc.c ft_memdel.c ft_strnew.c \
	ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c ft_strmap.c \
	ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c \
	ft_strmapi.c ft_strsplit.c ft_itoa.c ft_putchar.c ft_putstr.c \
	ft_putendl.c ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c \
	ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c \
	ft_lstadd.c ft_lstiter.c ft_lstmap.c ft_modul.c ft_first_free_join.c \
	ft_second_free_join.c ft_free_strdup.c ft_free_sub.c ft_while_digit.c \
	ft_not_prob.c ft_vhod_elem.c ft_len_digit.c ft_modul_int.c \
	ft_modul_int_change.c ft_while_digit_plus.c ft_while_isprint.c ft_double.c \
	ft_split_free.c

FLAGS = -Wall -Wextra -Werror

HEADER = ./

OBJC = $(SRC:.c=.o)

$(NAME):
	@gcc -c $(FLAGS) $(SRC) -I./$(HEADER)
	@ar rc $(NAME) $(OBJC)

all: $(NAME)

clean:
	@rm -f $(OBJC)

fclean: clean
	@rm -f $(NAME)

re: fclean all
