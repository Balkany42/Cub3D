/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrager <mgrager@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 14:23:42 by mgrager           #+#    #+#             */
/*   Updated: 2025/11/20 18:56:16 by mgrager          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*str;
	size_t	len;

	len = ft_strlen(s) + 1;
	str = malloc(len * sizeof(char));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s, len);
	return (str);
}
/*
#include <stdio.h>
int main()
{
	char *p;
	p = "AAAAAAAAAAAA";
	printf("%s\n", ft_strdup(p));
}
*/
