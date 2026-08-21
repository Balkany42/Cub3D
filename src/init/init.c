#include "cub3d.h"

static void	new_img(void *mlx, t_img *img, int width, int height)
{
	img->img = mlx_new_image(mlx, width, height);
	if (!img->img)
		parse_error("mlx_new_image failed");
	img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->line_len,
			&img->endian);
	img->width = width;
	img->height = height;
}

static int	close_win(t_game *game)
{
	(void)game;
	exit(0);
	return (0);
}

int	init_game(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		parse_error("mlx_init failed");
	game->win = mlx_new_window(game->mlx, WIN_WIDTH, WIN_HEIGHT, "cub3D");
	if (!game->win)
		parse_error("mlx_new_window failed");
	new_img(game->mlx, &game->screen, WIN_WIDTH, WIN_HEIGHT);
	load_textures(game);
	mlx_hook(game->win, 17, 0, close_win, game); /* clic sur la croix */
	mlx_hook(game->win, 2, 1L << 0, key_press, game);   /* KeyPress   */
	mlx_hook(game->win, 3, 1L << 1, key_release, game); /* KeyRelease */
	mlx_hook(game->win, 6, 1L << 6, mouse_hook, game);
	return (0);
}
static void	load_one(void *mlx, t_img *tex, char *path)
{
	int	w;
	int	h;

	tex->img = mlx_xpm_file_to_image(mlx, path, &w, &h);
	if (!tex->img)
		parse_error("failed to load texture (check the path in NO/SO/WE/EA)");
	tex->width = w;
	tex->height = h;
	tex->addr = mlx_get_data_addr(tex->img, &tex->bpp, &tex->line_len,
			&tex->endian);
}

void	load_textures(t_game *game)
{
	load_one(game->mlx, &game->tex[TEX_NO], game->map.no_path);
	load_one(game->mlx, &game->tex[TEX_SO], game->map.so_path);
	load_one(game->mlx, &game->tex[TEX_WE], game->map.we_path);
	load_one(game->mlx, &game->tex[TEX_EA], game->map.ea_path);
}
double	now_seconds(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((double)tv.tv_sec + (double)tv.tv_usec / 1000000.0);
}