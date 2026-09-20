/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crawl_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrager <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/03 00:00:00 by mgrager           #+#    #+#             */
/*   Updated: 2026/09/03 00:00:00 by mgrager          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	start_crawl(t_game *game)
{
	game->crawl_active = 1;
	game->crawl_start = now_seconds();
}

void	update_crawl(t_game *game)
{
	if (!game->crawl_active)
		return ;
	if (now_seconds() - game->crawl_start > CRAWL_DURATION)
	{
		game->crawl_active = 0;
		start_tutorial(game);
	}
}
