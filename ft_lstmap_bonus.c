/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhecquet <hhecquet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 12:07:57 by hhecquet          #+#    #+#             */
/*   Updated: 2024/11/12 17:26:49 by hhecquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	void	*temp;
	t_list	*list;
	t_list	*node;

	list = NULL;
	while (lst)
	{
		temp = f(lst->content);
		if (!temp)
		{
			ft_lstclear(&list, del);
			return (NULL);
		}
		node = (ft_lstnew(temp));
		if (!node)
		{
			del(temp);
			ft_lstclear(&list, del);
			return (NULL);
		}
		ft_lstadd_back(&list, node);
		lst = lst->next;
	}
	return (list);
}
