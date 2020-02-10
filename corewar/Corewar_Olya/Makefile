# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/07 16:44:07 by cdubuque          #+#    #+#              #
#    Updated: 2020/02/10 18:33:14 by jormond-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CR = corewar

INC = ./inc/op.h

PRINTF = ft_printf/libftprintf.a

NCURS = -lncurses

CRFILES = corewar.c errors.c input_players.c validation.c create.c disasm.c \
validation_2.c arena.c operations.c operations_code_1.c operations_code_2.c \
operations_code_3.c operations_code_4.c tools.c lets_go_war.c tools2.c op.c \
tools3.c unsigned.c

CRSRC = $(addprefix src/,$(CRFILES))

CROBJ = $(addprefix obj/,$(CRFILES:.c=.o))

FLAGS = -Wall -Wextra -Werror

all : $(CR)

$(CR) : $(CROBJ)
	@make -C ft_printf/
	@gcc -o $(CR) $(CROBJ) $(PRINTF) $(NCURS)

obj/%.o: src/%.c $(INC)
	@mkdir -p obj/
	@gcc $(FLAGS) -Iinc -o $@ -c $<

clean :
	@make clean -C ft_printf
	@rm -rf obj/

fclean : clean
	@make fclean -C ft_printf
	@rm -f $(CR)

re : fclean all
