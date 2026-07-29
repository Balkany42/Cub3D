
#include "cub3d.h"

/*
** Affiche un message d'erreur et retourne 1. Ne libere rien lui-meme :
** c'est l'appelant (au bout de la chaine, dans la fonction glue) qui
** doit reagir au retour 1 en appelant free_all.
*/
int	parse_error(char *msg)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd("\n", 2);
	return (1);
}

void	free_config(t_config *cfg)
{
	if (cfg->no)
		free(cfg->no);
	if (cfg->so)
		free(cfg->so);
	if (cfg->we)
		free(cfg->we);
	if (cfg->ea)
		free(cfg->ea);
	cfg->no = NULL;
	cfg->so = NULL;
	cfg->we = NULL;
	cfg->ea = NULL;
}

void	free_map(t_map *map)
{
	int	i;

	if (!map->grid)
		return ;
	i = 0;
	while (map->grid[i])
	{
		free(map->grid[i]);
		i++;
	}
	free(map->grid);
	map->grid = NULL;
}

/*
** A appeler depuis la fonction glue des qu'une etape du parsing
** (config ou map) retourne 1. Libere tout ce qui a pu etre alloue
** avant l'erreur, quelle que soit l'etape ou ca a plante.
*/
void	free_all(t_game *game)
{
	free_config(&game->config);
	free_map(&game->map);
}