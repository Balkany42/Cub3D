/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_present_texture.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrager <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 23:20:00 by mgrager           #+#    #+#             */
/*   Updated: 2026/08/31 23:20:00 by mgrager          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_img	*pick_texture_present_dark(t_game *game, t_ray *r)
{
	if (r->side == 0)
	{
		if (r->ray_dir_x > 0)
			return (&game->img_bonus.ghost_noframe_orange
				[game->animation_ghosts]);
		return (&game->img_bonus.ghost_noframe_pink
			[game->animation_ghosts]);
	}
	if (r->ray_dir_y > 0)
		return (&game->img_bonus.ghost_noframe_red[game->animation_ghosts]);
	return (&game->img_bonus.ghost_noframe_cyan[game->animation_ghosts]);
}

static t_img	*pick_texture_present_light(t_game *game, t_ray *r)
{
	if (r->side == 0)
	{
		if (r->ray_dir_x > 0)
			return (&game->img_bonus.ghost_frame_orange
				[game->animation_ghosts]);
		return (&game->img_bonus.ghost_frame_pink[game->animation_ghosts]);
	}
	if (r->ray_dir_y > 0)
		return (&game->img_bonus.ghost_frame_red[game->animation_ghosts]);
	return (&game->img_bonus.ghost_frame_cyan[game->animation_ghosts]);
}

t_img	*pick_texture_present(t_game *game, t_ray *r)
{
	if (game->light < 0 && game->ghost_state == PRESENT)
		return (pick_texture_present_dark(game, r));
	if (game->light > 0 && game->ghost_state == PRESENT)
		return (pick_texture_present_light(game, r));
	return (0);
}
