#include "cub3d.h"

int parse(char **lines, t_map *map, t_player *player)
{
    int i = 0;

    if (parse_config(map, lines, &i))
        return (1);
    if (parse_map(map, lines, i))
        return (1);
    if (check_map(map, player))
        return (1);
    return (0);
}
