/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrager <mgrager@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 19:33:15 by mgrager           #+#    #+#             */
/*   Updated: 2025/11/20 19:49:51 by mgrager          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	result;
	int	signe;

	i = 0;
	result = 0;
	signe = 1;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\r'
		|| str[i] == '\v' || str[i] == '\f')
		i++;
	if (str[i] == '-')
	{
		i++;
		signe = -signe;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] != '\0' && str[i] <= '9' && str[i] >= '0')
	{
		result = (result * 10) + (str[i] - 48);
		i++;
	}
	result = result * signe;
	return (result);
}
/*
#include <stdio.h>
#include <stdlib.h>

int main ()
{
	printf("%d\n", ft_atoi("1971"));
	printf("%d\n", atoi("1971"));
	printf("%d\n", ft_atoi("-1971"));
	printf("%d\n", atoi("-1971"));
	printf("%d\n", ft_atoi("0"));
	printf("%d\n", atoi("0"));
}
*/
