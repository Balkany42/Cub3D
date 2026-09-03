/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrager <mgrager@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 12:29:16 by mgrager           #+#    #+#             */
/*   Updated: 2025/11/20 18:55:24 by mgrager          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (!dest && !src)
		return (dest);
	if (n == 0)
		return (dest);
	i = 0;
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
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
   	printf("%d\n", memcmp(memcpy(buf_p, buf_ft, len), 
   	ft_memcpy(buf_p, buf_ft, len), len));
}
*/
