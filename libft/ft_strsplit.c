/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmuteba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 17:50:44 by mmuteba           #+#    #+#             */
/*   Updated: 2018/07/13 12:01:34 by mmuteba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_wordcountd(char const *s, char c)
{
	int words;

	words = 0;
	if (!s && !c)
		return (0);
	while (*s)
	{
		if ((*s != c && *(s + 1) == c) || (*s != c && *(s + 1) == '\0'))
			words++;
		s++;
	}
	return (words);
}

static int		ft_strlend(const char *s, char c)
{
	static int	pos;
	int			letters;

	if (!s && !c)
		return (0);
	pos = 0;
	letters = 0;
	while (s[pos] == c)
		pos++;
	while (s[pos++] != c && s[pos])
		letters++;
	return (letters);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**splt;
	int		word;
	int		i;

	word = 0;
	i = 0;
	if (!s)
		return (NULL);
	if (!(splt = (char **)malloc(sizeof(char *) * (ft_wordcountd(s, c) + 1))))
		return (NULL);
	while (*s == c)
		s++;
	while (*s)
	{
		splt[word] = (char *)malloc(sizeof(char) * (ft_strlend(s, c) + 1));
		while (*s != c && *s)
			splt[word][i++] = *s++;
		splt[word][i] = '\0';
		word++;
		i = 0;
		while (*s == c)
			s++;
	}
	splt[word] = NULL;
	return (splt);
}
