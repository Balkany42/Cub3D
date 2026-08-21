#include "cub3d.h"

// static int	has_cub_extension(const char *path)
// {
// 	int	len;

// 	len = (int)strlen(path);
// 	return (len > 4 && !strcmp(path + len - 4, ".cub"));
// }

// Fonction Diana

int	main(int argc, char **argv)
{
	t_game	game;
	char **lines;

	if (argc != 2)
		parse_error("usage: ./cub3D <map.cub>");
	if (has_valid_extension(argv[1]))
		parse_error("map file must have a .cub extension");
	if (check_file(argv[1]))
		parse_error("");
	ft_memset(&game, 0, sizeof(t_game));
	lines = read_file(argv[1]);
	if(!lines)
		parse_error("failed to read file"); // Ne pas oublier de remplacer die
	if(parse(lines, &game.map, &game.player))
		parse_error(""); // Enlever le die et ne pas mettre de message d'erreur ici
	free_table(lines);
	init_game(&game);
	game.last_time = now_seconds();
	mlx_loop_hook(game.mlx, render_loop, &game);
	mlx_loop(game.mlx);
	return (0);
}