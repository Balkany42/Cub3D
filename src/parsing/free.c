/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrager <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 00:50:15 by mgrager           #+#    #+#             */
/*   Updated: 2026/08/31 05:19:53 by mgrager          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	parse_error(t_game *game, char *msg)
{
	if (msg && msg[0])
	{
		ft_putstr_fd(RED, 2);
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd(msg, 2);
		ft_putstr_fd("\n", 2);
		ft_putstr_fd(RESET, 2);
	}
	free_all(game);
	exit (1);
}

static void	free_map(t_map *map)
{
	free_table(map->grid);
	map->grid = NULL;
	free(map->no_path);
	map->no_path = NULL;
	free(map->so_path);
	map->so_path = NULL;
	free(map->we_path);
	map->we_path = NULL;
	free(map->ea_path);
	map->ea_path = NULL;
}

static void	free_mandatory_textures(t_game *game)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (game->tex[i].img)
		{
			mlx_destroy_image(game->mlx, game->tex[i].img);
			game->tex[i].img = NULL;
		}
		i++;
	}
}

static void	free_window(t_game *game)
{
	if (game->screen.img)
	{
		mlx_destroy_image(game->mlx, game->screen.img);
		game->screen.img = NULL;
	}
	if (game->win)
	{
		mlx_destroy_window(game->mlx, game->win);
		game->win = NULL;
	}
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	game->mlx = NULL;
}

void	free_all(t_game *game)
{
	if (!game)
		return ;
	free_table(game->lines);
	game->lines = NULL;
	free_map(&game->map);
	if (game->mlx)
	{
		free_mandatory_textures(game);
		if (BONUS)
			free_img_bonus(game);
		free_window(game);
	}
}
