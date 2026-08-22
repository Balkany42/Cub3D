

#include "cub3d.h"

int	is_blank(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\t')
			return (0);
		i++;
	}
	return (1);
}

// Utilisée

int	is_map_line(char *line)
{
	int i = 0;
	if (!line || !line[0])
		return (0);
	if (is_blank(line))
		return (0);
	while (line[i])
	{
		if (line[i] != '0' && line[i] != '1' && line[i] != ' '
		&& line[i] != 'N' && line[i] != '\t' && line[i] != 'S'
		&& line[i] != 'E' && line[i] != 'W')
			return(0);
		i++;
	}
	return(1);
}
//Utilisée

int	match_token(char *line, char *token)
{
	size_t	len;

	len = ft_strlen(token);
	if (ft_strncmp(line, token, len) != 0)
		return (0);
	if (line[len] != ' ' && line[len] != '\t')
		return (0);
	return (1);
}

// Utilisée

int	parse_config_line(t_game *game, char *line)
{
	int	ret;
	int	handled;

	if (is_blank(line))
		return (0);
	ret = try_texture_token(game, line, &handled);
	if (handled)
		return (ret);
	ret = try_color_token(game, line, &handled);
	if (handled)
		return (ret);
	return (parse_error(game, "identifiant inconnu ou mal forme dans la config"));
}

//Utilisée


int	parse_config(t_game *game, char **lines, int *i)
{
	while (lines[*i] && !is_map_line(lines[*i]))
	{
		if (parse_config_line(game, lines[*i]))
			return (1);
		(*i)++;
	}
	if (!lines[*i])
		return (parse_error(game, "aucune map trouvee dans le fichier"));
	if (!config_is_complete(&game->map))
		return (parse_error(game, "un ou plusieurs identifiants de config manquants"));
	return (0);
}

//Utilisée