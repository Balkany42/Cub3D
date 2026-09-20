/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_loop.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrager <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 23:20:00 by mgrager           #+#    #+#             */
/*   Updated: 2026/08/31 23:20:00 by mgrager          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	render_loop_crawl(t_game *game, double now)
{
	render_crawl(game);
	mlx_put_image_to_window(game->mlx, game->win, game->screen.img, 0, 0);
	game->last_time = now;
	return (0);
}

void	render_frame(t_game *game)
{
	int	x;

	render_floor_ceiling(game);
	x = 0;
	while (x < WIN_WIDTH)
	{
		cast_column(game, x);
		x++;
	}
	if (BONUS)
	{
		draw_minimap(game);
		if (BONUS && game->control > 0)
			render_control_panel(game);
		if (game->message.msg_state != MSG_INACTIVE)
		{
			render_tutorial_frame(game);
			render_tutorial_text(game);
		}
	}
	mlx_put_image_to_window(game->mlx, game->win, game->screen.img, 0, 0);
	if (BONUS && game->control > 0)
		render_control_text(game);
}

static void	update_animation_frames(t_game *game, double now)
{
	double	dt_ghosts;

	dt_ghosts = now - game->last_time_ghosts;
	if (dt_ghosts >= ANIMATION_TIME_GHOSTS)
	{
		game->last_time_ghosts = now;
		game->animation_ghosts++;
		if (game->animation_ghosts == 8)
			game->animation_ghosts = 0;
	}
}

static double	update_timers(t_game *game, double now)
{
	double	dt;

	dt = now - game->last_time;
	update_animation_frames(game, now);
	if (BONUS && game->light > 0)
		update_animation_matrix(game, now);
	if (game->ghost_state == SCARED && now - game->time_scared >= TIME_SCARED)
		game->ghost_state = ABSENT;
	game->last_time = now;
	if (dt > 0.1)
		dt = 0.1;
	return (dt);
}

int	render_loop(t_game *game)
{
	double	now;
	double	dt;

	now = now_seconds();
	if (BONUS)
		update_crawl(game);
	if (BONUS && game->crawl_active)
		return (render_loop_crawl(game, now));
	dt = update_timers(game, now);
	move_player(game, dt);
	if (BONUS)
	{
		update_message_reveal(game);
		check_random_message_timer(game);
		check_message_auto_dismiss(game);
	}
	render_frame(game);
	return (0);
}
