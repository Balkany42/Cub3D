/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrager <mgrager@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 14:59:21 by mgrager           #+#    #+#             */
/*   Updated: 2025/11/20 18:58:51 by mgrager          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;

	c = c % 256;
	i = 0;
	while (s[i] != '\0')
		i++;
	while (1)
	{
		if (s[i] == c)
			return ((char *)s + i);
		if (i == 0)
			break ;
		i--;
	}
	return (NULL);
}
/*
#include <stdio.h>
#include <string.h>
int main ()
{
	size_t c;
	c = 67;
	char str[12] = "ABCDEFGHIJK";
	
	printf("%s\n", ft_strrchr(str, c));
	printf("%s\n", strrchr(str, c));
}
*/
