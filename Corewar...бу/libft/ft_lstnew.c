/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdubuque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 18:44:32 by cdubuque          #+#    #+#             */
/*   Updated: 2018/12/26 19:49:15 by cdubuque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*sl;

	if (!(sl = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (content == NULL)
	{
		sl->content = NULL;
		sl->content_size = 0;
	}
	else
	{
		if (!(sl->content = (size_t *)malloc(sizeof(content_size))))
			return (NULL);
		if (content == NULL)
		{
			free(sl);
			return (NULL);
		}
		sl->content_size = content_size;
		ft_memcpy(sl->content, content, content_size);
	}
	sl->next = NULL;
	return (sl);
}
