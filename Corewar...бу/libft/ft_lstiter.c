/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdubuque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 18:06:52 by cdubuque          #+#    #+#             */
/*   Updated: 2018/12/27 19:35:03 by cdubuque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	if (!lst || !f)
		return (NULL);
	while (lst)
	{
		f(lst);
		lst = lst->next;
	}
	return (NULL);
}
