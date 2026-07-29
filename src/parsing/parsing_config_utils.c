

#include "cub3d.h"

//extrait la valeur après le mot-clé (ex : le chemin après "NO"). 
//Comme éplucher une étiquette de prix pour ne garder que le chiffre.
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

//: vérifie que le fichier 
//se termine bien par .xpm. Un contrôle de badge à l'entrée.

static int	has_valid_extension(char *path)
{
	size_t	len;

	len = ft_strlen(path);
	if (len < 4)
		return (0);
	return (ft_strncmp(path + len - 4, ".xpm", 4) == 0);
}

//stocke le chemin de texture après avoir vérifié qu'il n'existe pas
// déjà et que le fichier est accessible. Comme ranger une clé dans un tiroir, 
//mais seulement si le tiroir est vide et que la clé fonctionne.
static int	set_texture(char **dst, char *value)
{
	if (*dst != NULL)
	{
		free(value);
		return (parse_error("identifiant de texture duplique"));
	}
	if (!has_valid_extension(value))
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

/*
essaie de reconnaître NO/SO/WE/EA sur la ligne et déclenche le
stockage si ça correspond. Un gabarit qu'on pose sur la ligne pour voir si ça matche.
*/
int	try_texture_token(t_config *cfg, char *line, int *handled)
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
		return (set_texture(&cfg->no, value));
	if (line[0] == 'S')
		return (set_texture(&cfg->so, value));
	if (line[0] == 'W')
		return (set_texture(&cfg->we, value));
	return (set_texture(&cfg->ea, value));
}

//vérifie qu'un bout de texte est bien un nombre entre 0 et 255.
//un videur, encore, mais pour les nombres de couleur.
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