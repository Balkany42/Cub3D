/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrager <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 00:15:37 by mgrager           #+#    #+#             */
/*   Updated: 2026/08/31 00:16:02 by mgrager          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_game	game;
	char	**lines;

	ft_memset(&game, 0, sizeof(t_game));
	if (argc != 2)
		parse_error(&game, "Usage: ./cub3D <map.cub> !");
	if (ft_strlen_break(argv[1], MAX_PATH_LEN))
		parse_error(&game, "Map file path is too long !");
	if (has_valid_extension(argv[1]))
		parse_error(&game, "Map file must have a .cub extension !");
	if (check_file(argv[1]))
		parse_error(&game, "Unable to open the map file !");
	lines = read_file(argv[1]);
	if (!lines)
		parse_error(&game, "Failed to read file !");
	game.lines = lines;
	if (parse(lines, &game))
		parse_error(&game, "Parsing Error... Shouldn't happen !");
	init_game(&game);
	game.last_time = now_seconds();
	mlx_loop_hook(game.mlx, render_loop, &game);
	mlx_loop(game.mlx);
	return (0);
}
