

#include "cub3d.h"

//découpe "R,G,B" en trois morceaux et vérifie chacun. Comme
//trier trois billes de couleurs différentes dans trois boîtes, 
//en rejetant celles qui ne sont pas rondes
static int	set_color(int dst[3], char *value, int *flag)
{
	char	**parts;
	int		i;

	if (*flag)
	{
		free(value);
		return (parse_error("identifiant de couleur duplique"));
	}
	parts = ft_split(value, ',');
	free(value);
	if (!parts || !parts[0] || !parts[1] || !parts[2] || parts[3])
		return (parse_error("une couleur doit avoir exactement 3 composantes"));
	i = 0;
	while (i < 3)
	{
		if (parse_component(parts[i], &dst[i]))
			return (parse_error("composante de couleur invalide (attendu 0-255)"));
		i++;
	}
	i = -1;
	while (parts[++i])
		free(parts[i]);
	free(parts);
	*flag = 1;
	return (0);
}

/*
** reconnaît F ou C sur la ligne et déclenche set_color
Même logique que try_texture_token, mais côté couleurs.
*/
int	try_color_token(t_config *cfg, char *line, int *handled)
{
	char	*value;

	*handled = 1;
	if (match_token(line, "F"))
	{
		if (!(value = get_value(line, "F")))
			return (parse_error("valeur manquante pour F"));
		return (set_color(cfg->f, value, &cfg->f_set));
	}
	if (match_token(line, "C"))
	{
		if (!(value = get_value(line, "C")))
			return (parse_error("valeur manquante pour C"));
		return (set_color(cfg->c, value, &cfg->c_set));
	}
	*handled = 0;
	return (0);
}

/*vérifie en fin de parsing que les 6 éléments (4 textures + 2
ccouleurs) sont bien remplis. Une checklist avant décollage
: si une case manque, on ne décolle pas.*/

int	config_is_complete(t_config *cfg)
{
	return (cfg->no != NULL && cfg->so != NULL && cfg->we != NULL
		&& cfg->ea != NULL && cfg->f_set && cfg->c_set);
}