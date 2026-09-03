/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrager <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 23:44:26 by mgrager           #+#    #+#             */
/*   Updated: 2026/09/03 03:47:12 by mgrager          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	key_press_1(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
	{
		free_all(game);
		exit(0);
	}
	else if (keycode == KEY_W)
		game->keys.w = 1;
	else if (keycode == KEY_A)
		game->keys.a = 1;
	else if (keycode == KEY_S)
		game->keys.s = 1;
	else if (keycode == KEY_D)
		game->keys.d = 1;
	else if (keycode == KEY_UP)
		game->keys.up = 1;
	else if (keycode == KEY_DOWN)
		game->keys.down = 1;
	else if (keycode == KEY_LEFT)
		game->keys.left = 1;
	else if (keycode == KEY_RIGHT)
		game->keys.right = 1;
	return (0);
}

static int	key_press_2(int keycode, t_game *game)
{
	if (BONUS && keycode == KEY_SPACE)
	{
		if (!game->keys.space)
			toggle_door(game);
		game->keys.space = 1;
	}
	else if (BONUS && keycode == KEY_P)
	{
		if (!game->keys.p)
		{
			game->light = -game->light;
			game->light_used = 1;
			try_advance_message(game, keycode);
			if (game->light > 0)
			{
				game->matrix_state = MATRIX_WORKING;
				init_state_texture(game);
			}
			else
				game->matrix_state = MATRIX_OFF;
		}
		game->keys.p = 1;
	}
	return (0);
}

static int	key_press_3(int keycode, t_game *game)
{
	if (BONUS && keycode == KEY_O)
	{
		if (!game->keys.o && game->light_used > 0)
		{
			update_phantom_state(game, 1);
			try_advance_message(game, keycode);
		}
		game->keys.o = 1;
	}
	else if (BONUS && keycode == KEY_I)
	{
		if (!game->keys.i && game->light_used > 0)
		{
			update_phantom_state(game, 2);
			try_advance_message(game, keycode);
		}
		game->keys.i = 1;
	}
	else if (BONUS && keycode == KEY_T)
	{
		if (!game->keys.t)
			update_matrix_pill_state(game, MATRIX_BLUE_PILL);
		game->keys.t = 1;
	}
	return (0);
}

static int	key_press_4(int keycode, t_game *game)
{
	if (BONUS && keycode == KEY_Y)
	{
		if (!game->keys.y)
			update_matrix_pill_state(game, MATRIX_RED_PILL);
		game->keys.y = 1;
	}
	else if (BONUS && keycode == KEY_M)
	{
		if (!game->keys.m)
			game->control = -game->control;
		game->keys.m = 1;
	}
	else if (BONUS && keycode == KEY_Q)
	{
		if (!game->keys.q)
			handle_skip_key(game);
		game->keys.q = 1;
	}
	return (0);
}

int	key_press(int keycode, t_game *game)
{
	key_press_1(keycode, game);
	key_press_2(keycode, game);
	key_press_3(keycode, game);
	key_press_4(keycode, game);
	if (BONUS && keycode == KEY_R)
	{
		if (!game->keys.r && game->matrix_state != MATRIX_WORKING)
		{
			game->matrix_state = MATRIX_WORKING;
			init_state_texture(game);
		}
		game->keys.r = 1;
	}
	return (0);
}
