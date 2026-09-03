/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrager <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 22:48:03 by mgrager           #+#    #+#             */
/*   Updated: 2026/08/30 22:48:46 by mgrager          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	new_img(t_game *game, t_img *img, int width, int height)
{
	img->img = mlx_new_image(game->mlx, width, height);
	if (!img->img)
		parse_error(game, "mlx_new_image failed !");
	img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->line_len,
			&img->endian);
	img->width = width;
	img->height = height;
}

static int	close_win(t_game *game)
{
	free_all(game);
	exit(0);
	return (0);
}

static void	init_hooks(t_game *game)
{
	mlx_hook(game->win, 17, 0, close_win, game);
	mlx_hook(game->win, 2, 1L << 0, key_press, game);
	mlx_hook(game->win, 3, 1L << 1, key_release, game);
	if (BONUS)
	{
		mlx_hook(game->win, 4, 1L << 2, scroll_hook, game);
		mlx_hook(game->win, 6, 1L << 6, mouse_hook, game);
	}
}

int	init_game(t_game *game)
{
	game->mlx = mlx_init();
	game->light = -1;
	game->mouse_ref = WIN_WIDTH / 2;
	game->ghost_state = ABSENT;
	game->control = -1;
	if (!game->mlx)
		parse_error(game, "mlx_init failed !");
	game->win = mlx_new_window(game->mlx, WIN_WIDTH, WIN_HEIGHT, "cub3D");
	if (!game->win)
		parse_error(game, "mlx_new_window failed !");
	new_img(game, &game->screen, WIN_WIDTH, WIN_HEIGHT);
	load_textures(game);
	if (BONUS)
	{
		load_textures_bonus(game);
		init_matrix_textures(game);
		start_crawl(game);
		load_crawl(game);
	}
	init_hooks(game);
	return (0);
}

double	now_seconds(void)
{
	static double	last = 0.0;
	struct timeval	tv;
	double			now;

	gettimeofday(&tv, NULL);
	now = (double)tv.tv_sec + (double)tv.tv_usec / 1000000.0;
	if (now < last)
		now = last;
	last = now;
	return (now);
}
