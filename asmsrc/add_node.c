/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 16:21:26 by jormond-          #+#    #+#             */
/*   Updated: 2019/12/11 19:18:57 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_ls			*add_node(t_cw *corewar)
{
	t_ls		*tmp;

	tmp = TOKEN;
	if (!(tmp))
		tmp = init_list(corewar);
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		add_new_node(corewar, &(tmp->next));
        return (tmp->next);
	}
	return (tmp);
}

t_ls			*init_list(t_cw *corewar)
{
	t_ls	*list;

	if (!(list = (t_ls *)malloc(sizeof(t_ls))))
		output("Can't allocate a memory");
	if (!(list->token = (char *)malloc(sizeof(char) * 256)))
		output("Can't allocate a memory");
	list->next = NULL;
	list->label = 0;
	TOKEN = list;
	return (list);
}

void			*add_new_node(t_cw *corewar, t_ls **tmp)
{
	if(!((*tmp) = (t_ls *)malloc(sizeof(t_ls))))
		output("Can't allocate a memory");
	if (!((*tmp)->token = (char *)malloc(sizeof(char) * 256)))
		output("Can't allocate a memory");
	(*tmp)->next = NULL;
	(*tmp)->label = 0;
}

t_ls			*last_node(t_cw *corewar)
{
	t_ls		*tmp;

	tmp = TOKEN;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

// void			prepare_node(t_cw *corewar)
// {
// 	add_node(corewar);
// }
