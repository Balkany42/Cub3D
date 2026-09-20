/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrager <mgrager@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 12:22:50 by mgrager           #+#    #+#             */
/*   Updated: 2025/11/20 18:56:40 by mgrager          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
/*
#include <stdio.h>
#include <string.h>
int main()
{
	printf("%lu\n", ft_strlen("Je suis une legende"));
	printf("%lu\n", strlen("Je suis une legende"));
	printf("%lu\n", ft_strlen("0 "));
	printf("%lu\n", strlen("0 "));
	printf("%lu\n", ft_strlen(""));
	printf("%lu\n", strlen(""));
	printf("%lu\n", ft_strlen("'d'"));
	printf("%lu\n", strlen("'d'"));
	printf("%lu\n", ft_strlen("123"));
	printf("%lu\n", strlen("123"));
	printf("%lu\n", ft_strlen("111"));
	printf("%lu\n", strlen("111"));
}
*/
