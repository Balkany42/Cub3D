/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_blit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrager <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 23:20:00 by mgrager           #+#    #+#             */
/*   Updated: 2026/08/31 23:20:00 by mgrager          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	inject_new_row(t_img *img, t_img *glyph, t_glyph_pos *gp)
{
	int	z;
	int	pixel;

	z = 0;
	while (z < GLYPH_SIZE)
	{
		pixel = get_tex_pixel(glyph, z + gp->offset_x, gp->row + gp->offset_y);
		put_pixel(img, gp->x + z, TILE_SIZE - GLYPH_SIZE - 1, pixel);
		z++;
	}
}

void	shift_column_up(t_img *img, int x)
{
	int	y;
	int	z;
	int	pixel;

	z = x;
	while (z < x + GLYPH_SIZE)
	{
		y = 8;
		while (y <= 55)
		{
			pixel = get_tex_pixel(img, z, y + 1);
			put_pixel(img, z, y, pixel);
			y++;
		}
		z++;
	}
}
