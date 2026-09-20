/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_frame.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrager <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 23:20:00 by mgrager           #+#    #+#             */
/*   Updated: 2026/08/31 23:20:00 by mgrager          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	cell_colour(char c)
{
	if (c == '1')
		return (0x888888);
	if (c == '0')
		return (0x222222);
	if (c == '2')
		return (0xFFFAF0);
	if (c == '3')
		return (0x70DD99);
	if (c == 'C')
		return (0xFF0000);
	if (c == 'O')
		return (0x00FF00);
	return (-1);
}

void	render_cell(t_game *game, int colour, int y, int x)
{
	int	save_x;
	int	save_y;

	save_x = x;
	save_y = y;
	while (y < save_y + MINIMAP_TILE)
	{
		x = save_x;
		while (x < save_x + MINIMAP_TILE)
		{
			put_pixel(&game->screen, x, y, colour);
			x++;
		}
		y++;
	}
}

void	render_grid_cell(t_game *game, int colour, int y, int x)
{
	int	save_x;
	int	save_y;

	save_x = x;
	save_y = y;
	while (y < save_y + MINIMAP_TILE)
	{
		x = save_x;
		while (x < save_x + MINIMAP_TILE)
		{
			if (x >= MINIMAP_OFFSET && y >= MINIMAP_OFFSET
				&& x < MINIMAP_OFFSET + MINIMAP_TILE * MINIMAP_WIDTH
				&& y < MINIMAP_OFFSET + MINIMAP_TILE * MINIMAP_HEIGHT)
				put_pixel(&game->screen, x, y, colour);
			x++;
		}
		y++;
	}
}

void	render_cursor(t_game *game, int center_x, int center_y)
{
	int	i;

	i = 0;
	while (i < MINIMAP_TILE)
	{
		put_pixel(&game->screen, center_x + (int)(game->player.dir_x * i),
			center_y + (int)(game->player.dir_y * i), 0xFFFF00);
		i++;
	}
}

void	render_minimap_frame(t_game *game)
{
	int	i;

	i = -1;
	while (i <= MINIMAP_WIDTH)
	{
		render_cell(game, 0xFFFFFF, MINIMAP_OFFSET - MINIMAP_TILE,
			MINIMAP_OFFSET + MINIMAP_TILE * i);
		render_cell(game, 0xFFFFFF,
			MINIMAP_OFFSET + MINIMAP_TILE * MINIMAP_HEIGHT,
			MINIMAP_OFFSET + MINIMAP_TILE * i);
		i++;
	}
	i = -1;
	while (i <= MINIMAP_HEIGHT)
	{
		render_cell(game, 0xFFFFFF, MINIMAP_OFFSET + MINIMAP_TILE * i,
			MINIMAP_OFFSET - MINIMAP_TILE);
		render_cell(game, 0xFFFFFF, MINIMAP_OFFSET + MINIMAP_TILE * i,
			MINIMAP_OFFSET + MINIMAP_TILE * MINIMAP_WIDTH);
		i++;
	}
}
