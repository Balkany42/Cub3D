#include "cub3d.h"

static t_ray	setup_ray(t_game *game, int x)
{
	t_ray	r;
	double	camera_x;
	t_player *p;

	p = &game->player;
	camera_x = 2.0 * x / (double)WIN_WIDTH - 1.0;
	r.ray_dir_x = p->dir_x + p->plane_x * camera_x;
	r.ray_dir_y = p->dir_y + p->plane_y * camera_x;
	r.map_x = (int)p->x;
	r.map_y = (int)p->y;
	if (r.ray_dir_x == 0)
		r.delta_dist_x = 1e30;
	else
		r.delta_dist_x = fabs(1.0 / r.ray_dir_x);
	if (r.ray_dir_y == 0)
		r.delta_dist_y = 1e30;
	else
		r.delta_dist_y = fabs(1.0 / r.ray_dir_y);
	if (r.ray_dir_x < 0)
	{
		r.step_x = -1;
		r.side_dist_x = (p->x - r.map_x) * r.delta_dist_x;
	}
	else
	{
		r.step_x = 1;
		r.side_dist_x = (r.map_x + 1.0 - p->x) * r.delta_dist_x;
	}
	if (r.ray_dir_y < 0)
	{
		r.step_y = -1;
		r.side_dist_y = (p->y - r.map_y) * r.delta_dist_y;
	}
	else
	{
		r.step_y = 1;
		r.side_dist_y = (r.map_y + 1.0 - p->y) * r.delta_dist_y;
	}
	return (r);
}

static void	dda(t_map *map, t_ray *r)
{
	int	hit;

	hit = 0;
	while (!hit)
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
		if (r->map_y < 0 || r->map_y >= map->height
			|| r->map_x < 0 || r->map_x >= map->width)
			hit = 1;
		else if (map->grid[r->map_y][r->map_x] == '1')
			hit = 1;
	}
}

static t_img	*pick_texture(t_game *game, t_ray *r)
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
static void	draw_column(t_game *game, t_ray *r, int x)
{
	int		line_h;
	int		draw_start;
	int		draw_end;
	double	wall_x;
	int		tex_x;
	t_img	*tex;
	double	step;
	double	tex_pos;
	int		y;
	int		color;

	line_h = (int)(WIN_HEIGHT / r->perp_wall_dist);
	draw_start = -line_h / 2 + WIN_HEIGHT / 2;
	draw_end = line_h / 2 + WIN_HEIGHT / 2;
	tex = pick_texture(game, r);
	if (r->side == 0)
		wall_x = game->player.y + r->perp_wall_dist * r->ray_dir_y;
	else
		wall_x = game->player.x + r->perp_wall_dist * r->ray_dir_x;
	wall_x -= floor(wall_x);
	tex_x = (int)(wall_x * tex->width);
	if ((r->side == 0 && r->ray_dir_x > 0) || (r->side == 1 && r->ray_dir_y < 0))
		tex_x = tex->width - tex_x - 1;
	step = (double)tex->height / line_h;
	tex_pos = (double)(draw_start < 0 ? 0 : draw_start);
	tex_pos = (tex_pos - WIN_HEIGHT / 2 + line_h / 2) * step;
	y = (draw_start < 0) ? 0 : draw_start;
	while (y < WIN_HEIGHT && y < draw_end)
	{
		color = get_tex_pixel(tex, tex_x, (int)tex_pos);
		if (r->side == 1)
			color = (color >> 1) & 0x7F7F7F; /* murs N/S légèrement assombris */
		put_pixel(&game->screen, x, y, color);
		tex_pos += step;
		y++;
	}
}

static void	cast_column(t_game *game, int x)
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

void	render_frame(t_game *game)
{
	int	x;

	render_floor_ceiling(game);
	x = 0;
	while (x < WIN_WIDTH)
	{
		cast_column(game, x);
		x++;
	}
	if (BONUS)
		draw_minimap(game);
	mlx_put_image_to_window(game->mlx, game->win, game->screen.img, 0, 0);
}

int	render_loop(t_game *game)
{
	double	now;
	double	dt;

	now = now_seconds();
	dt = now - game->last_time;
	game->last_time = now;
	if (dt > 0.1)
		dt = 0.1; /* évite un "saut" si le programme a été mis en pause */
	move_player(game, dt);
	render_frame(game);
	return (0);
}
