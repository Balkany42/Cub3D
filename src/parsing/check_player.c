/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrager <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 22:30:00 by mgrager           #+#    #+#             */
/*   Updated: 2026/08/31 22:30:00 by mgrager          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	is_valid_char(char c)
{
	if (BONUS)
	{
		return (c == '0' || c == '1' || c == ' ' || c == 'N' || c == 'S'
			|| c == 'E' || c == 'W' || c == 'C' || c == 'O' || c == '2'
			|| c == '3');
	}
	else
		return (c == '0' || c == '1' || c == ' '
			|| c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

static void	set_player_dir(t_game *game, char c)
{
	if (c == 'N')
	{
		game->player.dir_x = 0;
		game->player.dir_y = -1;
	}
	else if (c == 'S')
	{
		game->player.dir_x = 0;
		game->player.dir_y = 1;
	}
	else if (c == 'E')
	{
		game->player.dir_x = 1;
		game->player.dir_y = 0;
	}
	else
	{
		game->player.dir_x = -1;
		game->player.dir_y = 0;
	}
}

static void	set_player_start(t_game *game, int y, int x, char c)
{
	game->player.x = x + 0.5;
	game->player.y = y + 0.5;
	set_player_dir(game, c);
	game->player.plane_x = -game->player.dir_y * FOV_FACTOR;
	game->player.plane_y = game->player.dir_x * FOV_FACTOR;
	game->map.grid[y][x] = '0';
}

static int	check_player_cell(t_game *game, int y, int x, int *found)
{
	char	c;

	c = game->map.grid[y][x];
	if (!is_valid_char(c))
		return (parse_error(game, "Invalid character in the map !"));
	if (BONUS && c == 'O')
		return (parse_error(game, "A door can't be open at start !"));
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
	{
		if (*found)
			return (parse_error(game, "More than 1 player found !"));
		set_player_start(game, y, x, c);
		*found = 1;
	}
	return (0);
}

int	check_player(t_game *game)
{
	int	x;
	int	y;
	int	found;

	found = 0;
	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (game->map.grid[y][x])
		{
			if (check_player_cell(game, y, x, &found))
				return (1);
			x++;
		}
		y++;
	}
	if (!found)
		return (parse_error(game, "No player found in the map !"));
	return (0);
}
