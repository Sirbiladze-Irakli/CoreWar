/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/06 14:44:35 by zaz               #+#    #+#             */
/*   Updated: 2020/01/22 16:26:14 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


// t_op    op_tab[17] =
// {
// 	{0,0,{0},0,0},
// 	{"live", 1, {T_DIR}, 1, 4},
// 	{"ld", 2, {T_DIR | T_IND, T_REG}, 2, 4},
// 	{"st", 2, {T_REG, T_IND | T_REG}, 3, 0},
// 	{"add", 3, {T_REG, T_REG, T_REG}, 4, 0},
// 	{"sub", 3, {T_REG, T_REG, T_REG}, 5, 0},
// 	{"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 4},
// 	{"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 4},
// 	{"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 4},
// 	{"zjmp", 1, {T_DIR}, 9, 2},
// 	{"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 2},
// 	{"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 2},
// 	{"fork", 1, {T_DIR}, 12, 2},
// 	{"lld", 2, {T_DIR | T_IND, T_REG}, 13, 4},
// 	{"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 2},
// 	{"lfork", 1, {T_DIR}, 15, 1000, 2},
// 	{"aff", 1, {T_REG}, 16, 2, 0}
// };
