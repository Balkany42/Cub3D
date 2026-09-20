/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tutorial_flow.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrager <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 23:20:00 by mgrager           #+#    #+#             */
/*   Updated: 2026/08/31 23:20:00 by mgrager          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	tutorial_dismiss_key(int index)
{
	if (index == 0 || index == 5)
		return (KEY_Q);
	if (index == 1)
		return (KEY_P);
	if (index == 2)
		return (KEY_O);
	return (KEY_I);
}

void	start_message_display(t_game *game, t_img *img, int dismiss_key)
{
	game->message.current_message = img;
	game->message.dismiss_key = dismiss_key;
	detect_message_lines(img, &game->message.msg_layout);
	game->message.msg_current_line = 0;
	game->message.msg_revealed_x = 0;
	game->message.msg_state = MSG_REVEALING;
	game->message.msg_next_tick = now_seconds() + MESSAGE_REVEAL_INTERVAL;
}

void	start_tutorial(t_game *game)
{
	game->message.tutorial_index = 0;
	game->message.tutorial_done = 0;
	start_message_display(game, &game->message.tutorial_messages[0],
		tutorial_dismiss_key(0));
}

static void	advance_tutorial(t_game *game)
{
	game->message.tutorial_index++;
	if (game->message.tutorial_index >= 6)
	{
		game->message.tutorial_done = 1;
		game->message.msg_state = MSG_INACTIVE;
		return ;
	}
	start_message_display(game,
		&game->message.tutorial_messages[game->message.tutorial_index],
		tutorial_dismiss_key(game->message.tutorial_index));
}

void	try_advance_message(t_game *game, int keycode)
{
	if (game->message.msg_state != MSG_HOLDING)
		return ;
	if (game->message.dismiss_key != keycode)
		return ;
	if (!game->message.tutorial_done)
		advance_tutorial(game);
	else
	{
		game->message.msg_state = MSG_INACTIVE;
		game->message.last_random_msg_time = now_seconds();
	}
}
