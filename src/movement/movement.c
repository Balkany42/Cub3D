#include "cub3d.h"

static void	zoom_player(t_game *game, double factor)
{
	t_player	*p;
	double		len;
	double		new_len;

	p = &game->player;
	len = sqrt(p->plane_x * p->plane_x + p->plane_y * p->plane_y);
	new_len = len * factor;
	if (new_len < FOV_MIN)
		factor = FOV_MIN / len;
	else if (new_len > FOV_MAX)
		factor = FOV_MAX / len;
	p->plane_x *= factor;
	p->plane_y *= factor;
}

int	is_wall(t_map *map, double x, double y)
{
	int	mx;
	int	my;

	mx = (int)x;
	my = (int)y;
	if (my < 0 || my >= map->height || mx < 0 || mx >= map->width)
		return (1);
	return (map->grid[my][mx] == '1');
}
static void try_move(t_game *game, double dx, double dy)
{
    t_player    *p;
    double      margin_x;
    double      margin_y;

    p = &game->player;
    if (dx > 0)
        margin_x = WALL_MARGIN;
    else
        margin_x = -WALL_MARGIN;
    if (dy > 0)
        margin_y = WALL_MARGIN;
    else
        margin_y = -WALL_MARGIN;
    if (!is_wall(&game->map, p->x + dx + margin_x, p->y))
        p->x += dx;
    if (!is_wall(&game->map, p->x, p->y + dy + margin_y))
        p->y += dy;
}

void	rotate_player(t_game *game, double angle)
{
	t_player	*p;
	double		old_dir_x;
	double		old_plane_x;

	p = &game->player;
	old_dir_x = p->dir_x;
	p->dir_x = p->dir_x * cos(angle) - p->dir_y * sin(angle);
	p->dir_y = old_dir_x * sin(angle) + p->dir_y * cos(angle);
	old_plane_x = p->plane_x;
	p->plane_x = p->plane_x * cos(angle) - p->plane_y * sin(angle);
	p->plane_y = old_plane_x * sin(angle) + p->plane_y * cos(angle);
}

void	move_player(t_game *game, double dt)
{
	t_player	*p;
	double		speed;
	double		right_x;
	double		right_y;

	p = &game->player;
	speed = MOVE_SPEED * dt;
	right_x = -p->dir_y;
	right_y = p->dir_x;
	if (game->keys[KEY_W])
		try_move(game, p->dir_x * speed, p->dir_y * speed);
	if (game->keys[KEY_S])
		try_move(game, -p->dir_x * speed, -p->dir_y * speed);
	if (game->keys[KEY_D])
		try_move(game, right_x * speed, right_y * speed);
	if (game->keys[KEY_A])
		try_move(game, -right_x * speed, -right_y * speed);
	if (game->keys[KEY_LEFT])
		rotate_player(game, -ROT_SPEED * dt);
	if (game->keys[KEY_RIGHT])
		rotate_player(game, ROT_SPEED * dt);
	if (game->keys[KEY_UP])
		zoom_player(game, 1.0 - ZOOM_SPEED * dt);
	if (game->keys[KEY_DOWN])
		zoom_player(game, 1.0 + ZOOM_SPEED * dt);
}
