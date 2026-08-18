#include "../../include/cub3d.h"

static int	has_cub_extension(const char *path)
{
	int	len;

	len = (int)strlen(path);
	return (len > 4 && !strcmp(path + len - 4, ".cub"));
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		die("usage: ./cub3D <map.cub>");
	if (!has_cub_extension(argv[1]))
		die("map file must have a .cub extension");
	memset(&game, 0, sizeof(t_game));
	parse_map(argv[1], &game.map, &game.player);
	init_game(&game);
	game.last_time = now_seconds();
	mlx_loop_hook(game.mlx, render_loop, &game);
	mlx_loop(game.mlx);
	return (0);
}