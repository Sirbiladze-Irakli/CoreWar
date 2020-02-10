/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 14:23:44 by cdubuque          #+#    #+#             */
/*   Updated: 2020/02/10 19:51:58 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

const t_op	g_op_tab[16] =
{
	{"live", 1, 10, "alive", 4},
	{"ld", 2, 5, "load", 4},
	{"st", 2, 5, "store", 4},
	{"add", 3, 10, "addition", 4},
	{"sub", 3, 10, "soustraction", 4},
	{"and", 3, 6, "et (and  r1, r2, r3   r1&r2 -> r3", 4},
	{"or", 3, 6, "ou  (or   r1, r2, r3   r1 | r2 -> r3", 4},
	{"xor", 3, 6, "ou (xor  r1, r2, r3   r1^r2 -> r3", 4},
	{"zjmp", 1, 20, "jump if zero", 2},
	{"ldi", 3, 25, "load index", 2},
	{"sti", 3, 25, "store index", 2},
	{"fork", 1, 800, "fork", 2},
	{"lld", 2, 10, "long load", 4},
	{"lldi", 3, 50, "long load index", 2},
	{"lfork", 1, 1000, "long fork", 2},
	{"aff", 1, 2, "aff", 4},
};
