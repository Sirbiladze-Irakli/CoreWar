
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdubuque <cdubuque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 13:12:40 by cdubuque          #+#    #+#             */
/*   Updated: 2019/11/11 13:12:40 by cdubuque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Toutes les tailles sont en octets.
** On part du principe qu'un int fait 32 bits. Est-ce vrai chez vous ?
*/

#ifndef OP_H
# define OP_H
# define IND_SIZE				2
# define REG_SIZE				4
# define DIR_SIZE				REG_SIZE


# define REG_CODE				1
# define DIR_CODE				2
# define IND_CODE				3


# define MAX_ARGS_NUMBER		4
# define MAX_PLAYERS			4
# define MEM_SIZE				(4*1024)
# define IDX_MOD				(MEM_SIZE / 8)
# define CHAMP_MAX_SIZE			(MEM_SIZE / 6)

# define COMMENT_CHAR			'#'
# define LABEL_CHAR				':'
# define DIRECT_CHAR			'%'
# define SEPARATOR_CHAR			','

# define LABEL_CHARS			"abcdefghijklmnopqrstuvwxyz_0123456789"

# define NAME_CMD_STRING		".name"
# define COMMENT_CMD_STRING		".comment"

# define REG_NUMBER				16

# define CYCLE_TO_DIE			1536
# define CYCLE_DELTA			50
# define NBR_LIVE				21
# define MAX_CHECKS				10

# define T_REG					1
# define T_DIR					2
# define T_IND					4
# define T_LAB					8

# define PROG_NAME_LENGTH		(128)
# define COMMENT_LENGTH			(2048)
# define COREWAR_EXEC_MAGIC		0xea83f3

# include "../libft/libft.h"
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include <stdarg.h>
# include <stdio.h> 												//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!	
# define BUFF_SIZE 1
# define NAME (*players)[c]->name
# define COL_PL corewar->col_play
# define ST_POI entry_point

typedef char	t_arg_type;

typedef struct		header_s
{
	unsigned int		magic;
	char				prog_name[PROG_NAME_LENGTH + 1];
	unsigned int		prog_size;
	char				comment[COMMENT_LENGTH + 1];
}					header_t;

typedef struct      s_player
{
	char			*name;
	char			player_name[PROG_NAME_LENGTH + 1];
	char			comment[COMMENT_LENGTH + 1];
	int				n;
	char			*fullname;
	int				code_size;
	int				*exec_code;
	int				entry_point;
}					t_player;

typedef struct 		s_corewar
{
	unsigned char	arena[MEM_SIZE];
	int				col_play;
	int				last_player;
	int				start_cycles;
	int				col_live;
	int				cycles_to_die;
	int				col_check;
}					t_corewar;

typedef	struct 		s_carriage
{
	int				ID;
	int				carry;
	int				op_code;
	int				cyc_live;
	int				cyc_to_live;
	int				PC;
	int				byte_jump;
	int				registrs[REG_NUMBER];
}					t_carriage;


int					get_next_line(const int fd, char **line);
/*
**main
*/
void				ft_create_players(t_player ***players, t_corewar **corewar);
/*
**errors
*/
void				error(char *s);
/*	
**input_players
*/
void				ft_champions_up(char *s, int c, t_player **players, char *s1);
void				ft_split_s(char **s);
void				ft_new_player_flag(char *s, int *c, t_player **players, char *s1);
void				ft_new_player_c(char *s, int *c, t_player **players, char *s1);
void				ft_give_number(char *s, int *c, t_player **players, int d);
/*
**validation
*/
void				ft_check_name(t_player **players, int *mas, int i, int pos);
void				ft_check_magic_header(t_player **players, int *mas);
void				ft_check_file(t_player **players, int *mas, int i);
void				ft_validation(t_player **players);
/*
**unsigned
*/
int					ft_colvo_uns(unsigned long long n, int col, int i);
char				*ft_while_uns(unsigned long long n, char *s, int h);
char				*ft_putt_uns(unsigned long long n, char *s, int i);
char				*ft_unsigned(unsigned long long n, int i);
/*
**validation_2
*/
int					ft_degree_16(int j);
int					ft_in_ten(char *s);
void				ft_exec_code(t_player **players, int *mas, int i, int pos);
void				ft_champion_comment(t_player **players, int *mas, int i, int pos);
/*
**arena
*/
void				ft_arena_exec_code(t_player **players, t_corewar *corewar);
void				ft_carriege_init(t_carriage ***carriege, t_player **players, t_corewar *corewar);
void				ft_arena(t_player **players, t_corewar *corewar);
/*
**operations
*/
void				ft_operations_2(t_carriage ***carriege, t_corewar *corewar, int i);
void				ft_operations(t_carriage ***carriege, t_corewar *corewar, int i);
/*
**operations_code_1
*/
void				ft_live(t_carriage ***carriege, t_corewar *corewar, int i);
void				ft_ld(t_carriage ***carriege, t_corewar *corewar, int i);
void				ft_st(t_carriage ***carriege, t_corewar *corewar, int i);
void				ft_add(t_carriage ***carriege, t_corewar *corewar, int i);
void				ft_sub(t_carriage ***carriege, t_corewar *corewar, int i);


#endif