#include "cub3d.h"

static int	set_color(t_game *game, int dst[3], char *value, int *flag)
{
	char	**parts;
	int		i;

	if (*flag)
	{
		free(value);
		return (parse_error(game, "identifiant de couleur duplique"));
	}
	parts = ft_split(value, ','); // On a besoin de pouvoir mettre des espaces ou des tabs dans les couleurs
	free(value);
	if (!parts || !parts[0] || !parts[1] || !parts[2] || parts[3])
		return (parse_error(game, "une couleur doit avoir exactement 3 composantes"));
	i = 0;
	while (i < 3)
	{
		if (parse_component(parts[i], &dst[i]))
			return (parse_error(game, "composante de couleur invalide (attendu 0-255)"));
		i++;
	}
	i = -1;
	while (parts[++i])
		free(parts[i]);
	free(parts);
	*flag = 1;
	return (0);
}
// Utilisée

int	try_color_token(t_game *game, char *line, int *handled)
{
	char	*value;
	int		ret;

	*handled = 1;
	if (match_token(line, "F"))
	{
		if (!(value = get_value(line, "F")))
			return (parse_error(game, "valeur manquante pour F"));
		ret = set_color(game, game->map.f, value, &game->map.f_set);
		if (!ret)
			game->map.floor_color = (game->map.f[0] << 16) | (game->map.f[1] << 8) | game->map.f[2];
		return (ret);
	}
	if (match_token(line, "C"))
	{
		if (!(value = get_value(line, "C")))
			return (parse_error(game, "valeur manquante pour C"));
		ret = set_color(game, game->map.c, value, &game->map.c_set);
		if (!ret)
			game->map.ceil_color = (game->map.c[0] << 16) | (game->map.c[1] << 8) | game->map.c[2];
		return (ret);
	}
	*handled = 0;
	return (0);
}
// Utilisée
int	config_is_complete(t_map *map)
{
	return (map->no_path != NULL && map->so_path != NULL && map->we_path != NULL
		&& map->ea_path != NULL && map->f_set && map->c_set);
}