/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_dispatch.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrager <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 23:20:00 by mgrager           #+#    #+#             */
/*   Updated: 2026/08/31 23:20:00 by mgrager          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_matrix_local_x(t_game *game, t_ray *r)
{
	int	left;

	left = r->map_x;
	while (game->map.grid[r->map_y][left - 1] == '3')
		left--;
	return (r->map_x - left);
}

int	get_matrix_local_y(t_game *game, t_ray *r)
{
	int	top;

	top = r->map_y;
	while (game->map.grid[top - 1][r->map_x] == '3')
		top--;
	return (r->map_y - top);
}

int	matrix_face_family(int face)
{
	if (face == TEX_NO)
		return (2);
	if (face == TEX_SO)
		return (1);
	return (0);
}

void	start_message(t_game *game, double now)
{
	t_matrix_pos	pos;

	pos.face = 0;
	while (pos.face < 4)
	{
		pos.cell = 0;
		while (pos.cell < MATRIX_SIZE)
		{
			pos.subcol = 0;
			while (pos.subcol < 8)
			{
				game->matrix_col[pos.face][pos.cell][pos.subcol].delta_start
					= now + (pos.cell * 8 + pos.subcol) * 2 * SCROLL_INTERVAL;
				pos.subcol++;
			}
			pos.cell++;
		}
		pos.face++;
	}
}

t_img	*pick_texture_matrix(t_game *game, t_ray *r)
{
	if (game->light < 0)
		return (&game->img_bonus.basics[0]);
	if (game->light > 0)
		return (pick_texture_matrix_light(game, r));
	return (0);
}
