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

	ft_memset(&game, 0, sizeof(t_game));
	if (argc != 2)
		parse_error(&game, "usage: ./cub3D <map.cub>");
	if (has_valid_extension(argv[1]))
		parse_error(&game, "map file must have a .cub extension");
	if (check_file(argv[1]))
		parse_error(&game, ""); // Commentaire pour pas oublier le message d'erreur.
	lines = read_file(argv[1]);
	if(!lines)
		parse_error(&game, "failed to read file"); // Ne pas oublier de remplacer die
	if(parse(lines, &game))
	{
		free_table(lines);
		parse_error(&game, ""); // Enlever le die et ne pas mettre de message d'erreur ici
	}
	init_game(&game);
	game.last_time = now_seconds();
	mlx_loop_hook(game.mlx, render_loop, &game);
	mlx_loop(game.mlx);
	return (0);
}