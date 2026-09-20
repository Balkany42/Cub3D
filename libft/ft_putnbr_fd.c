/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrager <mgrager@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 17:42:34 by mgrager           #+#    #+#             */
/*   Updated: 2025/11/20 18:55:48 by mgrager          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int	i;
	long int	j;

	i = n;
	if (i < 0)
	{
		i = -i;
		write (fd, "-", 1);
	}
	if (i >= 10)
	{
		ft_putnbr_fd(i / 10, fd);
	}
	j = i % 10 + 48;
	write(fd, &j, 1);
}
/*
#include <stdio.h>
int main ()
{
	int fd;
	fd = 1;
	
	ft_putnbr_fd(2147483647, 1);
	write(fd, "\n", 1);
	ft_putnbr_fd(2147483647, 1);
	write(fd, "\n", 1);
	ft_putnbr_fd(-2147483648, 1);
	write(fd, "\n", 1);
	ft_putnbr_fd(-2147483648, 1);
	write(fd, "\n", 1);
	ft_putnbr_fd(0, 1);
	write(fd, "\n", 1);
	ft_putnbr_fd(0, 1);
	write(fd, "\n", 1);
	ft_putnbr_fd(-0, 1);
	write(fd, "\n", 1);
	ft_putnbr_fd(-0, 1);
	write(fd, "\n", 1);
	ft_putnbr_fd(-21, 1);
	write(fd, "\n", 1);
	ft_putnbr_fd(-21, 1);
	write(fd, "\n", 1);
	ft_putnbr_fd(21, 1);
	write(fd, "\n", 1);
	ft_putnbr_fd(21, 1);
}
*/
