/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrager <mgrager@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 16:42:28 by mgrager           #+#    #+#             */
/*   Updated: 2025/11/20 18:59:51 by mgrager          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	i;
	size_t	j;
	char	*p;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = ft_strlen(s1) + ft_strlen(s2);
	p = (char *)malloc((sizeof (char)) * (j + 1));
	if (p == 0)
		return (NULL);
	while (s1[i] != '\0')
	{
		p[i] = s1[i];
	i++;
	}
	i = 0;
	while (s2[i] != '\0')
	{
	p[i + ft_strlen(s1)] = s2[i];
	i++;
	}
	p[j] = '\0';
	return (p);
}
/*
#include <stdio.h>
int main ()
{
	char s1[7] = "ABCDEF";
	char s2[7] = "GHIJKL";
	printf("%s", ft_strjoin(s1, s2));
}
*/
