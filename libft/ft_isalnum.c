/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrager <mgrager@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 12:18:13 by mgrager           #+#    #+#             */
/*   Updated: 2025/11/20 18:54:29 by mgrager          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(size_t c)
{
	return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')
		|| (c >= '0' && c <= '9'));
}
/*
#include <stdio.h>
#include <ctype.h>
int main()
{
	printf("%d\n", ft_isalnum('C'));
	printf("%d\n", isalnum('C'));
	printf("%d\n", ft_isalnum('1'));
	printf("%d\n", isalnum('1'));
	printf("%d\n", ft_isalnum(5259));
	printf("%d\n", isalnum(5259));
	printf("%d\n", ft_isalnum('d'));
	printf("%d\n", isalnum('d'));
	printf("%d\n", ft_isalnum(123));
	printf("%d\n", isalnum(123));
	printf("%d\n", ft_isalnum(111));
	printf("%d\n", isalnum(111));
}
*/
