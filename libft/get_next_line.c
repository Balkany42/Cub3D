/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrager <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 20:26:33 by mgrager           #+#    #+#             */
/*   Updated: 2026/08/19 20:26:35 by mgrager          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*read_and_fill(int fd, char *stash)
{
	char	*buf;
	char	*tmp;
	ssize_t	bytes;

	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (free(stash), NULL);
	bytes = 1;
	while (!ft_strchr(stash, '\n') && bytes > 0)
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes < 0)
			return (free(buf), free(stash), NULL);
		buf[bytes] = '\0';
		tmp = ft_strjoin(stash, buf);
		free(stash);
		if (!tmp)
			return (free(buf), NULL);
		stash = tmp;
	}
	free(buf);
	return (stash);
}

static char	*extract_line(char *stash)
{
	char	*line;
	char	*nl;
	size_t	len;
	size_t	i;

	if (!stash || !stash[0])
		return (NULL);
	nl = ft_strchr(stash, '\n');
	if (nl)
		len = (size_t)(nl - stash) + 1;
	else
		len = ft_strlen(stash);
	line = malloc(len + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (i < len)
	{
		line[i] = stash[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

static char	*update_stash(char *stash)
{
	char	*new_stash;
	char	*nl;
	size_t	i;
	size_t	j;

	nl = ft_strchr(stash, '\n');
	if (!nl)
	{
		free(stash);
		return (NULL);
	}
	new_stash = malloc(ft_strlen(nl + 1) + 1);
	if (!new_stash)
	{
		free(stash);
		return (NULL);
	}
	i = (size_t)(nl - stash) + 1;
	j = 0;
	while (stash[i])
		new_stash[j++] = stash[i++];
	new_stash[j] = '\0';
	free(stash);
	return (new_stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!stash)
		stash = ft_strdup("");
	if (!stash)
		return (NULL);
	stash = read_and_fill(fd, stash);
	if (!stash)
		return (NULL);
	line = extract_line(stash);
	stash = update_stash(stash);
	return (line);
}
