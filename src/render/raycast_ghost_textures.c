/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_ghost_textures.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrager <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 23:20:00 by mgrager           #+#    #+#             */
/*   Updated: 2026/08/31 23:20:00 by mgrager          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_img	*pick_texture_absent(t_game *game, t_ray *r)
{
	if (game->light < 0 && game->ghost_state == ABSENT)
	{
		if (r->side == 0)
		{
			if (r->ray_dir_x > 0)
				return (&game->tex[TEX_WE]);
			return (&game->tex[TEX_EA]);
		}
		if (r->ray_dir_y > 0)
			return (&game->tex[TEX_NO]);
		return (&game->tex[TEX_SO]);
	}
	if (game->light > 0 && game->ghost_state == ABSENT)
		return (&game->img_bonus.basics[2]);
	return (0);
}

static t_img	*pick_texture_hidden(t_game *game)
{
	if (game->light < 0 && game->ghost_state == HIDDEN)
	{
		if ((game->animation_ghosts % 4) == 0)
			return (&game->img_bonus.ghost_noframe_eyes[0]);
		if ((game->animation_ghosts % 4) == 1)
			return (&game->img_bonus.ghost_noframe_eyes[1]);
		if ((game->animation_ghosts % 4) == 2)
			return (&game->img_bonus.ghost_noframe_eyes[2]);
		if ((game->animation_ghosts % 4) == 3)
			return (&game->img_bonus.ghost_noframe_eyes[3]);
	}
	if (game->light > 0 && game->ghost_state == HIDDEN)
	{
		if ((game->animation_ghosts % 4) == 0)
			return (&game->img_bonus.ghost_frame_eyes[0]);
		if ((game->animation_ghosts % 4) == 1)
			return (&game->img_bonus.ghost_frame_eyes[1]);
		if ((game->animation_ghosts % 4) == 2)
			return (&game->img_bonus.ghost_frame_eyes[2]);
		if ((game->animation_ghosts % 4) == 3)
			return (&game->img_bonus.ghost_frame_eyes[3]);
	}
	return (0);
}

static t_img	*pick_texture_scared(t_game *game)
{
	if (game->light < 0 && game->ghost_state == SCARED)
	{
		if ((game->animation_ghosts % 4) == 0)
			return (&game->img_bonus.ghost_noframe_blue[0]);
		if ((game->animation_ghosts % 4) == 1)
			return (&game->img_bonus.ghost_noframe_blue[1]);
		if ((game->animation_ghosts % 4) == 2)
			return (&game->img_bonus.ghost_noframe_white[0]);
		if ((game->animation_ghosts % 4) == 3)
			return (&game->img_bonus.ghost_noframe_white[1]);
	}
	if (game->light > 0 && game->ghost_state == SCARED)
	{
		if ((game->animation_ghosts % 4) == 0)
			return (&game->img_bonus.ghost_frame_blue[0]);
		if ((game->animation_ghosts % 4) == 1)
			return (&game->img_bonus.ghost_frame_blue[1]);
		if ((game->animation_ghosts % 4) == 2)
			return (&game->img_bonus.ghost_frame_white[0]);
		if ((game->animation_ghosts % 4) == 3)
			return (&game->img_bonus.ghost_frame_white[1]);
	}
	return (0);
}

t_img	*pick_texture_wall(t_game *game, t_ray *r)
{
	if (game->ghost_state == ABSENT)
		return (pick_texture_absent(game, r));
	else if (game->ghost_state == HIDDEN)
		return (pick_texture_hidden(game));
	else if (game->ghost_state == PRESENT)
		return (pick_texture_present(game, r));
	else if (game->ghost_state == SCARED)
		return (pick_texture_scared(game));
	return (0);
}
