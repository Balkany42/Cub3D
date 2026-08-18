/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrager <mgrager@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 12:20:40 by mgrager           #+#    #+#             */
/*   Updated: 2025/11/20 18:52:40 by mgrager          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(size_t c)
{
	return (c >= 0 && c <= 127);
}
/*
#include <stdio.h>
#include <ctype.h>
int main()
{
	printf("%d\n", ft_isascii('C'));
	printf("%d\n", isascii('C'));
	printf("%d\n", ft_isascii('1'));
	printf("%d\n", isascii('1'));
	printf("%d\n", ft_isascii(5259));
	printf("%d\n", isascii(5259));
	printf("%d\n", ft_isascii('d'));
	printf("%d\n", isascii('d'));
	printf("%d\n", ft_isascii(123));
	printf("%d\n", isascii(123));
	printf("%d\n", ft_isascii(111));
	printf("%d\n", isascii(111));
}
*/
