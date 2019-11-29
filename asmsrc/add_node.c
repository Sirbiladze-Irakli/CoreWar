/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 16:21:26 by jormond-          #+#    #+#             */
/*   Updated: 2019/11/29 17:46:04 by jormond-         ###   ########.fr       */
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
		while (tmp)
			tmp = tmp->next;
		tmp = add_new_node(corewar);
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

t_ls			*add_new_node(t_cw *corewar)
{
	t_ls	*list;
	
	if(!(list = (t_ls *)malloc(sizeof(t_ls))))
		output("Can't allocate a memory");
	if (!(list->token = (char *)malloc(sizeof(char) * 256)))
		output("Can't allocate a memory");
	list->next = NULL;
	list->label = 0;
	return (list);
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
