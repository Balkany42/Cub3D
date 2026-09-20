/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tutorial_timers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrager <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 23:20:00 by mgrager           #+#    #+#             */
/*   Updated: 2026/08/31 23:20:00 by mgrager          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	handle_skip_key(t_game *game)
{
	if (game->message.msg_state == MSG_REVEALING)
	{
		game->message.msg_current_line = game->message.msg_layout.line_count;
		game->message.msg_state = MSG_HOLDING;
		game->message.msg_hold_start = now_seconds();
		return ;
	}
	try_advance_message(game, KEY_Q);
}

void	check_random_message_timer(t_game *game)
{
	int		index;
	double	now;

	if (!game->message.tutorial_done
		|| game->message.msg_state != MSG_INACTIVE)
		return ;
	now = now_seconds();
	if (now - game->message.last_random_msg_time < RANDOM_MESSAGE_INTERVAL)
		return ;
	game->rand_seed = game->rand_seed * 1103515245 + 12345;
	index = (game->rand_seed / 65536) % 8;
	start_message_display(game, &game->message.random_messages[index], KEY_Q);
}

void	check_message_auto_dismiss(t_game *game)
{
	if (!game->message.tutorial_done
		|| game->message.msg_state != MSG_HOLDING)
		return ;
	if (now_seconds() - game->message.msg_hold_start
		< MESSAGE_AUTO_DISMISS_TIME)
		return ;
	game->message.msg_state = MSG_INACTIVE;
	game->message.last_random_msg_time = now_seconds();
}

void	update_message_reveal(t_game *game)
{
	t_line_box	*box;
	double		now;

	if (game->message.msg_state != MSG_REVEALING)
		return ;
	now = now_seconds();
	if (now < game->message.msg_next_tick)
		return ;
	game->message.msg_next_tick = now + MESSAGE_REVEAL_INTERVAL;
	box = &game->message.msg_layout.line[game->message.msg_current_line];
	game->message.msg_revealed_x += 6;
	if (game->message.msg_revealed_x >= box->right - box->left)
	{
		game->message.msg_current_line++;
		game->message.msg_revealed_x = 0;
	}
	if (game->message.msg_current_line >= game->message.msg_layout.line_count)
	{
		game->message.msg_state = MSG_HOLDING;
		game->message.msg_hold_start = now;
	}
}

void	detect_message_lines(t_img *img, t_msg_layout *layout)
{
	int	y;
	int	line;

	y = 0;
	line = 0;
	while (y < img->height)
	{
		if (row_has_text(img, y))
		{
			if (y == 0 || !row_has_text(img, y - 1))
				layout->line[line].top = y;
			if (y == img->height - 1 || !row_has_text(img, y + 1))
			{
				layout->line[line].bottom = y;
				find_line_x_bounds(img, &layout->line[line]);
				line++;
			}
		}
		y++;
	}
	layout->line_count = line;
}
