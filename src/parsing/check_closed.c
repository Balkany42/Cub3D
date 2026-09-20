/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_closed.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrager <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 22:59:29 by mgrager           #+#    #+#             */
/*   Updated: 2026/08/30 22:59:29 by mgrager          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	flood_fill(t_flood_grid *g, int y, int x)
{
	if (y < 0 || y >= g->height || x < 0 || x >= g->width)
		return (1);
	if (g->grid[y][x] == '1' || g->grid[y][x] == 'V')
		return (0);
	if (g->grid[y][x] == ' ')
		return (1);
	g->grid[y][x] = 'V';
	if (flood_fill(g, y - 1, x))
		return (1);
	if (flood_fill(g, y + 1, x))
		return (1);
	if (flood_fill(g, y, x - 1))
		return (1);
	if (flood_fill(g, y, x + 1))
		return (1);
	return (0);
}

static int	copy_grid(t_game *game, t_flood_grid *g)
{
	int	i;

	g->grid = malloc(sizeof(char *) * (game->map.height + 1));
	if (!g->grid)
		return (parse_error(game, "Map copy failed !"));
	g->height = game->map.height;
	g->width = game->map.width;
	i = 0;
	while (i < game->map.height)
	{
		g->grid[i] = ft_strdup(game->map.grid[i]);
		if (!g->grid[i])
			return (free_table(g->grid), parse_error(game,
					"Map copy failed !"));
		i++;
	}
	g->grid[i] = NULL;
	return (0);
}

static int	check_closed(t_game *game)
{
	t_flood_grid	g;
	int				leak;

	if (copy_grid(game, &g))
		return (1);
	leak = flood_fill(&g, game->player.y, game->player.x);
	free_table(g.grid);
	if (leak)
		return (parse_error(game, "Map not closed !"));
	return (0);
}

static int	check_zones_reachable(t_game *game)
{
	t_flood_grid	g;
	int				y;
	int				x;

	if (copy_grid(game, &g))
		return (1);
	flood_fill(&g, game->player.y, game->player.x);
	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			if ((game->map.grid[y][x] == '2' || game->map.grid[y][x] == '3')
				&& g.grid[y][x] != 'V')
				return (free_table(g.grid), parse_error(game,
						"Matrix or Monument not accessible !"));
			x++;
		}
		y++;
	}
	free_table(g.grid);
	return (0);
}

int	check_map(t_game *game)
{
	if (check_player(game))
		return (1);
	if (check_closed(game))
		return (1);
	if (BONUS)
	{
		if (check_doors(game))
			return (1);
		if (check_monuments(game, 3, 2))
			return (1);
		if (check_matrix(game, 7, 3))
			return (1);
		if (game->monument_count < 1 || game->matrix_count < 1
			|| game->matrix_count > 1)
			parse_error(game, "Incorrect number of Matrix or Monuments !");
		if (check_zones_reachable(game))
			return (1);
	}
	return (0);
}
