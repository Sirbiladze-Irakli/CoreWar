/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 16:21:26 by jormond-          #+#    #+#             */
/*   Updated: 2019/11/22 18:25:06 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void			add_node(t_cw *corewar)
{
	t_ls		*tmp;

	tmp = TOKEN;
	if (!(TOKEN))
		init_list(corewar);
	else
	{
		while (TOKEN)
			TOKEN = TOKEN->next;
		add_new_node(corewar, TOKEN);
	}
	TOKEN = tmp;
	
}

void			init_list(t_cw *corewar)
{
	if (!(TOKEN = (t_ls *)malloc(sizeof(t_ls))))
		output("Can't allocate a memory");
	TOKEN->next = NULL;
	if (!(TOKEN->token = (char *)malloc(sizeof(char) * 256)))
		output("Can't allocate a memory");
	TOKEN->label = 0;
}

void			add_new_node(t_cw *corewar, t_ls *list)
{
	if(!(list = (t_ls *)malloc(sizeof(t_ls))))
		output("Can't allocate a memory");
	list->next = NULL;
	if (!(list->token = (char *)malloc(sizeof(char) * 256)))
		output("Can't allocate a memory");
	list->label = 0;
}

t_ls			*last_node(t_cw *corewar)
{
	t_ls		*tmp;

	tmp = TOKEN;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

void			prepare_node(t_cw *corewar, t_ls **tmp)
{
	add_node(corewar);
	(*tmp) = last_node(corewar);
}
