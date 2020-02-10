/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 18:15:30 by jormond-          #+#    #+#             */
/*   Updated: 2020/02/10 20:17:03 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H
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
# define INDIRECT_LABEL 107
# define INDIRECTION 108
# define INSTRUCTION 109
# define DOTNAME 29
# define LEXICAL 400
# define NAME_ERROR 401
# define COMMENT_ERROR 402
# define END_LINE_ERROR 403
# define ARG_NUM_ERROR 404
# define SEPARATOR_ERROR 405
# define LABEL_PATTERN "^[0-9a-z_]+:$"
# define T_REG_PATTERN "^r[0-9]{1,2}$"
# define T_DIR_PATTERN "^%-?0*[0-9]+$"
# define T_DIR_LABEL_PATTERN "^%:[0-9a-z_]+$"
# define T_IND_PATTERN "^-?[0-9]+$"
# define T_IND_LABEL_PATTERN "^:[0-9a-z_]+$"

# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <fcntl.h>
# include <regex.h>
# include "../ft_printf/includes/ft_printf.h"
# include "op.h"

typedef struct	s_ls
{
	char		*token;
	int			label;
	int			curpos;
	int			head;
	int			instrbytes;
	int			args;
	int			pos;
	struct s_ls	*next;
	struct s_ls *prev;
}				t_ls;

typedef struct	s_cw
{
	t_ls		*tokens;
	t_ls		*instruct;
	t_ls		*startnode;
	char		*bytecode;
	char		**labels;
	char		*line;
	char		*inname;
	char		lastinstr[10];
	char		lastarg[30];
	int			res;
	int			labelpos;
	int			skip;
	int			iter;
	int			bytes;
	int			typecode;
	int			dir;
	int			in;
	int			counter;
	int			eline;
	int			name;
	int			comment;
	int			esym;
}				t_cw;

typedef struct	s_parse
{
	int			i;
	int			j;
	short		quotes;
	int			first_dot:2;
	int			name:7;
	int			comment:7;
	int			commas:4;
	int			comflag:2;
	int			countargs:4;
	int			args;
	int			order;
}				t_parse;

typedef struct	s_asm
{
	char		*instr;
	int			arg_num;
	int			order;
	int			dir_size;
	char		args[3];
}				t_asm;

/*
** asm.c
*/

void			init_struct(t_cw *corewar);
void			output(char *str);
void			error_out(t_cw *corewar, int var);
void			errors(t_cw *corewar, int var, int shift);

/*
** arg_reader.c
*/

void			take_tokens(t_cw *corewar);
void			s_reader(t_cw *corewar, char *av);
void			read_line(int fd, char **line);

/*
** tools.c
*/

void			evaluate_instruction(t_cw *corewar, char *token);
int				dir_size(t_ls *tmp);
void			skip_spaces(t_cw *corewar, int *i);
void			skip_separators(t_cw *corewar, int *i);

/*
** tools2.c
*/

int				separators(char c);
void			check_comment(t_ls *tmp);
void			check_name(t_ls *tmp);
int				substrncmp(char *dest, char *find, int begin, int n);

/*
** tools3.c
*/

int				wtf(t_ls *list);

/*
** s_compiler.c
*/

void			s_compiler(t_cw *corewar, char *av);
void			define_types(t_cw *corewar, int out, t_ls *list);
void			champ_exec_code_size(t_cw *corewar);
void			instr_len(t_cw *corewar, t_ls *tmp);
void			arg_len(t_cw *corewar, t_ls *tmp);

/*
** fill_magic_header.c
*/

void			fill_magic_header(int out);
void			fill_name(t_cw *corewar, int out);
void			fill_null(int out);
void			champ_size(t_cw *corewar, int out);
void			fill_comment(t_cw *corewar, int out);

/*
** read_and_write.c
*/

t_ls			*find_label(t_cw *corewar, t_ls *list, int begin);
int				calc_range(t_ls *list, t_ls *tmp);
void			read_name(t_cw *corewar);
int				codetype(t_ls *tmp);
void			count_args(t_cw *corewar, t_ls *tmp);

