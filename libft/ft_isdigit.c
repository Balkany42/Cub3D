/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrager <mgrager@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 12:16:42 by mgrager           #+#    #+#             */
/*   Updated: 2025/11/20 18:54:39 by mgrager          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(size_t c)
{
	return (c >= '0' && c <= '9');
}
/*
#include <stdio.h>
#include <ctype.h>
int main()
{
	printf("%d\n", ft_isdigit(1));
	printf("%d\n", isdigit (1));
	printf("%d\n", ft_isdigit(150));
	printf("%d\n", isdigit(150));
	printf("%d\n", ft_isdigit(45));
	printf("%d\n", isdigit(45));
	printf("%d\n", ft_isdigit(55));
	printf("%d\n", isdigit(55));
	printf("%d\n", ft_isdigit(65));
	printf("%d\n", isdigit(65));
	printf("%d\n", ft_isdigit(75));
	printf("%d\n", isdigit(75));
}
*/
