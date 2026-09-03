/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrager <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 22:57:43 by mgrager           #+#    #+#             */
/*   Updated: 2026/08/31 21:55:53 by mgrager          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	iwn(t_game *game, int y, int x)
{
	if (y < 0 || x < 0 || y >= game->map.height || x >= game->map.width)
		return (0);
	return (game->map.grid[y][x] == '1');
}

int	check_doors(t_game *game)
{
	int	x;
	int	y;
	int	horizontal;
	int	vertical;

	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			if (game->map.grid[y][x] == 'C')
			{
				vertical = iwn(game, y - 1, x) && iwn(game, y + 1, x);
				horizontal = iwn(game, y, x - 1) && iwn(game, y, x + 1);
				if (horizontal == vertical)
					parse_error(game,
						"Door must be surrounded by two aligned walls");
			}
			x++;
		}
		y++;
	}
	return (0);
}
