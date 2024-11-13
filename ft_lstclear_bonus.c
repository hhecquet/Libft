/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhecquet <hhecquet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 11:39:16 by hhecquet          #+#    #+#             */
/*   Updated: 2024/11/12 11:58:44 by hhecquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*elst;

	if (del && lst && *lst)
	{
		while (lst && *lst)
		{
			elst = (*lst)->next;
			ft_lstdelone(*lst, del);
			*lst = elst;
		}
	}
}
