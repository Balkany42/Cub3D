/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_release.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrager <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 23:22:37 by mgrager           #+#    #+#             */
/*   Updated: 2026/08/30 23:26:22 by mgrager          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	key_release_1(int keycode, t_game *game)
{
	if (keycode == KEY_W)
		game->keys.w = 0;
	else if (keycode == KEY_A)
		game->keys.a = 0;
	else if (keycode == KEY_S)
		game->keys.s = 0;
	else if (keycode == KEY_D)
		game->keys.d = 0;
	else if (keycode == KEY_SPACE)
		game->keys.space = 0;
	else if (keycode == KEY_UP)
		game->keys.up = 0;
	else if (keycode == KEY_DOWN)
		game->keys.down = 0;
	else if (keycode == KEY_LEFT)
		game->keys.left = 0;
	else if (keycode == KEY_RIGHT)
		game->keys.right = 0;
	else if (keycode == KEY_P)
		game->keys.p = 0;
	return (0);
}

static int	key_release_2(int keycode, t_game *game)
{
	if (keycode == KEY_O)
		game->keys.o = 0;
	else if (keycode == KEY_I)
		game->keys.i = 0;
	else if (keycode == KEY_T)
		game->keys.t = 0;
	else if (keycode == KEY_Y)
		game->keys.y = 0;
	else if (keycode == KEY_M)
		game->keys.m = 0;
	else if (keycode == KEY_Q)
		game->keys.q = 0;
	else if (keycode == KEY_R)
		game->keys.r = 0;
	return (0);
}

int	key_release(int keycode, t_game *game)
{
	if (key_release_1(keycode, game))
		return (0);
	key_release_2(keycode, game);
	return (0);
}
