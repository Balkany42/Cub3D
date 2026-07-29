

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

/*
** Retourne 1 si la ligne commence par un caractere de map valide
** (0, 1, espace, N, S, E, W) -> sert a detecter le debut de la map.
*/
int	is_map_line(char *line)
{
	if (!line || !line[0])
		return (0);
	if (is_blank(line))
		return (0);
	return (line[0] == '0' || line[0] == '1' || line[0] == ' '
		|| line[0] == 'N' || line[0] == 'S'
		|| line[0] == 'E' || line[0] == 'W');
}

/*
** Verifie que 'line' commence par 'token' suivi d'un espace/tab,
** pour eviter que "NO" ne matche a tort "NORTH" ou similaire.
*/
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

/*
** Redirige une ligne de config vers le bon setter (texture ou couleur).
** Retourne 0 si succes, 1 si erreur (l'appelant doit free/quitter).
*/
int	parse_config_line(t_config *cfg, char *line)
{
	int	ret;
	int	handled;

	if (is_blank(line))
		return (0);
	ret = try_texture_token(cfg, line, &handled);
	if (handled)
		return (ret);
	ret = try_color_token(cfg, line, &handled);
	if (handled)
		return (ret);
	return (parse_error("identifiant inconnu ou mal forme dans la config"));
}

/*
** Point d'entree principal. Avance *i dans les lignes de config et
** s'arrete des qu'il atteint la premiere ligne de map. Retourne 0 si ok.
*/
int	parse_config(t_config *cfg, char **lines, int *i)
{
	while (lines[*i] && !is_map_line(lines[*i]))
	{
		if (parse_config_line(cfg, lines[*i]))
			return (1);
		(*i)++;
	}
	if (!lines[*i])
		return (parse_error("aucune map trouvee dans le fichier"));
	if (!config_is_complete(cfg))
		return (parse_error("un ou plusieurs identifiants de config manquants"));
	return (0);
}