/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrager <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 22:46:46 by mgrager           #+#    #+#             */
/*   Updated: 2026/08/30 22:46:47 by mgrager          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	load_textures_messages(t_game *game)
{
	load_numbered_family(game, game->img_bonus.blue_braille,
		"textures/001_messages/blue_braille/", 7);
	load_numbered_family(game, game->img_bonus.red_braille,
		"textures/001_messages/red_braille/", 7);
	load_numbered_family(game, game->img_bonus.blue_eng,
		"textures/001_messages/blue_eng/", 7);
	load_numbered_family(game, game->img_bonus.red_eng,
		"textures/001_messages/red_eng/", 7);
	load_numbered_family(game, game->img_bonus.blue_fr,
		"textures/001_messages/blue_fr/", 7);
	load_numbered_family(game, game->img_bonus.red_fr,
		"textures/001_messages/red_fr/", 7);
	load_numbered_family(game, game->img_bonus.blue_ru,
		"textures/001_messages/blue_ru/", 7);
	load_numbered_family(game, game->img_bonus.red_ru,
		"textures/001_messages/red_ru/", 7);
	load_numbered_family(game, game->img_bonus.creator,
		"textures/001_messages/creators/", 3);
}

void	load_textures_bonus(t_game *game)
{
	load_textures_messages(game);
	load_randoms(game);
	load_ghosts_frames(game);
	load_ghosts_noframes(game);
	load_basics(game);
	load_numbered_family(game, game->message.tutorial_messages,
		"textures/005_tutorial/", 6);
	load_numbered_family(game, game->message.random_messages,
		"textures/006_random/", 8);
}
