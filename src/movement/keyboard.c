#include "cub3d.h"

int	key_press(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		exit(0);
	if (keycode >= 0 && keycode < 65536)
		game->keys[keycode] = 1;
	return (0);
}

int	key_release(int keycode, t_game *game)
{
	if (keycode >= 0 && keycode < 65536)
		game->keys[keycode] = 0;
	return (0);
}

int	mouse_hook(int x, int y, t_game *game)
{
	int	dx;

	(void)y;
	dx = x - WIN_WIDTH / 2;
	if (dx != 0)
	{
		rotate_player(game, dx * MOUSE_SENSITIVITY);
		mlx_mouse_move(game->mlx, game->win, WIN_WIDTH / 2, WIN_HEIGHT / 2);
	}
	return (0);
}