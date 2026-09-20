/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrager <mgrager@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 12:14:51 by mgrager           #+#    #+#             */
/*   Updated: 2025/11/20 18:54:35 by mgrager          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(size_t c)
{
	return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}
/*
#include <stdio.h>
#include <ctype.h>
int main()
{
	printf("%d\n", ft_isalpha('C'));
	printf("%d\n", isalpha('C'));
	printf("%d\n", ft_isalpha('1'));
	printf("%d\n", isalpha('1'));
	printf("%d\n", ft_isalpha(5259));
	printf("%d\n", isalpha(5259));
	printf("%d\n", ft_isalpha('d'));
	printf("%d\n", isalpha('d'));
	printf("%d\n", ft_isalpha(123));
	printf("%d\n", isalpha(123));
	printf("%d\n", ft_isalpha(111));
	printf("%d\n", isalpha(111));
}
*/
