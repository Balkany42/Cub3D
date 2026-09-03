/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tutorial_render.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrager <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 23:20:00 by mgrager           #+#    #+#             */
/*   Updated: 2026/08/31 23:20:00 by mgrager          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	row_has_text(t_img *img, int y)
{
	int	x;

	x = 0;
	while (x < img->width)
	{
		if (get_tex_pixel(img, x, y) != 0x000000)
			return (1);
		x++;
	}
	return (0);
}

void	find_line_x_bounds(t_img *img, t_line_box *box)
{
	int	x;
	int	y;

	y = box->top;
	box->left = img->width;
	box->right = 0;
	while (y <= box->bottom)
	{
		x = 0;
		while (x < img->width)
		{
			if (get_tex_pixel(img, x, y) != 0x000000)
			{
				if (x > box->right)
					box->right = x;
				if (x < box->left)
					box->left = x;
			}
			x++;
		}
		y++;
	}
}

static void	render_line(t_game *game, t_line_box *box, int max_x)
{
	int		x;
	int		y;
	int		color;
	t_img	*img;

	img = game->message.current_message;
	y = box->top;
	while (y <= box->bottom)
	{
		x = box->left;
		while (x <= max_x)
		{
			color = get_tex_pixel(img, x, y);
			put_pixel(&game->screen, TUTORIAL_OFFSET_PX + MINIMAP_TILE + x,
				TUTORIAL_HEIGHT_OFFSET_PX + MINIMAP_TILE + y, color);
			x++;
		}
		y++;
	}
}

void	render_tutorial_text(t_game *game)
{
	int			i;
	int			max_x;
	t_line_box	*box;

	i = 0;
	while (i < game->message.msg_current_line)
	{
		box = &game->message.msg_layout.line[i];
		render_line(game, box, box->right);
		i++;
	}
	if (game->message.msg_current_line < game->message.msg_layout.line_count)
	{
		box = &game->message.msg_layout.line[game->message.msg_current_line];
		max_x = box->left + game->message.msg_revealed_x;
		if (max_x > box->right)
			max_x = box->right;
		render_line(game, box, max_x);
	}
}

void	render_tutorial_frame(t_game *game)
{
	int	x;
	int	y;
	int	start_x;
	int	start_y;

	start_y = TUTORIAL_HEIGHT_OFFSET_PX;
	start_x = TUTORIAL_OFFSET_PX;
	y = start_y;
	while (y < TUTORIAL_HEIGHT_PX + TUTORIAL_HEIGHT_OFFSET_PX
		+ MINIMAP_TILE * 2)
	{
		x = start_x;
		while (x < WIN_WIDTH - TUTORIAL_OFFSET_PX)
		{
			if (x < start_x + MINIMAP_TILE || y < start_y + MINIMAP_TILE
				|| x >= WIN_WIDTH - TUTORIAL_OFFSET_PX - MINIMAP_TILE
				|| y >= TUTORIAL_HEIGHT_PX + TUTORIAL_HEIGHT_OFFSET_PX
				+ MINIMAP_TILE)
				put_pixel(&game->screen, x, y, 0xFFFFFF);
			else
				put_pixel(&game->screen, x, y, 0x000000);
			x++;
		}
		y++;
	}
}
