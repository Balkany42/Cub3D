/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_tick.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrager <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 23:20:00 by mgrager           #+#    #+#             */
/*   Updated: 2026/08/31 23:20:00 by mgrager          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	tick_column_inject(t_game *game, t_matrix_pos *pos,
	t_matrix_col *col)
{
	t_glyph_pos	gp;

	gp.x = pos->subcol * GLYPH_SIZE;
	gp.row = col->progress;
	gp.offset_x = 0;
	gp.offset_y = 0;
	shift_column_up(&game->matrix_tex[pos->face][pos->cell], gp.x);
	if (col->is_message_glyph)
	{
		gp.offset_x = pos->subcol * GLYPH_SIZE;
		gp.offset_y = col->glyphs_done * GLYPH_SIZE;
	}
	inject_new_row(&game->matrix_tex[pos->face][pos->cell],
		col->current_glyph, &gp);
}

static void	tick_column(t_game *game, t_matrix_pos *pos, double now)
{
	t_matrix_col	*col;

	col = &game->matrix_col[pos->face][pos->cell][pos->subcol];
	if (now < col->next_tick)
		return ;
	if (col->is_message_glyph && col->glyphs_done >= GLYPH_SIZE - 1)
		return ;
	if (col->current_glyph == NULL)
		col->current_glyph = pick_glyph(game, matrix_face_family(pos->face),
				pos, now);
	tick_column_inject(game, pos, col);
	col->progress++;
	if (col->progress == GLYPH_SIZE)
	{
		col->progress = 0;
		col->current_glyph = NULL;
		col->glyphs_done++;
	}
	col->next_tick = now + SCROLL_INTERVAL;
}

static void	tick_cell(t_game *game, t_matrix_pos *pos, double now)
{
	int	col_end;

	pos->subcol = 0;
	col_end = 7;
	if (pos->cell == 0)
		pos->subcol = 1;
	else if (pos->cell == MATRIX_SIZE - 1)
		col_end = 6;
	while (pos->subcol <= col_end)
	{
		tick_column(game, pos, now);
		pos->subcol++;
	}
}

void	update_animation_matrix(t_game *game, double now)
{
	t_matrix_pos	pos;

	pos.face = 0;
	while (pos.face < 4)
	{
		pos.cell = 0;
		while (pos.cell < MATRIX_SIZE)
		{
			tick_cell(game, &pos, now);
			pos.cell++;
		}
		pos.face++;
	}
}
