/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrager <mgrager@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 16:45:05 by mgrager           #+#    #+#             */
/*   Updated: 2025/11/22 15:56:54 by mgrager          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len_src;
	size_t	len_dst;

	len_src = ft_strlen(src);
	len_dst = ft_strlen(dst);
	i = 0;
	if (size <= len_dst)
		return (len_src + size);
	while (src[i] != '\0' && i < size - len_dst - 1)
	{
		dst[i + len_dst] = src[i];
		i++;
	}
	dst[i + len_dst] = '\0';
	return (len_src + len_dst);
}
/*
#include <stdio.h>
#include <string.h>
int main()
{
	char src1[12];
	char dst1[12];
	size_t i;
	i = 6;
	
	src = "AAAAAA";
	dst = "BBBBBB";
	//printf("%zu\n", strlcat (dst, src, i));
	printf("%zu\n", ft_strlcat (dst, src, i));
	src = "BBBBBB";
	dst = "AAAAAA";
	//printf("%zu\n", strlcat (dst, src, i));
	printf("%zu\n", ft_strlcat (dst, src, i));
	src = "BBBBBB";
	dst = "AAAAAA";
	//printf("%zu\n", strlcat (dst, src, i));
	printf("%zu\n", ft_strlcat (dst, src, i));
	src = "BBB";
	dst = "AAA";
	//printf("%zu\n", strlcat (dst, src, i));
	printf("%zu\n", ft_strlcat (dst, src, i));
	src = "BBBBBBBBB";
	dst = "AAAAAAAAA";
	//printf("%zu\n", strlcat (dst, src, i));
	printf("%zu\n", ft_strlcat (dst, src, i));
	src = "";
	dst = "";
	//printf("%zu\n", strlcat (dst, src, i));
	printf("%zu\n", ft_strlcat (dst, src, i));
}
*/
