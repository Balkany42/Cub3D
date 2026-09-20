/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrager <mgrager@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 17:30:28 by mgrager           #+#    #+#             */
/*   Updated: 2025/11/20 18:59:27 by mgrager          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	total_size;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	j = 0;
	i = ft_strlen(s);
	if (start > i)
		total_size = 0;
	else if (i < (start + len))
		total_size = i - start;
	else
		total_size = len;
	p = (char *)malloc((sizeof (char)) * (total_size + 1));
	if (p == 0)
		return (NULL);
	while (j < total_size)
	{
		p[j] = s[j + start];
		j++;
	}
	p[j] = '\0';
	return (p);
}
/*
#include <stdio.h>
int main()
{
	char str[13] = "ABCDEFGHIJKL";
	int start;
	int len;
	
	start = 55;
	len = 2;
	printf("%s", ft_substr(str, start, len));
}
*/
