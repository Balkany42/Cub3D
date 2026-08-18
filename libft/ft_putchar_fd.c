/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrager <mgrager@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 17:30:44 by mgrager           #+#    #+#             */
/*   Updated: 2025/11/20 18:55:40 by mgrager          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
/*
int main()
{
	ft_putchar_fd('A', 2);
	ft_putchar_fd('\n', 2);
	
	ft_putchar_fd('A', 1);
	ft_putchar_fd('\n', 1);
}
*/
