/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrager <mgrager@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 19:40:00 by mgrager           #+#    #+#             */
/*   Updated: 2025/11/20 18:54:22 by mgrager          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t			i;
	unsigned char	*p;

	i = 0;
	if (nmemb > 0 && size > ((size_t) - 1) / nmemb)
		return (NULL);
	p = malloc(nmemb * size);
	if (p == 0)
		return (NULL);
	while (i < nmemb * size)
	{
		p[i] = '\0';
		i++;
	}
	return ((void *)p);
}
/*
#include <stdlib.h>
int main ()
{
	ft_calloc(10, 10);
}
*/
