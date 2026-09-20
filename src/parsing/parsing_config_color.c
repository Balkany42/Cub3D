/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_config_color.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrager <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 23:00:26 by mgrager           #+#    #+#             */
/*   Updated: 2026/08/31 21:53:18 by mgrager          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	set_color(t_game *game, int dst[3], char *value, int *flag)
{
	char	**parts;
	char	*trimmed;
	int		i;

	if (*flag)
		return (free(value), parse_error(game, "Colour token duplicated !"));
	parts = ft_split(value, ',');
	free(value);
	if (!parts || !parts[0] || !parts[1] || !parts[2] || parts[3])
		return (free_table(parts), parse_error(game,
				"A colour must have 3 components !"));
	i = 0;
	while (i < 3)
	{
		trimmed = ft_strtrim(parts[i], " \t");
		if (!trimmed || parse_component(trimmed, &dst[i]))
			return (free(trimmed), free_table(parts), parse_error(game,
					"Invalid colour component ! (expected 0-255)"));
		free(trimmed);
		i++;
	}
	free_table(parts);
	*flag = 1;
	return (0);
}

static int	try_floor_color(t_game *game, char *line)
{
	char	*value;
	int		ret;

	value = get_value(line, "F");
	if (!value)
		return (parse_error(game, "Missing value for F !"));
	ret = set_color(game, game->map.f, value, &game->map.f_set);
	if (!ret)
		game->map.floor_color = (game->map.f[0] << 16)
			| (game->map.f[1] << 8) | game->map.f[2];
	return (ret);
}

static int	try_ceil_color(t_game *game, char *line)
{
	char	*value;
	int		ret;

	value = get_value(line, "C");
	if (!value)
		return (parse_error(game, "Missing value for C !"));
	ret = set_color(game, game->map.c, value, &game->map.c_set);
	if (!ret)
		game->map.ceil_color = (game->map.c[0] << 16)
			| (game->map.c[1] << 8) | game->map.c[2];
	return (ret);
}

int	try_color_token(t_game *game, char *line, int *handled)
{
	*handled = 1;
	if (match_token(line, "F"))
		return (try_floor_color(game, line));
	if (match_token(line, "C"))
		return (try_ceil_color(game, line));
	*handled = 0;
	return (0);
}

int	config_is_complete(t_map *map)
{
	return (map->no_path != NULL && map->so_path != NULL && map->we_path != NULL
		&& map->ea_path != NULL && map->f_set && map->c_set);
}
