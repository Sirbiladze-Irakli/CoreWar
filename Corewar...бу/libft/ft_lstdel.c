/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdubuque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 18:58:23 by cdubuque          #+#    #+#             */
/*   Updated: 2018/12/26 22:11:06 by cdubuque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*pas;

	if (alst == NULL)
		return ;
	while (*alst)
	{
		pas = (*alst)->next;
		ft_lstdelone(alst, del);
		*alst = pas;
	}
}
