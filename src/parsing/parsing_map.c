
#include "cub3d.h"

static int	get_map_height(char **lines, int start)
{
	int	height;

	height = 0;
	while (lines[start + height])
		height++;
	return (height);
}

static int	get_map_width(char **lines, int start, int height)
{
	int	i;
	int	width;
	int	len;

	width = 0;
	i = 0;
	while (i < height)
	{
		len = ft_strlen(lines[start + i]);
		if (len > width)
			width = len;
		i++;
	}
	return (width);
}

static char	*pad_line(char *line, int width)
{
	char	*padded;
	int		len;
	int		i;

	len = ft_strlen(line);
	padded = malloc(sizeof(char) * (width + 1));
	if (!padded)
		return (NULL);
	i = 0;
	while (i < len)
	{
		padded[i] = line[i];
		i++;
	}
	while (i < width)
		padded[i++] = ' ';
	padded[width] = '\0';
	return (padded);
}

static char	**build_grid(char **lines, int start, int width, int height)
{
	char	**grid;
	int		i;

	grid = malloc(sizeof(char *) * (height + 1));
	if (!grid)
		return (NULL);
	i = 0;
	while (i < height)
	{
		grid[i] = pad_line(lines[start + i], width);
		if (!grid[i])
			return (NULL);
		i++;
	}
	grid[height] = NULL;
	return (grid);
}

/*
** Point d'entree. 'start' est l'index de la premiere ligne de map
** (celui laisse par parse_config). Remplit map->grid/width/height.
*/
int	parse_map(t_map *map, char **lines, int start)
{
	map->height = get_map_height(lines, start);
	if (map->height == 0)
		return (parse_error("map vide"));
	map->width = get_map_width(lines, start, map->height);
	map->grid = build_grid(lines, start, map->width, map->height);
	if (!map->grid)
		return (parse_error("echec allocation de la map"));
	return (0);
}