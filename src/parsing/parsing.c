/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrager <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 22:59:13 by mgrager           #+#    #+#             */
/*   Updated: 2026/08/31 22:05:30 by mgrager          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	parse(char **lines, t_game *game)
{
	int	i;

	i = 0;
	if (parse_config(game, lines, &i))
		return (1);
	if (parse_map(game, lines, i))
		return (1);
	if (check_map(game))
		return (1);
	return (0);
}
