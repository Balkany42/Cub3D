/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   star_wars.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrager <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 23:20:00 by mgrager           #+#    #+#             */
/*   Updated: 2026/08/31 23:20:00 by mgrager          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	get_tex_pixel_avg(t_img *tex, int x, int y0, int rows)
{
	int	i;
	int	sum[3];
	int	count;
	int	color;

	ft_memset(sum, 0, sizeof(sum));
	count = 0;
	i = 0;
	while (i < rows)
	{
		if (y0 + i >= 0 && y0 + i < tex->height)
		{
			color = get_tex_pixel(tex, x, y0 + i);
			sum[0] += (color >> 16) & 0xFF;
			sum[1] += (color >> 8) & 0xFF;
			sum[2] += color & 0xFF;
			count++;
		}
		i++;
	}
	if (count == 0)
		return (0x000000);
	return (((sum[0] / count) << 16)
		| ((sum[1] / count) << 8) | (sum[2] / count));
}

static void	clear_black(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			put_pixel(&game->screen, x, y, 0x000000);
			x++;
		}
		y++;
	}
}

static void	render_crawl_row(t_game *game, int y, int half_width, int source_y)
{
	int	x;
	int	dx;
	int	source_x;
	int	color;

	if (source_y < 0 || source_y >= game->crawl_tex.height
		|| half_width <= 0)
		return ;
	x = 0;
	while (x < WIN_WIDTH)
	{
		dx = x - WIN_WIDTH / 2;
		if (dx >= -half_width && dx < half_width)
		{
			source_x = game->crawl_tex.width / 2
				+ dx * game->crawl_tex.width / (2 * half_width);
			if (source_x >= 0 && source_x < game->crawl_tex.width)
			{
				color = get_tex_pixel_avg(&game->crawl_tex, source_x,
						source_y, (int)CRAWL_Y_SCALE);
				put_pixel(&game->screen, x, y, color);
			}
		}
		x++;
	}
}

static int	get_half_width(int y, int min_hw, int max_hw)
{
	double	t;

	t = (double)(y - CRAWL_VANISH_Y) / (double)(WIN_HEIGHT - CRAWL_VANISH_Y);
	return (min_hw + (int)((max_hw - min_hw) * t));
}

void	render_crawl(t_game *game)
{
	int		y;
	int		max_half_width;
	int		min_half_width;
	double	scroll;

	clear_black(game);
	scroll = (now_seconds() - game->crawl_start) * CRAWL_SCROLL_SPEED;
	max_half_width = WIN_WIDTH / 2;
	if (game->crawl_tex.width / 2 < max_half_width)
		max_half_width = game->crawl_tex.width / 2;
	min_half_width = (int)(max_half_width * CRAWL_MIN_WIDTH_RATIO);
	y = CRAWL_VANISH_Y + 1;
	while (y < WIN_HEIGHT)
	{
		render_crawl_row(game, y,
			get_half_width(y, min_half_width, max_half_width),
			(int)(scroll - CRAWL_Y_SCALE * (double)(WIN_HEIGHT - y)));
		y++;
	}
}
