/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrager <mgrager@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 16:10:03 by mgrager           #+#    #+#             */
/*   Updated: 2025/11/20 18:55:07 by mgrager          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*p;
	t_list	*q;
	void	*temp;

	if (!lst || !f || !del)
		return (NULL);
	p = NULL;
	q = NULL;
	temp = NULL;
	while (lst)
	{
		temp = (f(lst->content));
		q = ft_lstnew(temp);
		if (!q)
		{
			del(temp);
			ft_lstclear(&p, del);
			return (NULL);
		}
		ft_lstadd_back(&p, q);
		lst = lst->next;
	}
	return (p);
}
