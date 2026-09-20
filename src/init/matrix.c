/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrager <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 22:41:18 by mgrager           #+#    #+#             */
/*   Updated: 2026/08/30 22:44:09 by mgrager          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	matrix_frame_color(int x, int y, int cell)
{
	int	d;

	d = y;
	if (TILE_SIZE - 1 - y < d)
		d = TILE_SIZE - 1 - y;
	if (cell == 0 && x < d)
		d = x;
	if (cell == MATRIX_SIZE - 1 && TILE_SIZE - 1 - x < d)
		d = TILE_SIZE - 1 - x;
	if (d >= 3 && d < 5)
		return (0x70DD99);
	return (0x000000);
}

static void	paint_matrix_cell(t_img *img, int cell)
{
	int	x;
	int	y;

	y = 0;
	while (y < TILE_SIZE)
	{
		x = 0;
		while (x < TILE_SIZE)
		{
			put_pixel(img, x, y, matrix_frame_color(x, y, cell));
			x++;
		}
		y++;
	}
}

static void	init_structure(t_game *game, int face, int cell)
{
	int				subcol;
	t_matrix_col	*col;

	subcol = 0;
	while (subcol < 8)
	{
		col = &game->matrix_col[face][cell][subcol];
		col->current_glyph = NULL;
		col->progress = 0;
		col->glyphs_done = 0;
		col->is_message_glyph = 0;
		col->delta_start = 0;
		col->next_tick = now_seconds() + subcol * 2 * SCROLL_INTERVAL;
		subcol++;
	}
}

void	init_matrix_textures(t_game *game)
{
	int	face;
	int	cell;

	face = 0;
	while (face < 4)
	{
		cell = 0;
		while (cell < MATRIX_SIZE)
		{
			new_img(game, &game->matrix_tex[face][cell], TILE_SIZE, TILE_SIZE);
			paint_matrix_cell(&game->matrix_tex[face][cell], cell);
			init_structure(game, face, cell);
			cell++;
		}
		face++;
	}
}

void	init_state_texture(t_game *game)
{
	int	face;
	int	cell;

	face = 0;
	while (face < 4)
	{
		cell = 0;
		while (cell < MATRIX_SIZE)
		{
			paint_matrix_cell(&game->matrix_tex[face][cell], cell);
			init_structure(game, face, cell);
			cell++;
		}
		face++;
	}
}
