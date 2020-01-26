# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/12 15:03:28 by jormond-          #+#    #+#              #
#    Updated: 2020/01/26 18:04:08 by jormond-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ASM = asm

INC = ./inc/op.h ./inc/asm.h ./inc/cmd_op.h

LIB = ft_printf/libftprintf.a

# FLAGS = -Wall -Wextra -Werror

ASMFILES = asm.c arg_reader.c s_compiler.c fill_magic_header.c tools.c \
			take_tokens.c get_next_line.c read_and_write.c parse.c add_node.c \
			add_token.c champ_code.c write_args.c third_arg.c errors.c \
			ft_join_char_free.c compare_val.c ErrorOut.c bad_line.c op.c \
			write_anything.c second_part_parse.c who_is_who.c process_instr.c

ASMSRC = $(addprefix asmsrc/,$(ASMFILES))

ASMOBJ = $(addprefix asmobj/,$(ASMFILES:.c=.o))

all : $(ASM)

$(ASM) : $(ASMOBJ)
	@make -C ft_printf/
	@gcc -o $(ASM) $(ASMOBJ) $(LIB)

asmobj/%.o: asmsrc/%.c $(INC)
	@mkdir -p asmobj/
	@gcc $(FLAGS) -Iinc -o $@ -c $<

clean :
	@make clean -C ft_printf/
	@rm -rf obj/

fclean : clean
	@make fclean -C ft_printf
	@rm -f $(ASM)
re : fclean all
