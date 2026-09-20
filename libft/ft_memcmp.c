/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrager <mgrager@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 20:03:41 by mgrager           #+#    #+#             */
/*   Updated: 2025/11/20 18:55:19 by mgrager          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && ((unsigned char *)s1)[i] == ((unsigned char *)s2)[i])
		i++;
	if (i == n)
		return (0);
	return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
}
/*
#include <string.h>
#include <stdio.h>
int main ()
{
	const char *str1 = "9876543210";
	const char *str2 = "987654321";
	printf("%d\n", memcmp(str1, str2, 10));
	printf("%d\n", ft_memcmp(str1, str2, 10));
	printf("%d\n", memcmp(str1, str2, 9));
	printf("%d\n", ft_memcmp(str1, str2, 9));
	printf("%d\n", memcmp(str2, str1, 10));
	printf("%d\n", ft_memcmp(str2, str1, 10));
	printf("%d\n", memcmp(str1, str1, 9));
	printf("%d\n", ft_memcmp(str1, str2, 9));
}
*/
