/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrager <mgrager@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 12:27:25 by mgrager           #+#    #+#             */
/*   Updated: 2025/11/20 18:54:18 by mgrager          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = '\0';
		i++;
	}
}
/*
#include <string.h>
#include <stdio.h>
int main ()
{
	char buf_ft[20];
    char buf_std[20];
    int len = 20;
    
    memset(buf_ft, 99, len);
    memset(buf_std, 99, len);
    
    ft_bzero(buf_ft, len);
    bzero(buf_std, len);
    
    printf("%d\n", memcmp(buf_ft, buf_std, len));
}
*/
