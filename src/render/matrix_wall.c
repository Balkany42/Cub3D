/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_wall.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrager <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 23:20:00 by mgrager           #+#    #+#             */
/*   Updated: 2026/08/31 23:20:00 by mgrager          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_img	*pick_matrix_no(t_game *game, t_ray *r)
{
	int	index;

	index = 6 - get_matrix_local_x(game, r);
	return (&game->matrix_tex[TEX_NO][index]);
}

static t_img	*pick_matrix_so(t_game *game, t_ray *r)
{
	int	index;

	index = get_matrix_local_x(game, r);
	return (&game->matrix_tex[TEX_SO][index]);
}

static t_img	*pick_matrix_we(t_game *game, t_ray *r)
{
	int	index;

	index = get_matrix_local_y(game, r);
	return (&game->matrix_tex[TEX_WE][index]);
}

static t_img	*pick_matrix_ea(t_game *game, t_ray *r)
{
	int	index;

	index = 6 - get_matrix_local_y(game, r);
	return (&game->matrix_tex[TEX_EA][index]);
}

t_img	*pick_texture_matrix_light(t_game *game, t_ray *r)
{
	if (game->light > 0)
	{
		if (r->side == 0)
		{
			if (r->ray_dir_x > 0)
				return (pick_matrix_we(game, r));
			return (pick_matrix_ea(game, r));
		}
		if (r->ray_dir_y > 0)
			return (pick_matrix_no(game, r));
		return (pick_matrix_so(game, r));
	}
	return (0);
}
