/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_config_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrager <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 05:22:04 by mgrager           #+#    #+#             */
/*   Updated: 2026/08/31 05:23:01 by mgrager          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*get_value(char *line, char *token)
{
	char	*trimmed;

	trimmed = ft_strtrim(line + ft_strlen(token), " \t");
	if (!trimmed || !trimmed[0])
	{
		free(trimmed);
		return (NULL);
	}
	return (trimmed);
}

static int	has_valid_xpm_extension(char *path)
{
	size_t	len;

	len = ft_strlen(path);
	if (len < 4)
		return (0);
	return (ft_strncmp(path + len - 4, ".xpm", 4) == 0);
}

static int	set_texture(t_game *game, char **dst, char *value)
{
	int	fd;

	if (*dst != NULL)
		return (free(value), parse_error(game, "Duplicated texture token !"));
	if (ft_strlen_break(value, MAX_PATH_LEN))
		return (free(value), parse_error(game, "Texture path too long !"));
	if (!has_valid_xpm_extension(value))
		return (free(value), parse_error(game, "Texture must be .xpm !"));
	fd = open(value, O_RDONLY);
	if (fd == -1)
		return (free(value), parse_error(game, "Missing texture file !"));
	close(fd);
	*dst = value;
	return (0);
}

int	try_texture_token(t_game *game, char *line, int *handled)
{
	char	*value;

	*handled = 1;
	if (match_token(line, "NO"))
		value = get_value(line, "NO");
	else if (match_token(line, "SO"))
		value = get_value(line, "SO");
	else if (match_token(line, "WE"))
		value = get_value(line, "WE");
	else if (match_token(line, "EA"))
		value = get_value(line, "EA");
	else
	{
		*handled = 0;
		return (0);
	}
	if (!value)
		return (parse_error(game, "No path after token !"));
	if (line[0] == 'N')
		return (set_texture(game, &game->map.no_path, value));
	if (line[0] == 'S')
		return (set_texture(game, &game->map.so_path, value));
	if (line[0] == 'W')
		return (set_texture(game, &game->map.we_path, value));
	return (set_texture(game, &game->map.ea_path, value));
}

int	parse_component(char *str, int *out)
{
	int	i;

	i = 0;
	if (!str[0])
		return (1);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (1);
		i++;
	}
	*out = ft_atoi(str);
	if (*out < 0 || *out > 255)
		return (1);
	return (0);
}
