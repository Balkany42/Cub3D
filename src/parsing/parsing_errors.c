
#include "cub3d.h"

/*
** Affiche un message d'erreur et retourne 1. Ne libere rien lui-meme :
** c'est l'appelant (au bout de la chaine, dans la fonction glue) qui
** doit reagir au retour 1 en appelant free_all.
*/
int	parse_error(char *msg)
{
	if (msg && msg[0])
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd(msg, 2);
		ft_putstr_fd("\n", 2);
	}
	exit (1);
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
// void	free_all(t_game *game)
// {
// 	free_config(&game->config);
// 	free_map(&game->map);
// }