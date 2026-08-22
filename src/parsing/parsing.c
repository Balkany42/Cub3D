#include "cub3d.h"

int parse(char **lines, t_game *game)
{
    int i = 0;

    if (parse_config(game, lines, &i))
        return (1);
    if (parse_map(game, lines, i))
        return (1);
    if (check_map(game))
        return (1);
    return (0);
}
