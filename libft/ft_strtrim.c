/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrager <mgrager@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 17:17:31 by mgrager           #+#    #+#             */
/*   Updated: 2025/11/22 15:55:06 by mgrager          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_cut(const char *set, char c);
static char	*ft_trim2(size_t beg, size_t end, const char *s1);

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	beg;
	size_t	end;
	size_t	len;
	char	*p;

	len = ft_strlen(s1);
	if (len == 0)
		return (ft_trim2(1, 0, s1));
	beg = 0;
	end = len - 1;
	while (ft_cut(set, s1[beg]))
		beg++;
	while (ft_cut(set, s1[end]) && end > 0)
		end--;
	p = ft_trim2(beg, end, s1);
	return (p);
}

static char	*ft_trim2(size_t beg, size_t end, const char *s1)
{
	size_t	i;
	size_t	size;
	char	*p;

	i = 0;
	if (beg > end)
		size = 0;
	else
		size = end - beg + 1;
	p = (char *)malloc(sizeof(char) * (size + 1));
	if (p == 0)
		return (NULL);
	while (i < size)
	{
		p[i] = s1[beg];
		i++;
		beg++;
	}
	p[i] = '\0';
	return (p);
}

static int	ft_cut(const char *set, char c)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}
/*
#include <stdio.h>

int	main(void)
{
	char	s1[13] = "AABBGGGGBBAA";
	char	set[3] = "AB";

	printf("%s", ft_strtrim(s1, set));
}
*/
