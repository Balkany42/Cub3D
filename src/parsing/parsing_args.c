/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrager <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 22:58:30 by mgrager           #+#    #+#             */
/*   Updated: 2026/08/30 22:58:32 by mgrager          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	has_valid_extension(char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (len < 4)
		return (1);
	if (ft_strcmp(filename + (len - 4), ".cub") == 0)
		return (0);
	return (1);
}

int	check_file(char *filename)
{
	int	fd;

	if (is_safe_file(filename))
		return (1);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (1);
	close (fd);
	return (0);
}
