/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 18:15:30 by jormond-          #+#    #+#             */
/*   Updated: 2020/01/22 17:28:18 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	OP_H
# define OP_H
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
# define LABEL 103
# define COMMAND_NAME 101
# define NAME 28
# define COMMAND_COMMENT 102
# define COMMENT 27
# define DIRECT_LABEL 104
# define DIRECT 105
# define REGISTER 106
# define INSTRUCTION 107
# define DOTNAME 29
# define LEXICAL 400
# define NAME_ERROR 401
# define COMMENT_ERROR 402
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include "../ft_printf/includes/ft_printf.h"
# include "op.h"
// # include "cmd_op.h"

typedef struct	s_ls
{
	char		*token;
	int			label;
	int         curpos;
	int         head;
	int         instrbytes;
	int         args;
	struct s_ls	*next;
	struct s_ls *prev;
}				t_ls;

typedef struct	s_cw
{
	t_ls		*tokens;
	t_ls        *instruct;
	t_ls        *startnode;
	char		*bytecode;
	char		*line;
	char		*inname;
	char        *incommands;
	char        *incomment;
	int			res;
	int         labelpos;
	int         skip;
	int         iter;
	int         bytes;
	int         typecode;
	int         dir;
	int			in;
	int         counter;
	int			eline;
	int			name;
	int			comment;
	int			esym;
}				t_cw;

typedef struct	s_parse
{
	int			i;
	short		quotes;
	int			first_dot:2;
	int			name:7;
	int			comment:7;
}				t_parse;


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

int             dir_size(t_ls *tmp);
void            evaluate_instruction(t_cw *corewar, char *token);
void			skip_spaces(t_cw *corewar, int *i);
int				separators(char c);
void			new_line(t_cw *corewar);

/*
** s_compiler.c
*/

void			s_compiler(t_cw *corewar, char *av);

/*
** fill_magic_header.c
*/

void			fill_magic_header(t_cw *corewar, int out);
void            fill_name(t_cw *corewar, int out);
void            fill_null(int out);
void            champ_size(t_cw *corewar, int out);
void            fill_comment(t_cw *corewar, int out);

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
int             codetype(t_ls *tmp);
void            count_args(t_cw *corewar, t_ls *tmp);

/*
** parse.c
*/

void			parse(t_cw *corewar);
void			init_parser(t_parse *parser);
void			first_part_parse(t_cw *corewar, t_parse *parser, int *i);
void			command(t_cw *corewar, t_parse *parser, int *i);
void			fill_commands(t_cw *corewar, t_parse *parser, int *i);
//void			add_token(t_cw *corewar, int *i);

/*
** add_node.c
*/

t_ls			*add_node(t_cw *corewar);
t_ls			*init_list(t_cw *corewar);
void			add_new_node(t_cw *corewar, t_ls **tmp);
t_ls			*last_node(t_cw *corewar);
void			prepare_node(t_cw *corewar);

/*
** add_token.c
*/

void            add_token(t_cw *corewar, int *i);
void            define_labels(t_cw *corewar);
void            fill_label(t_cw *corewar, t_ls *tmp);
void            fill_label2(t_cw *corewar, t_ls *tmp);
void            how_many_args(t_cw *corewar, t_ls *tmp);

/*
** champ_code.c
*/

void            champ_code(t_cw *corewar, int out, t_ls *list);
void            define_types(t_cw *corewar, t_ls *tmp, uint8_t *type);
void            reg_fill(t_cw *corewar, uint8_t *type);
void            dir_fill(t_cw *corewar, uint8_t *type);
void            ind_fill(t_cw *corewar, uint8_t *type);

/*
** write_arg.c
*/

void            write_args(t_cw *corewar, int out, t_ls *tmp);
void            first_two_args(t_cw *corewar, int out, t_ls *tmp);
void            write_dir(t_cw *corewar, int out, t_ls *tmp);
void            third_arg(t_cw *corewar, int out, t_ls *tmp);
void            jump_lenght(t_cw *corewar, t_ls *tmp, char *label, int out);

/*
** third_arg.c
*/

void            third_arg(t_cw *corewar, int out, t_ls *tmp);
void            write_in_file(t_cw *corewar, int res, int out);

/*
** disassembler.c
*/

void            disassembler(t_cw *corewar, char *av);

/*
** errors.c
*/



/*
** ft_join_char_free.c
*/

void			ft_join_char_free(char **content, char c);

/*
** compare_val.c
*/

void			compare_val(t_cw *corewar, t_parse *parser,
					char *line, int *i);
void			command_val(t_cw *corewar, t_ls *tmp, t_parse *parser, int *i);

/*
** ErrorOut.c
*/

void            ErrorOut(t_cw *corewar, t_parse *parser, int flag);

/*
** bad_line.c
*/

void			bad_line(t_cw *corewar, t_parse *parser, int *i);
void			before_new_line(t_cw *corewar, t_parse *parser, int *i);
void			check_str(t_cw *corewar, t_parse *parser, char *str);

// extern t_op		op_tab[17];

#endif
