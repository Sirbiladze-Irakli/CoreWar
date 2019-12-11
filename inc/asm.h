/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 18:15:30 by jormond-          #+#    #+#             */
/*   Updated: 2019/12/11 19:13:45 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	OP_H
# define OP_H
# define TOKEN corewar->tokens
# define LIVE 0x01
# define LD 0x02
# define ST 0x03
# define ADD 0x04
# define SUB 0x05
# define AND 0x06
# define OR 0x07
# define XOR 0x08
# define ZJMP 0x09
# define LDI 0x0a
# define STI 0x0b
# define FORK 0x0c
# define LLD 0x0d
# define LLDI 0x0e
# define LFORK 0x0f
# define AFF 0x10
# define LABEL 1
# define INSTRUCTION 2
# define REGISTER 3
# define SEPARATOR 4
# define DIRECT 5
# define DIRECT_LABEL 6
# define BUFF_SIZE 7
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include "op.h"
# include "cmd_op.h"
// # include "../libft/includes/libft.h"

typedef struct	s_ls
{
	char		*token;
	int			label;
	struct s_ls	*next;
}				t_ls;


typedef struct	s_cw
{
	t_ls		*tokens;
	char		*bytecode;
	char		*file;
	char		*line;
	void		*hex;
	char		*inname;
	char		*incomment;
	char		*incommands;
	int			ret;
	int			in;
	int			eline;
	int			esym;
	int			pos;
	int			name;
	int			comment;
}				t_cw;

/*
** main.c
*/

void			init_struct(t_cw *corewar);
void			output(char *str);
void			error_out(t_cw *corewar, int var);
void			errors(t_cw *corewar, int var, int shift);

/*
** get_next_line.c
*/

int				get_next_line(const int fd, char **line);

/*
** arg_reader.c
*/

void			s_reader(t_cw *corewar, char *av);
void			valid_arg(t_cw *corewar, char *av);
void			cor_reader(t_cw *corewar, char *av);
void			read_line(int fd, char **line);

/*
** tools.c
*/

char			*ft_itoa_base(int value, int base);
void			skip_spaces(t_cw *corewar, int *i);
int				separators(char c);

/*
** s_compiler.c
*/

void			s_compiler(t_cw *corewar, char *av);

/*
** fill_magic_header.c
*/

void			fill_magic_header(t_cw *corewar, int out);

/*
** take_tokens.c
*/

void			take_tokens(t_cw *corewar);
void			parse_tokens(t_cw *corewar);
void            name_and_comment(t_cw *corewar);
void			fill_name_and_comment(t_cw *corewar, int *i);
void			token_in_quotes(t_cw *corewar, int *i);
void			dot_label(t_cw *corewar, int *i);

/*
** read_and_write.c
*/

void			read_name(t_cw *corewar);

/*
** parse.c
*/

void			parse(t_cw *corewar);
void			add_token(t_cw *corewar, int *i);

/*
** add_node.c
*/

t_ls			*add_node(t_cw *corewar);
t_ls			*init_list(t_cw *corewar);
t_ls			*add_new_node(t_cw *corewar);
t_ls			*last_node(t_cw *corewar);
void			prepare_node(t_cw *corewar);

#endif
