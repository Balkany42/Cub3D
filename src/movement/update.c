/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrager <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 23:11:20 by mgrager           #+#    #+#             */
/*   Updated: 2026/08/31 22:30:00 by mgrager          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	update_matrix_pill_state(t_game *game, t_matrix_state target)
{
	if (game->matrix_state == MATRIX_WORKING)
	{
		game->matrix_state = target;
		start_message(game, now_seconds());
	}
	else if (game->matrix_state == target)
	{
		game->matrix_state = MATRIX_WORKING;
		init_state_texture(game);
	}
}

void	update_phantom_state(t_game *game, int i)
{
	double	now;

	now = now_seconds();
	if (i == 1)
	{
		if (game->ghost_state == ABSENT)
			game->ghost_state = PRESENT;
		else if (game->ghost_state == HIDDEN)
			game->ghost_state = PRESENT;
	}
	if (i == 2)
	{
		if (game->ghost_state == PRESENT)
			game->ghost_state = HIDDEN;
		else if (game->ghost_state == HIDDEN)
		{
			game->ghost_state = SCARED;
			game->time_scared = now;
		}
	}
}

int	mouse_hook(int x, int y, t_game *game)
{
	int	dx;

	(void)y;
	dx = x - game->mouse_ref;
	if (dx != 0)
		rotate_player(game, dx * MOUSE_SENSITIVITY);
	game->mouse_ref = x;
	if (x < WIN_WIDTH / 4 || x > WIN_WIDTH * 3 / 4)
	{
		mlx_mouse_move(game->mlx, game->win, WIN_WIDTH / 2, WIN_HEIGHT / 2);
		game->mouse_ref = WIN_WIDTH / 2;
	}
	return (0);
}

int	scroll_hook(int button, int x, int y, t_game *game)
{
	(void)x;
	(void)y;
	if (button == 4)
		zoom_player(game, 1.0 - SCROLL_ZOOM_STEP);
	else if (button == 5)
		zoom_player(game, 1.0 + SCROLL_ZOOM_STEP);
	return (0);
}

void	toggle_door(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			if (game->map.grid[y][x] == 'C')
				game->map.grid[y][x] = 'O';
			else if (game->map.grid[y][x] == 'O')
				game->map.grid[y][x] = 'C';
			x++;
		}
		y++;
	}
}
