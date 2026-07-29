

#include "cub3d.h"

static int	is_valid_char(char c)
{
	return (c == '0' || c == '1' || c == ' '
		|| c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

/*
** Parcourt toute la grille : verifie que chaque caractere est valide,
** et repere la position + orientation du joueur (un seul autorise).
*/
static int	check_player(t_map *map)
{
	int	x;
	int	y;
	int	found;

	found = 0;
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (map->grid[y][x])
		{
			if (!is_valid_char(map->grid[y][x]))
				return (parse_error("caractere invalide dans la map"));
			if (map->grid[y][x] != '0' && map->grid[y][x] != '1'
				&& map->grid[y][x] != ' ')
			{
				if (found)
					return (parse_error("plusieurs joueurs dans la map"));
				map->player_x = x;
				map->player_y = y;
				map->player_dir = map->grid[y][x];
				found = 1;
			}
			x++;
		}
		y++;
	}
	if (!found)
		return (parse_error("aucun joueur trouve dans la map"));
	return (0);
}

/*
** Flood fill recursif sur une copie de la grille. Retourne 1 des qu'une
** fuite est detectee (bord de tableau ou case vide atteinte), 0 sinon.
*/
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

static int	check_closed(t_map *map)
{
	char	**copy;
	int		i;
	int		leak;

	copy = malloc(sizeof(char *) * (map->height + 1));
	if (!copy)
		return (parse_error("echec allocation copie de map"));
	i = 0;
	while (i < map->height)
	{
		copy[i] = ft_strdup(map->grid[i]);
		i++;
	}
	copy[i] = NULL;
	leak = flood_fill(copy, map->height, map->width,
			map->player_y, map->player_x);
	i = -1;
	while (copy[++i])
		free(copy[i]);
	free(copy);
	if (leak)
		return (parse_error("map non fermee"));
	return (0);
}

/*
** Point d'entree. A appeler une fois parse_map termine.
*/
int	check_map(t_map *map)
{
	if (check_player(map))
		return (1);
	if (check_closed(map))
		return (1);
	return (0);
}