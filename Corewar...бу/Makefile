# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/07 16:44:07 by cdubuque          #+#    #+#              #
#    Updated: 2019/11/18 12:44:32 by jormond-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CR = corewar

INC = ./inc/op.h

LIB = libft/libft.a

CRFILES = corewar.c errors.c input_players.c validation.c unsigned.c \
validation_2.c arena.c 

CRSRC = $(addprefix src/,$(CRFILES))

CROBJ = $(addprefix obj/,$(CRFILES:.c=.o))

#FLAGS = -Wall -Wextra -Werror

all : $(CR)

$(CR) : $(CROBJ)
	@make -C libft/
	@gcc -o $(CR) $(CROBJ) $(LIB)

obj/%.o: src/%.c $(INC)
	@mkdir -p obj/
	@gcc $(FLAGS) -Iinc -o $@ -c $<

clean :
	@make clean -C libft/
	@rm -rf obj/

fclean : clean
	@make fclean -C libft
	@rm -f $(CR)

re : fclean all
