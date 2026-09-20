/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_glyph_pick.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrager <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 23:20:00 by mgrager           #+#    #+#             */
/*   Updated: 2026/08/31 23:20:00 by mgrager          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static unsigned int	next_rand(t_game *game)
{
	game->rand_seed = game->rand_seed * 1103515245 + 12345;
	return ((game->rand_seed / 65536) % 32768);
}

static t_img	*pick_random_glyph(t_game *game, int family)
{
	int	index;

	if (family == 0)
	{
		index = next_rand(game) % (52 + 10 + 24);
		if (index < 52)
			return (&game->img_bonus.rand_latin[index]);
		index -= 52;
		if (index < 10)
			return (&game->img_bonus.rand_digit[index]);
		return (&game->img_bonus.rand_sign[index - 10]);
	}
	if (family == 1)
	{
		index = next_rand(game) % (77 + 10 + 24);
		if (index < 77)
			return (&game->img_bonus.rand_ru[index]);
		index -= 77;
		if (index < 10)
			return (&game->img_bonus.rand_digit[index]);
		return (&game->img_bonus.rand_sign[index - 10]);
	}
	return (&game->img_bonus.rand_braille[next_rand(game) % 51]);
}

static t_img	*pick_blue_glyph(t_game *game, int face, int cell)
{
	if (face == TEX_NO)
		return (&game->img_bonus.blue_braille[cell]);
	if (face == TEX_SO)
		return (&game->img_bonus.blue_ru[cell]);
	if (face == TEX_WE)
		return (&game->img_bonus.blue_fr[cell]);
	if (face == TEX_EA)
		return (&game->img_bonus.blue_eng[cell]);
	return (NULL);
}

static t_img	*pick_red_glyph(t_game *game, int face, int cell)
{
	if (face == TEX_NO)
		return (&game->img_bonus.red_braille[cell]);
	if (face == TEX_SO)
		return (&game->img_bonus.red_ru[cell]);
	if (face == TEX_WE)
		return (&game->img_bonus.red_fr[cell]);
	if (face == TEX_EA)
		return (&game->img_bonus.red_eng[cell]);
	return (NULL);
}

t_img	*pick_glyph(t_game *game, int family, t_matrix_pos *pos, double now)
{
	t_matrix_col	*col;
	int				message;

	col = &game->matrix_col[pos->face][pos->cell][pos->subcol];
	message = (game->matrix_state == MATRIX_BLUE_PILL
			|| game->matrix_state == MATRIX_RED_PILL)
		&& now >= col->delta_start;
	if (message && !col->is_message_glyph)
		col->glyphs_done = 0;
	col->is_message_glyph = message;
	if (!message)
		return (pick_random_glyph(game, family));
	if (game->matrix_state == MATRIX_BLUE_PILL)
		return (pick_blue_glyph(game, pos->face, pos->cell));
	if (game->matrix_state == MATRIX_RED_PILL)
		return (pick_red_glyph(game, pos->face, pos->cell));
	return (NULL);
}
