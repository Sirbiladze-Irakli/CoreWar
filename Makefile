# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/12 15:03:28 by jormond-          #+#    #+#              #
#    Updated: 2019/11/12 15:30:50 by jormond-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ASM = asm

INC = ./inc/op.h

# FLAGS = -Wall -Wextra -Werror

ASMFILES = main.c arg_reader.c

ASMSRC = $(addprefix asmsrc/,$(ASMFILES))

ASMOBJ = $(addprefix asmobj/,$(ASMFILES:.c=.o))

all : $(ASM)

$(ASM) : $(ASMOBJ)
	@gcc -o $(ASM) $(ASMOBJ)

asmobj/%.o: asmsrc/%.c $(INC)
	@mkdir -p asmobj/
	@gcc $(FLAGS) -Iinc -o $@ -c $<

clean :
	@make clean -C libft/
	@rm -rf obj/

fclean : clean
	@make fclean -C libft
	@rm -f $(ASM)
