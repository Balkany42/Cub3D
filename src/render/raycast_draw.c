/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_draw.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrager <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 23:20:00 by mgrager           #+#    #+#             */
/*   Updated: 2026/08/31 23:20:00 by mgrager          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	get_tex_x(t_game *game, t_ray *r, t_img *tex)
{
	double	wall_x;
	int		tex_x;

	if (r->side == 0)
		wall_x = game->player.y + r->perp_wall_dist * r->ray_dir_y;
	else
		wall_x = game->player.x + r->perp_wall_dist * r->ray_dir_x;
	wall_x -= floor(wall_x);
	tex_x = (int)(wall_x * tex->width);
	if ((r->side == 0 && r->ray_dir_x < 0)
		|| (r->side == 1 && r->ray_dir_y > 0))
		tex_x = tex->width - tex_x - 1;
	return (tex_x);
}

static void	setup_col_draw(t_game *game, t_ray *r, t_col_draw *cd)
{
	cd->line_h = (int)(WIN_HEIGHT / r->perp_wall_dist);
	cd->draw_start = -cd->line_h / 2 + WIN_HEIGHT / 2;
	cd->draw_end = cd->line_h / 2 + WIN_HEIGHT / 2;
	cd->tex = pick_texture(game, r);
	cd->tex_x = get_tex_x(game, r, cd->tex);
	cd->step = (double)cd->tex->height / cd->line_h;
	cd->tex_pos = 0;
	if (cd->draw_start > 0)
		cd->tex_pos = cd->draw_start;
	cd->tex_pos = (cd->tex_pos - WIN_HEIGHT / 2 + cd->line_h / 2) * cd->step;
}

static void	render_col_pixels(t_game *game, t_ray *r, t_col_draw *cd, int x)
{
	int	y;
	int	color;

	y = 0;
	if (cd->draw_start > 0)
		y = cd->draw_start;
	while (y < WIN_HEIGHT && y < cd->draw_end)
	{
		color = get_tex_pixel(cd->tex, cd->tex_x, (int)cd->tex_pos);
		if (r->side == 1)
			color = (color >> 1) & 0x7F7F7F;
		put_pixel(&game->screen, x, y, color);
		cd->tex_pos += cd->step;
		y++;
	}
}

void	draw_column(t_game *game, t_ray *r, int x)
{
	t_col_draw	cd;

	setup_col_draw(game, r, &cd);
	render_col_pixels(game, r, &cd, x);
}
