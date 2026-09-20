/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrager <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 22:09:49 by mgrager           #+#    #+#             */
/*   Updated: 2026/09/03 03:47:55 by mgrager          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	fill_col1(char **col1)
{
	col1[0] = "Esc : Leave game";
	col1[1] = "W : Move up";
	col1[2] = "A : Move left";
	col1[3] = "S : Move down";
	col1[4] = "D : Move right";
	col1[5] = "Up arrow / wheel up : Zoom";
	col1[6] = "Down arrow / wheel down : Zoom out";
	col1[7] = "Left arrow / mouse left : Turn left";
	col1[8] = "Right arrow / mouse right : Turn right";
	col1[9] = NULL;
}

static void	fill_col2(char **col2)
{
	col2[0] = "Spacebar : Toggle door";
	col2[1] = "P : Turn on/off electricity";
	col2[2] = "O : Call ghosts";
	col2[3] = "I : Scare ghosts";
	col2[4] = "R : Launch Matrix";
	col2[5] = "T : Blue pill";
	col2[6] = "Y : Red pill";
	col2[7] = "M : Close control tab";
	col2[8] = NULL;
}

static void	render_column(t_game *game, char **lines, int x, int y)
{
	int	i;

	i = 0;
	while (lines[i])
	{
		if (!ft_strcmp(lines[i], "T : Blue pill"))
			mlx_string_put(game->mlx, game->win, x,
				y + (i + 2) * CONTROL_LINE_HEIGHT, 0x0066FF, lines[i]);
		else if (!ft_strcmp(lines[i], "Y : Red pill"))
			mlx_string_put(game->mlx, game->win, x,
				y + (i + 2) * CONTROL_LINE_HEIGHT, 0xFF0000, lines[i]);
		else
			mlx_string_put(game->mlx, game->win, x,
				y + (i + 2) * CONTROL_LINE_HEIGHT, 0x70DD99, lines[i]);
		i++;
	}
}

void	render_control_text(t_game *game)
{
	char	*col1[10];
	char	*col2[9];
	int		x;
	int		y;

	fill_col1(col1);
	fill_col2(col2);
	x = WIN_WIDTH - CONTROL_OFFSET_PX - CONTROL_WIDTH_PX + MINIMAP_TILE + 10;
	y = WIN_HEIGHT - CONTROL_OFFSET_PX - CONTROL_HEIGHT_PX + MINIMAP_TILE;
	render_column(game, col1, x, y);
	render_column(game, col2, x + CONTROL_COL_GAP, y);
}

void	render_control_panel(t_game *game)
{
	int	x;
	int	y;
	int	start_x;
	int	start_y;

	start_y = WIN_HEIGHT - CONTROL_OFFSET_PX - CONTROL_HEIGHT_PX;
	start_x = WIN_WIDTH - CONTROL_OFFSET_PX - CONTROL_WIDTH_PX;
	y = start_y;
	while (y < start_y + CONTROL_HEIGHT_PX)
	{
		x = start_x;
		while (x < WIN_WIDTH - CONTROL_OFFSET_PX)
		{
			if (x <= start_x + MINIMAP_TILE || y < start_y + MINIMAP_TILE
				|| x >= WIN_WIDTH - CONTROL_OFFSET_PX - MINIMAP_TILE
				|| y >= start_y + CONTROL_HEIGHT_PX - MINIMAP_TILE)
				put_pixel(&game->screen, x, y, 0xFFFFFF);
			else
				put_pixel(&game->screen, x, y, 0x000000);
			x++;
		}
		y++;
	}
}
