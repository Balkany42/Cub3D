/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrager <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 22:06:11 by mgrager           #+#    #+#             */
/*   Updated: 2026/08/31 22:06:50 by mgrager          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	get_map_height(char **lines, int start)
{
	int	height;

	height = 0;
	while (lines[start + height])
		height++;
	return (height);
}

static int	get_map_width(char **lines, int start, int height)
{
	int	i;
	int	width;
	int	len;

	width = 0;
	i = 0;
	while (i < height)
	{
		len = ft_strlen(lines[start + i]);
		if (len > width)
			width = len;
		i++;
	}
	return (width);
}

static char	*pad_line(char *line, int width)
{
	char	*padded;
	int		len;
	int		i;

	len = ft_strlen(line);
	padded = malloc(sizeof(char) * (width + 1));
	if (!padded)
		return (NULL);
	i = 0;
	while (i < len)
	{
		padded[i] = line[i];
		i++;
	}
	while (i < width)
		padded[i++] = ' ';
	padded[width] = '\0';
	return (padded);
}

static char	**build_grid(char **lines, int start, int width, int height)
{
	char	**grid;
	int		i;

	grid = malloc(sizeof(char *) * (height + 1));
	if (!grid)
		return (NULL);
	i = 0;
	while (i < height)
	{
		grid[i] = pad_line(lines[start + i], width);
		if (!grid[i])
			return (free_table(grid), NULL);
		i++;
	}
	grid[height] = NULL;
	return (grid);
}

int	parse_map(t_game *game, char **lines, int start)
{
	game->map.height = get_map_height(lines, start);
	if (game->map.height == 0)
		return (parse_error(game, "Empty map !"));
	game->map.width = get_map_width(lines, start, game->map.height);
	game->map.grid = build_grid(lines, start,
			game->map.width, game->map.height);
	if (!game->map.grid)
		return (parse_error(game, "Map allocation failed !"));
	return (0);
}
