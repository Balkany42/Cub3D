/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrager <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 07:30:30 by mgrager           #+#    #+#             */
/*   Updated: 2026/09/02 02:24:03 by mgrager          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	free_extra_bonus(t_game *game)
{
	int	face;
	int	cell;

	face = 0;
	while (face < 4)
	{
		cell = 0;
		while (cell < MATRIX_SIZE)
		{
			if (game->matrix_tex[face][cell].img)
			{
				mlx_destroy_image(game->mlx, game->matrix_tex[face][cell].img);
				game->matrix_tex[face][cell].img = NULL;
			}
			cell++;
		}
		face++;
	}
	if (game->crawl_tex.img)
	{
		mlx_destroy_image(game->mlx, game->crawl_tex.img);
		game->crawl_tex.img = NULL;
	}
	delete_image_group(game->message.tutorial_messages, 6, game->mlx);
	delete_image_group(game->message.random_messages, 8, game->mlx);
}

void	delete_randoms(t_game *game)
{
	delete_image_group(game->img_bonus.rand_braille, 51, game->mlx);
	delete_image_group(game->img_bonus.rand_digit, 10, game->mlx);
	delete_image_group(game->img_bonus.rand_latin, 52, game->mlx);
	delete_image_group(game->img_bonus.rand_ru, 77, game->mlx);
	delete_image_group(game->img_bonus.rand_sign, 24, game->mlx);
}

void	delete_messages(t_game *game)
{
	delete_image_group(game->img_bonus.blue_braille, 7, game->mlx);
	delete_image_group(game->img_bonus.red_braille, 7, game->mlx);
	delete_image_group(game->img_bonus.blue_eng, 7, game->mlx);
	delete_image_group(game->img_bonus.red_eng, 7, game->mlx);
	delete_image_group(game->img_bonus.blue_fr, 7, game->mlx);
	delete_image_group(game->img_bonus.red_fr, 7, game->mlx);
	delete_image_group(game->img_bonus.blue_ru, 7, game->mlx);
	delete_image_group(game->img_bonus.red_ru, 7, game->mlx);
	delete_image_group(game->img_bonus.creator, 3, game->mlx);
}

void	free_img_bonus(t_game *game)
{
	delete_image_group(game->img_bonus.basics, 3, game->mlx);
	delete_ghosts_noframe(game);
	delete_ghosts_frame(game);
	delete_randoms(game);
	delete_messages(game);
	free_extra_bonus(game);
}
