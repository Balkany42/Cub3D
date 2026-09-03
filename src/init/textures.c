/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrager <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 22:33:55 by mgrager           #+#    #+#             */
/*   Updated: 2026/08/30 22:33:57 by mgrager          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	load_textures(t_game *game)
{
	load_one(game, &game->tex[TEX_NO], game->map.no_path);
	load_one(game, &game->tex[TEX_SO], game->map.so_path);
	load_one(game, &game->tex[TEX_WE], game->map.we_path);
	load_one(game, &game->tex[TEX_EA], game->map.ea_path);
}

void	load_crawl(t_game *game)
{
	load_one(game, &game->crawl_tex, "textures/007_crawl/crawl.xpm");
}

void	load_basics(t_game *game)
{
	load_one(game, &game->img_bonus.basics[0],
		"textures/004_basics/black.xpm");
	load_one(game, &game->img_bonus.basics[1],
		"textures/004_basics/door.xpm");
	load_one(game, &game->img_bonus.basics[2],
		"textures/004_basics/matrix.xpm");
}
