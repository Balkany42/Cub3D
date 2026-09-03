/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrager <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 22:45:49 by mgrager           #+#    #+#             */
/*   Updated: 2026/08/30 22:47:19 by mgrager          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	load_one(t_game *game, t_img *tex, char *path)
{
	int	w;
	int	h;

	if (is_safe_file(path))
		parse_error(game, "Texture file is invalid or too large !");
	tex->img = mlx_xpm_file_to_image(game->mlx, path, &w, &h);
	if (!tex->img)
		parse_error(game,
			"failed to load texture ! (check the path in NO/SO/WE/EA)");
	tex->width = w;
	tex->height = h;
	tex->addr = mlx_get_data_addr(tex->img, &tex->bpp, &tex->line_len,
			&tex->endian);
}

static char	*pad_number(char *num)
{
	char	*tmp;

	if (ft_strlen(num) == 1)
	{
		tmp = num;
		num = ft_strjoin("00", num);
		free(tmp);
	}
	else if (ft_strlen(num) == 2)
	{
		tmp = num;
		num = ft_strjoin("0", num);
		free(tmp);
	}
	return (num);
}

static char	*build_texture_path(t_game *game, char *dir, int index)
{
	char	*num;
	char	*tmp;
	char	*path;

	num = ft_itoa(index + 1);
	if (!num)
		parse_error(game, "Allocation texture bonus failed !");
	num = pad_number(num);
	if (!num)
		parse_error(game, "Allocation texture bonus failed !");
	tmp = ft_strjoin(dir, num);
	free(num);
	if (!tmp)
		parse_error(game, "Allocation texture bonus failed !");
	path = ft_strjoin(tmp, ".xpm");
	free(tmp);
	if (!path)
		parse_error(game, "Allocation texture bonus failed !");
	return (path);
}

void	load_numbered_family(t_game *game, t_img *dst, char *dir, int count)
{
	int		i;
	char	*path;

	i = 0;
	while (i < count)
	{
		path = build_texture_path(game, dir, i);
		load_one(game, &dst[i], path);
		free(path);
		i++;
	}
}
