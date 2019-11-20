/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdubuque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 19:05:24 by cdubuque          #+#    #+#             */
/*   Updated: 2019/02/17 16:12:15 by cdubuque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*pas;
	t_list	*tmp;

	if (lst == NULL)
		return (NULL);
	if (!(pas = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (!(tmp = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (lst != NULL)
	{
		pas = (*f)(lst);
		tmp = pas;
		lst = lst->next;
	}
	while (lst)
	{
		pas->next = (*f)(lst);
		pas = pas->next;
		lst = lst->next;
	}
	return (tmp);
}
