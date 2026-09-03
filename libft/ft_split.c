/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrager <mgrager@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 01:45:54 by mgrager           #+#    #+#             */
/*   Updated: 2025/11/22 16:55:18 by mgrager          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_split2(const char *s, char c, size_t *i);
static void	ft_free(char **tab, size_t count);
static int	ft_count_words(const char *s, char c);

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	k;
	char	**tab;

	i = 0;
	k = 0;
	if (!s)
		return (NULL);
	tab = (char **)malloc(sizeof(char *) * ((ft_count_words(s, c) + 1)));
	if (tab == NULL)
		return (NULL);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] == '\0')
			break ;
		tab[k] = ft_split2 (s, c, &i);
		if (tab[k] == NULL)
			return (ft_free(tab, k), NULL);
		k++;
	}
	tab[k] = (NULL);
	return (tab);
}

static char	*ft_split2(const char *s, char c, size_t *i)
{
	size_t	j;
	size_t	start;

	j = 0;
	while (s[*i] == c)
		(*i)++;
	start = *i;
	while (s[*i] != c && s[*i] != '\0')
	{
		j++;
		(*i)++;
	}
	return (ft_substr(s, start, j));
}

static void	ft_free(char **tab, size_t count)
{
	while (count > 0)
	{
		count--;
		free(tab[count]);
	}
	free(tab);
}

static int	ft_count_words(const char *s, char c)
{
	size_t	i;
	size_t	word_nbr;
	size_t	content;

	i = 0;
	word_nbr = 0;
	content = 0;
	while (s[i])
	{
		if (s[i] != c && content == 0)
		{
			content = 1;
			word_nbr++;
		}
		else if (s[i] == c)
		{
			content = 0;
		}
		i++;
	}
	return (word_nbr);
}
