/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_monument.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrager <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 22:04:28 by mgrager           #+#    #+#             */
/*   Updated: 2026/08/31 22:05:07 by mgrager          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_monument_row(t_game *game, int y, int save_x, int save_y)
{
	int	x;

	x = save_x;
	while (x < save_x + MONUMENT_SIZE + 2 * MONUMENT_AROUND && x >= 0)
	{
		if (x >= game->map.width)
			return (1);
		if (x >= save_x + MONUMENT_AROUND
			&& x < save_x + MONUMENT_AROUND + MONUMENT_SIZE
			&& y >= save_y + MONUMENT_AROUND
			&& y < save_y + MONUMENT_AROUND + MONUMENT_SIZE)
		{
			if (game->map.grid[y][x] != '2')
				return (1);
		}
		else
		{
			if (game->map.grid[y][x] != '0')
				return (1);
		}
		x++;
	}
	return (0);
}

static int	check_complete_set_monument(t_game *game, int y, int x)
{
	int	save_x;
	int	save_y;

	save_x = x - MONUMENT_AROUND;
	save_y = y - MONUMENT_AROUND;
	y = save_y;
	while (y < save_y + MONUMENT_SIZE + 2 * MONUMENT_AROUND && y >= 0)
	{
		if (y >= game->map.height)
			return (1);
		if (check_monument_row(game, y, save_x, save_y))
			return (1);
		y++;
	}
	return (0);
}

static void	check_monument_cell(t_game *game, int y, int x, t_zone *z)
{
	if (check_top_corner(game, y, x, '2'))
		return ;
	if (x - z->around < 0 || x + z->size + z->around > game->map.width
		|| y - z->around < 0 || y + z->size + z->around > game->map.height)
	{
		parse_error(game, "Monument placed wrong !");
		return ;
	}
	if (check_complete_set_monument(game, y, x))
		parse_error(game, "Incomplete Monument set !");
	game->monument_count++;
}

int	check_monuments(t_game *game, int size, int around)
{
	int		x;
	int		y;
	t_zone	z;

	z.size = size;
	z.around = around;
	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			if (game->map.grid[y][x] == '2')
				check_monument_cell(game, y, x, &z);
			x++;
		}
		y++;
	}
	return (0);
}
