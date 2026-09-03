/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_ghosts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrager <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 22:07:55 by mgrager           #+#    #+#             */
/*   Updated: 2026/08/31 22:07:56 by mgrager          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	delete_image_group(t_img *img, int n, void *mlx)
{
	n--;
	while (n >= 0)
	{
		if (img[n].img)
		{
			mlx_destroy_image(mlx, img[n].img);
			img[n].img = NULL;
		}
		n--;
	}
}

void	delete_ghosts_noframe(t_game *game)
{
	delete_image_group(game->img_bonus.ghost_noframe_blue, 2, game->mlx);
	delete_image_group(game->img_bonus.ghost_noframe_eyes, 4, game->mlx);
	delete_image_group(game->img_bonus.ghost_noframe_orange, 8, game->mlx);
	delete_image_group(game->img_bonus.ghost_noframe_pink, 8, game->mlx);
	delete_image_group(game->img_bonus.ghost_noframe_red, 8, game->mlx);
	delete_image_group(game->img_bonus.ghost_noframe_cyan, 8, game->mlx);
	delete_image_group(game->img_bonus.ghost_noframe_white, 2, game->mlx);
}

void	delete_ghosts_frame(t_game *game)
{
	delete_image_group(game->img_bonus.ghost_frame_blue, 2, game->mlx);
	delete_image_group(game->img_bonus.ghost_frame_eyes, 4, game->mlx);
	delete_image_group(game->img_bonus.ghost_frame_orange, 8, game->mlx);
	delete_image_group(game->img_bonus.ghost_frame_pink, 8, game->mlx);
	delete_image_group(game->img_bonus.ghost_frame_red, 8, game->mlx);
	delete_image_group(game->img_bonus.ghost_frame_cyan, 8, game->mlx);
	delete_image_group(game->img_bonus.ghost_frame_white, 2, game->mlx);
}
