/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrager <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 02:23:21 by mgrager           #+#    #+#             */
/*   Updated: 2026/09/03 03:46:14 by mgrager          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_safe_file(char *path)
{
	int		fd;
	char	buf[4096];
	long	total;
	int		n;

	fd = open(path, O_RDONLY | O_NONBLOCK);
	if (fd < 0)
		return (1);
	total = 0;
	n = read(fd, buf, 4096);
	while (n > 0 && total <= MAX_CUB_FILE_SIZE)
	{
		total += n;
		n = read(fd, buf, 4096);
	}
	close(fd);
	return (total > MAX_CUB_FILE_SIZE);
}

char	*skip_ws(char *line)
{
	while (*line == ' ' || *line == '\t')
		line++;
	return (line);
}
