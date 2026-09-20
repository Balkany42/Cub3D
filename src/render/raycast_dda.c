/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_dda.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrager <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 23:20:00 by mgrager           #+#    #+#             */
/*   Updated: 2026/08/31 23:20:00 by mgrager          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	dda_step(t_ray *r)
{
	if (r->side_dist_x < r->side_dist_y)
	{
		r->side_dist_x += r->delta_dist_x;
		r->map_x += r->step_x;
		r->side = 0;
	}
	else
	{
		r->side_dist_y += r->delta_dist_y;
		r->map_y += r->step_y;
		r->side = 1;
	}
}

static int	dda_check_hit(t_map *map, t_ray *r)
{
	if (r->map_y < 0 || r->map_y >= map->height
		|| r->map_x < 0 || r->map_x >= map->width)
	{
		r->character_hit = '1';
		return (1);
	}
	if (map->grid[r->map_y][r->map_x] == '1'
		|| map->grid[r->map_y][r->map_x] == 'C'
		|| map->grid[r->map_y][r->map_x] == '2'
		|| map->grid[r->map_y][r->map_x] == '3')
	{
		r->character_hit = map->grid[r->map_y][r->map_x];
		return (1);
	}
	return (0);
}

static void	dda(t_map *map, t_ray *r)
{
	int	hit;

	hit = 0;
	while (!hit)
	{
		dda_step(r);
		hit = dda_check_hit(map, r);
	}
}

void	cast_column(t_game *game, int x)
{
	t_ray	r;

	r = setup_ray(game, x);
	dda(&game->map, &r);
	if (r.side == 0)
		r.perp_wall_dist = (r.map_x - game->player.x
				+ (1 - r.step_x) / 2.0) / r.ray_dir_x;
	else
		r.perp_wall_dist = (r.map_y - game->player.y
				+ (1 - r.step_y) / 2.0) / r.ray_dir_y;
	if (r.perp_wall_dist < 0.05)
		r.perp_wall_dist = 0.05;
	draw_column(game, &r, x);
}
