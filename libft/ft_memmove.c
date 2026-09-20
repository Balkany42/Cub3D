/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrager <mgrager@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 12:33:39 by mgrager           #+#    #+#             */
/*   Updated: 2025/11/20 19:09:55 by mgrager          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (dest == NULL && src == NULL)
		return (dest);
	if (dest < src)
	{
		while (i < n)
		{
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	else
	{
		while (n > 0)
		{
			n--;
			((unsigned char *)dest)[n] = ((unsigned char *)src)[n];
		}
	}
	return (dest);
}
/*
#include <string.h>
#include <stdio.h>
int main ()
{
	char buf_ft[20] = "";
	char buf_p[20] = "";
	int len;
	len = 20;
   	printf("%d\n", memcmp(memmove(buf_p, buf_ft, len), 
   	ft_memmove(buf_p, buf_ft, len), len));
}
*/
