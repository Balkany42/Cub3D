
#include "cub3d.h"

int	parse_error(t_game *game, char *msg)
{
	if (msg && msg[0])
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd(msg, 2);
		ft_putstr_fd("\n", 2);
	}
	free_all(game);
	exit (1);
}
void	free_map(t_map *map)
{
	int	i;

	if (map->grid)
	{
		i = 0;
		while (map->grid[i])
		{
			free(map->grid[i]);
			i++;
		}
		free(map->grid);
		map->grid = NULL;
	}
	if (map->no_path)
	{
		free(map->no_path);
		map->no_path = NULL;
	}
	if (map->so_path)
	{
		free(map->so_path);
		map->so_path = NULL;
	}
	if (map->we_path)
	{
		free(map->we_path);
		map->we_path = NULL;
	}
	if (map->ea_path)
	{
		free(map->ea_path);
		map->ea_path = NULL;
	}
}

void	free_all(t_game *game)
{
	int	i;

	if (!game)
		return ;
	free_map(&game->map);
	if (game->mlx)
	{
		i = 0;
		while (i < 4)
		{
			if (game->tex[i].img)
			{
				mlx_destroy_image(game->mlx, game->tex[i].img);
				game->tex[i].img = NULL;
			}
			i++;
		}
		if (game->screen.img)
		{
			mlx_destroy_image(game->mlx, game->screen.img);
			game->screen.img = NULL;
		}
		if (game->win)
		{
			mlx_destroy_window(game->mlx, game->win);
			game->win = NULL;
		}
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		game->mlx = NULL;
	}
}
