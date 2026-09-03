/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrager <mgrager@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 16:04:06 by mgrager           #+#    #+#             */
/*   Updated: 2025/11/20 18:54:55 by mgrager          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*p;
	t_list	*q;

	p = *lst;
	if (!*lst)
		return ;
	while (p)
	{
		q = p->next;
		del(p->content);
		free(p);
		p = q;
	}
	*lst = NULL;
}
