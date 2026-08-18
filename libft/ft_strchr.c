/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrager <mgrager@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 14:50:20 by mgrager           #+#    #+#             */
/*   Updated: 2025/11/20 18:56:12 by mgrager          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	c = c % 256;
	i = 0;
	while (s[i] || s[i] == c)
	{
		if (s[i] == c)
			return ((char *)s + i);
		i++;
	}
	return (NULL);
}
/*
#include <stdio.h>
int main()
{
	char *p = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int c = 'A';
	printf("%s\n", ft_strchr(p, c));
	c = 'Z';
	printf("%s\n", ft_strchr(p, c));
	c = 'U';
	printf("%s\n", ft_strchr(p, c));
	c = 'A';
	printf("%s\n", ft_strchr(p, c));
}
*/