/*
** parse.c
*/

void			parse(t_cw *corewar);
void			init_parser(t_parse *parser);
void			first_part_parse(t_cw *corewar, t_parse *parser, int *i);
void			command(t_cw *corewar, t_parse *parser, int *i);
void			fill_commands(t_cw *corewar, t_parse *parser, int *i);

/*
** add_node.c
*/

t_ls			*add_node(t_cw *corewar);
t_ls			*init_list(t_cw *corewar);
void			add_new_node(t_ls **tmp);
t_ls			*last_node(t_cw *corewar);

/*
** add_token.c
*/

void			add_token(t_cw *corewar, int *i);
void			define_labels(t_cw *corewar);
void			fill_label(t_ls *tmp);
void			fill_label2(t_ls *tmp);
void			how_many_args(t_cw *corewar, t_ls *tmp);

/*
** champ_code.c
*/

void			champ_code(t_cw *corewar, int out, t_ls *list);
void			arg_types_fill(t_cw *corewar, t_ls *list, uint8_t *type);
void			reg_fill(t_cw *corewar, uint8_t *type);
void			dir_fill(t_cw *corewar, uint8_t *type);
void			ind_fill(t_cw *corewar, uint8_t *type);

/*
** write_arg.c
*/

void			write_reg(int out, t_ls *list);
void			write_dir(t_cw *corewar, int out, t_ls *list);
void			write_ind(int out, t_ls *list);
void			write_dir_lab(t_cw *corewar, int out, t_ls *list);
void			write_ind_lab(t_cw *corewar, int out, t_ls *list);

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
void			circle_closure(t_cw *corewar);

/*
** errors_out.c
*/

void			errors_out(t_cw *corewar, int flag);
void			error_vars(t_cw *corewar, char *str, int flag);
void			ft_errors(t_cw *corewar);
void			empty_separator(t_cw *corewar, t_ls *tmp);
void			check_eof(t_cw *corewar);

/*
** bad_line.c
*/

void			bad_line(t_cw *corewar, int *i);
void			before_new_line(t_cw *corewar, int *i);
void			check_str(t_cw *corewar, char *str);

/*
** write_anything.c
*/

void			write_anything(t_cw *corewar, int *i);

/*
** second_part_parse.c
*/

void			second_part_parse(t_cw *corewar, t_parse *parser, int *i);
void			space_check(t_cw *corewar, t_parse *parser, int *i);
void			separator_check(t_cw *corewar, t_parse *parser, int *i);
void			compare_labels(t_cw *corewar, t_parse *parser);
void			compare(t_cw *corewar, t_parse *parser, t_ls *arg);

/*
** who_is_who.c
*/

void			who_is_who(t_cw *corewar, t_parse *parser, int *i);
void			define_str(t_cw *corewar, t_parse *parser, char *str);
int				tab(char *str);
void			check_instr(t_cw *corewar, t_parse *parser, int *i);
void			check_label(t_cw *corewar, char *str);

/*
** process_instr.c
*/

void			process_instr(t_cw *corewar, t_parse *parser, char *str);
void			instr_arg(t_cw *corewar, t_parse *parser, char *str);
int				count_bytes(int j);
void			wrong_instr(t_ls *tmp, char *str);

/*
** ft_strtrim_free.c
*/

void			ft_strtrim_free(char **str);

/*
** right_arg.c
*/

void			right_arg(t_cw *corewar, t_parse *parser, t_ls *tmp, char *str);
void			first(t_cw *corewar, t_ls *tmp, char *str);
void			second(t_cw *corewar, t_ls *tmp, char *str);
void			third(t_cw *corewar, t_ls *tmp, char *str);
void			distrib(t_ls *tmp, char *str, char flag);

/*
** right_arg2.c
*/

void			distrib2(t_ls *tmp, char *str, char flag);
int				check_reg(t_ls *tmp, char *str);
int				check_dir(t_ls *tmp, char *str);
int				check_ind(t_ls *tmp, char *str);

extern t_asm	g_asm_tab[17];

#endif
