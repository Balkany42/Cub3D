/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrager <mgrager@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 12:24:43 by mgrager           #+#    #+#             */
/*   Updated: 2025/11/20 18:55:37 by mgrager          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = (unsigned char)c;
		i++;
	}
	return (s);
}
/*
#include <string.h>
#include <stdio.h>
int main ()
{
	char buf_ft[20];
    char buf_std[20];
    int len = 20;
    int fill_char = '@';
    
    memset(buf_ft, 0, len);
    memset(buf_std, 0, len);
    
    ft_memset(buf_ft, fill_char, len);
    memset(buf_std, fill_char, len);
    
    printf("%d\n", memcmp(buf_ft, buf_std, len));
}
*/
