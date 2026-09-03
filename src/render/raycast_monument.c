/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_monument.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrager <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 23:20:00 by mgrager           #+#    #+#             */
/*   Updated: 2026/08/31 23:20:00 by mgrager          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_img	*pick_monument_no(t_game *game, t_ray *r)
{
	int	index;

	index = 2 - get_monument_local_x(game, r);
	return (&game->img_bonus.creator[index]);
}

static t_img	*pick_monument_so(t_game *game, t_ray *r)
{
	int	index;

	index = get_monument_local_x(game, r);
	return (&game->img_bonus.creator[index]);
}

static t_img	*pick_monument_we(t_game *game, t_ray *r)
{
	int	index;

	index = get_monument_local_y(game, r);
	return (&game->img_bonus.creator[index]);
}

static t_img	*pick_monument_ea(t_game *game, t_ray *r)
{
	int	index;

	index = 2 - get_monument_local_y(game, r);
	return (&game->img_bonus.creator[index]);
}

t_img	*pick_texture_monument_light(t_game *game, t_ray *r)
{
	if (game->light > 0)
	{
		if (r->side == 0)
		{
			if (r->ray_dir_x > 0)
				return (pick_monument_we(game, r));
			return (pick_monument_ea(game, r));
		}
		if (r->ray_dir_y > 0)
			return (pick_monument_no(game, r));
		return (pick_monument_so(game, r));
	}
	return (0);
}
