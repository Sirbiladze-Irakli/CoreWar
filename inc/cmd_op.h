/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_op.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 12:18:14 by jormond-          #+#    #+#             */
/*   Updated: 2019/11/22 12:50:03 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CMD_OP_H
# define CMD_OP_H
# include "../libft/includes/libft.h"

typedef struct	s_op
{
	char		*name;
	uint8_t		code;
	uint8_t		args_num;
	uint8_t		args_types[3];
	uint8_t		t_dir_size;		
}				t_op;

static t_op		g_ops[16] = {
	{
		.name = "live",
		.code = 0x01,
		.args_num = 1,
		.args_types = {T_DIR, 0, 0},
		.t_dir_size = 4,
	},
	{
		.name = "ld",
		.code = 0x02,
		.args_num = 2,
		.args_types = {T_DIR | T_IND, T_REG},
		.t_dir_size = 4,
	},
	{
		.name = "st",
		.code = 0x03,
		.args_num = 2,
		.args_types = {T_REG, T_IND | T_REG},
		.t_dir_size = 4,
	},
	{
		.name = "add",
		.code = 0x04,
		.args_num = 3,
		.args_types = {T_REG, T_REG, T_REG},
		.t_dir_size = 4,
	},
	{
		.name = "sub",
		.code = 0x05,
		.args_num = 3,
		.args_types = {T_REG, T_REG, T_REG},
		.t_dir_size = 4,
	},
	{
		.name = "and",
		.code = 0x06,
		.args_num = 3,
		.args_types = {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG},
		.t_dir_size = 4,
	},
	{
		.name = "or",
		.code = 0x07,
		.args_num = 3,
		.args_types = {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG},
		.t_dir_size = 4,
	},
	{
		.name = "xor",
		.code = 0x08,
		.args_num = 3,
		.args_types = {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG},
		.t_dir_size = 4,
	},
	{
		.name = "zjmp",
		.code = 0x09,
		.args_num = 1,
		.args_types = {T_DIR},
		.t_dir_size = 2,
	},
	{
		.name = "ldi",
		.code = 0x0a,
		.args_num = 1,
		.args_types = {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG},
		.t_dir_size = 2,
	},
	{
		.name = "sti",
		.code = 0x0b,
		.args_num = 3,
		.args_types = {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG},
		.t_dir_size = 2,
	},
	{
		.name = "fork",
		.code = 0x0c,
		.args_num = 1,
		.args_types = {T_DIR},
		.t_dir_size = 2,
	},
	{
		.name = "lld",
		.code = 0x0d,
		.args_num = 2,
		.args_types = {T_DIR | T_IND, T_REG},
		.t_dir_size = 4,
	},
	{
		.name = "lldi",
		.code = 0x0e,
		.args_num = 3,
		.args_types = {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG},
		.t_dir_size = 2,
	},
	{
		.name = "lfork",
		.code = 0x0f,
		.args_num = 1,
		.args_types = {T_DIR},
		.t_dir_size = 2,
	},
	{
		.name = "aff",
		.code = 0x0f,
		.args_num = 1,
		.args_types = {T_REG},
		.t_dir_size = 4,
	}
};


#endif