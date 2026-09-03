/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrager <mgrager@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 17:36:26 by mgrager           #+#    #+#             */
/*   Updated: 2025/11/20 18:55:43 by mgrager          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
	write(fd, "\n", 1);
}
/*
int main()
{
	char a[4] = "AAA";
	char z[4] = "ZZZ";
	
	ft_putendl_fd(a, 2);
	ft_putendl_fd(a, 1);
	
	ft_putendl_fd(z, 2);
	ft_putendl_fd(z, 1);
}
*/
