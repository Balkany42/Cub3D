/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrager <mgrager@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 19:46:23 by mgrager           #+#    #+#             */
/*   Updated: 2025/11/20 18:55:15 by mgrager          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*ptr = s;

	i = 0;
	ptr = s;
	if (n <= i)
		return (0);
	while (i < n)
	{
		if (ptr[i] == (unsigned char)c)
			return ((unsigned char *)s + i);
		i++;
	}
	return (NULL);
}
/*
#include <string.h>
#include <stdio.h>
int main ()
{
	const char *str1 = "9876543210";
	const char *str2 = "987654321";
	printf("%p\n", memchr(str1, 48, 10));
	printf("%p\n", ft_memchr(str1, 48, 10));
	printf("%p\n", memchr(str1, 48, 9));
	printf("%p\n", ft_memchr(str1, 48, 9));
	printf("%p\n", memchr(str2, 48, 10));
	printf("%p\n", ft_memchr(str2, 48, 10));
	printf("%p\n", memchr(str1, 48, 10));
	printf("%p\n", ft_memchr(str1, 48, 10));
}
*/
