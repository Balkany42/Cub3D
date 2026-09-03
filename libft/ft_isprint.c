/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrager <mgrager@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 12:21:39 by mgrager           #+#    #+#             */
/*   Updated: 2025/11/20 18:54:42 by mgrager          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(size_t c)
{
	return (c >= 32 && c <= 126);
}
/*
#include <stdio.h>
#include <ctype.h>
int main()
{
	printf("%d\n", ft_isprint('C'));
	printf("%d\n", isprint('C'));
	printf("%d\n", ft_isprint('1'));
	printf("%d\n", isprint('1'));
	printf("%d\n", ft_isprint(5259));
	printf("%d\n", isprint(5259));
	printf("%d\n", ft_isprint('d'));
	printf("%d\n", isprint('d'));
	printf("%d\n", ft_isprint(123));
	printf("%d\n", isprint(123));
	printf("%d\n", ft_isprint(111));
	printf("%d\n", isprint(111));
}
*/
