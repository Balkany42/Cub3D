

#include "cub3d.h"

static int	is_valid_char(char c)
{
	if (BONUS)
	{
		if(c == 'C')
			parse_error(game, "Doors must be closed at init")
		return(c == '0' || c == '1' || c == ' '
			|| c == 'N' || c == 'S' || c == 'E' || c == 'W' c == 'O');
	}
	else
		return (c == '0' || c == '1' || c == ' '
			|| c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

// Utilisée
// static int	check_player(t_map *map, t_player player)
// {
// 	int	x;
// 	int	y;
// 	int	found;

// 	found = 0;
// 	y = 0;
// 	while (y < map->height)
// 	{
// 		x = 0;
// 		while (map->grid[y][x])
// 		{
// 			if (!is_valid_char(map->grid[y][x]))
// 				return (parse_error("caractere invalide dans la map"));
// 			if (map->grid[y][x] != '0' && map->grid[y][x] != '1'
// 				&& map->grid[y][x] != ' ')
// 			{
// 				if (found)
// 					return (parse_error("plusieurs joueurs dans la map"));
// 				player->player_x = x;
// 				player->player_y = y;
// 				player->player_dir = map->grid[y][x];
// 				found = 1;
// 			}
// 			x++;
// 		}
// 		y++;
// 	}
// 	if (!found)
// 		return (parse_error("aucun joueur trouve dans la map"));
// 	return (0);
// }

static int  check_player(t_game *game)
{
    int x;
    int y;
    int found;
    char    c;

    found = 0;
    y = 0;
    while (y < game->map.height)
    {
        x = 0;
        while (game->map.grid[y][x])
        {
            c = game->map.grid[y][x];

            if (!is_valid_char(c))
                return (parse_error(game, "caractere invalide dans la map"));

            if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
            {
                if (found)
                    return (parse_error(game, "plusieurs joueurs dans la map"));

                /* position centrée */
                game->player.x = x + 0.5;
                game->player.y = y + 0.5;

                /* direction */
                if (c == 'N')
                    game->player.dir_x = 0, game->player.dir_y = -1;
                else if (c == 'S')
                    game->player.dir_x = 0, game->player.dir_y = 1;
                else if (c == 'E')
                    game->player.dir_x = 1, game->player.dir_y = 0;
                else
                    game->player.dir_x = -1, game->player.dir_y = 0;

                /* plan caméra */
                game->player.plane_x = - game->player.dir_y * FOV_FACTOR;
                game->player.plane_y =  game->player.dir_x * FOV_FACTOR;

                /* on nettoie la map */
                game->map.grid[y][x] = '0';

                found = 1;
            }
            x++;
        }
        y++;
    }
    if (!found)
        return (parse_error(game, "aucun joueur trouve dans la map"));
    return (0);
}


// Utilisée

static int	flood_fill(char **grid, int height, int width, int y, int x)
{
	if (y < 0 || y >= height || x < 0 || x >= width)
		return (1);
	if (grid[y][x] == '1' || grid[y][x] == 'V')
		return (0);
	if (grid[y][x] == ' ')
		return (1);
	grid[y][x] = 'V';
	if (flood_fill(grid, height, width, y - 1, x))
		return (1);
	if (flood_fill(grid, height, width, y + 1, x))
		return (1);
	if (flood_fill(grid, height, width, y, x - 1))
		return (1);
	if (flood_fill(grid, height, width, y, x + 1))
		return (1);
	return (0);
}

// Utilisée

static int	check_closed(t_game *game)
{
	char	**copy;
	int		i;
	int		leak;

	copy = malloc(sizeof(char *) * (game->map.height + 1));
	if (!copy)
		return (parse_error(game, "echec allocation copie de map"));
	i = 0;
	while (i < game->map.height)
	{
		copy[i] = ft_strdup(game->map.grid[i]);
		i++;
	}
	copy[i] = NULL;
	leak = flood_fill(copy, game->map.height, game->map.width,
			game->player.y, game->player.x);
	i = -1;
	while (copy[++i])
		free(copy[i]);
	free(copy);
	if (leak)
		return (parse_error(game, "map non fermee"));
	return (0);
}
// Utilisée

int	check_map(t_game *game)
{
	if (check_player(game))
		return (1);
	if (check_closed(game))
		return (1);
	return (0);
}

// Utilisée