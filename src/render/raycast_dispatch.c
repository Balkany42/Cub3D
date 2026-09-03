/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_dispatch.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrager <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 23:20:00 by mgrager           #+#    #+#             */
/*   Updated: 2026/08/31 23:20:00 by mgrager          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_monument_local_x(t_game *game, t_ray *r)
{
	int	left;

	left = r->map_x;
	while (game->map.grid[r->map_y][left - 1] == '2')
		left--;
	return (r->map_x - left);
}

int	get_monument_local_y(t_game *game, t_ray *r)
{
	int	top;

	top = r->map_y;
	while (game->map.grid[top - 1][r->map_x] == '2')
		top--;
	return (r->map_y - top);
}

static t_img	*pick_texture_door(t_game *game)
{
	if (game->light > 0)
		return (&game->img_bonus.basics[1]);
	if (game->light < 0)
		return (&game->img_bonus.basics[0]);
	return (0);
}

static t_img	*pick_texture_monument(t_game *game, t_ray *r)
{
	if (game->light < 0)
		return (&game->img_bonus.basics[0]);
	if (game->light > 0)
		return (pick_texture_monument_light(game, r));
	return (0);
}

t_img	*pick_texture(t_game *game, t_ray *r)
{
	if (r->character_hit == 'C')
		return (pick_texture_door(game));
	if (r->character_hit == '1')
		return (pick_texture_wall(game, r));
	if (r->character_hit == '2')
		return (pick_texture_monument(game, r));
	if (r->character_hit == '3')
		return (pick_texture_matrix(game, r));
	return (0);
}
