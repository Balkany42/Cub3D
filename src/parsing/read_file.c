/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrager <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 00:52:47 by mgrager           #+#    #+#             */
/*   Updated: 2026/08/31 00:54:56 by mgrager          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	strip_newline(char *line)
{
	int	len;

	len = (int)ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		line[len - 1] = '\0';
}

static char	**append_line(char **lines, char *line)
{
	int		count;
	char	**new;
	int		i;

	i = 0;
	count = 0;
	if (lines)
		while (lines[count])
			count++;
	new = malloc(sizeof(char *) * (count + 2));
	if (!new)
	{
		free_table(lines);
		free(line);
		return (NULL);
	}
	while (i < count)
	{
		new[i] = lines[i];
		i++;
	}
	new[count] = line;
	new[count + 1] = NULL;
	free(lines);
	return (new);
}

char	**read_file(char *path)
{
	int		fd;
	char	*line;
	char	**lines;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (NULL);
	lines = NULL;
	line = get_next_line(fd);
	while (line)
	{
		strip_newline(line);
		lines = append_line(lines, line);
		if (!lines)
		{
			close(fd);
			return (NULL);
		}
		line = get_next_line(fd);
	}
	close(fd);
	return (lines);
}
