/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ghosts.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrager <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 22:43:44 by mgrager           #+#    #+#             */
/*   Updated: 2026/08/30 22:45:32 by mgrager          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	load_ghosts_noframes(t_game *game)
{
	load_numbered_family(game, game->img_bonus.ghost_noframe_blue,
		"textures/003_ghosts/noframe/blue/", 2);
	load_numbered_family(game, game->img_bonus.ghost_noframe_eyes,
		"textures/003_ghosts/noframe/eyes/", 4);
	load_numbered_family(game, game->img_bonus.ghost_noframe_orange,
		"textures/003_ghosts/noframe/orange/", 8);
	load_numbered_family(game, game->img_bonus.ghost_noframe_pink,
		"textures/003_ghosts/noframe/pink/", 8);
	load_numbered_family(game, game->img_bonus.ghost_noframe_red,
		"textures/003_ghosts/noframe/red/", 8);
	load_numbered_family(game, game->img_bonus.ghost_noframe_cyan,
		"textures/003_ghosts/noframe/cyan/", 8);
	load_numbered_family(game, game->img_bonus.ghost_noframe_white,
		"textures/003_ghosts/noframe/white/", 2);
}

void	load_ghosts_frames(t_game *game)
{
	load_numbered_family(game, game->img_bonus.ghost_frame_blue,
		"textures/003_ghosts/frame/blue/", 2);
	load_numbered_family(game, game->img_bonus.ghost_frame_eyes,
		"textures/003_ghosts/frame/eyes/", 4);
	load_numbered_family(game, game->img_bonus.ghost_frame_orange,
		"textures/003_ghosts/frame/orange/", 8);
	load_numbered_family(game, game->img_bonus.ghost_frame_pink,
		"textures/003_ghosts/frame/pink/", 8);
	load_numbered_family(game, game->img_bonus.ghost_frame_red,
		"textures/003_ghosts/frame/red/", 8);
	load_numbered_family(game, game->img_bonus.ghost_frame_cyan,
		"textures/003_ghosts/frame/cyan/", 8);
	load_numbered_family(game, game->img_bonus.ghost_frame_white,
		"textures/003_ghosts/frame/white/", 2);
}

void	load_randoms(t_game *game)
{
	load_numbered_family(game, game->img_bonus.rand_braille,
		"textures/002_alphabets/rand_braille/", 51);
	load_numbered_family(game, game->img_bonus.rand_digit,
		"textures/002_alphabets/rand_digit/", 10);
	load_numbered_family(game, game->img_bonus.rand_latin,
		"textures/002_alphabets/rand_latin/", 52);
	load_numbered_family(game, game->img_bonus.rand_ru,
		"textures/002_alphabets/rand_ru/", 77);
	load_numbered_family(game, game->img_bonus.rand_sign,
		"textures/002_alphabets/rand_sign/", 24);
}
