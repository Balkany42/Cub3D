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

//Utilisée

static int	has_valid_xpm_extension(char *path)
{
	size_t	len;

	len = ft_strlen(path);
	if (len < 4)
		return (0);
	return (ft_strncmp(path + len - 4, ".xpm", 4) == 0);
}

// Utilisée

static int	set_texture(char **dst, char *value)
{
	if (*dst != NULL)
	{
		free(value);
		return (parse_error("identifiant de texture duplique"));
	}
	if (!has_valid_xpm_extension(value))
	{
		free(value);
		return (parse_error("le fichier de texture doit etre en .xpm"));
	}
	if (access(value, F_OK | R_OK) != 0)
	{
		free(value);
		return (parse_error("fichier de texture introuvable ou illisible"));
	}
	*dst = value;
	return (0);
}
// Utilisée

int	try_texture_token(t_map *map, char *line, int *handled)
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
		return (parse_error("valeur manquante pour un identifiant de texture"));
	if (line[0] == 'N')
		return (set_texture(&map->no_path, value));
	if (line[0] == 'S')
		return (set_texture(&map->so_path, value));
	if (line[0] == 'W')
		return (set_texture(&map->we_path, value));
	return (set_texture(&map->ea_path, value));
}

//Utilisée

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

//Utilisée