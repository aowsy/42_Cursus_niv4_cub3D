/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_cub.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluu <tluu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 16:35:43 by tluu              #+#    #+#             */
/*   Updated: 2022/09/28 19:31:49 by tluu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	nword_cub(char const *s, char c)
{
	int	i;
	int	nbword;

	i = 0;
	nbword = 0;
	while (s[i])
	{
		if (s[i + 1] == '\0')
		{
			nbword++;
			return (nbword);
		}
		if (s[i] == c)
			nbword++;
		i++;
	}
	return (nbword);
}

static char	**putword_cub(char **fstr, const char *s, char c)
{
	int		nword;
	size_t	len;
	int		i;

	nword = 0;
	i = 0;
	while (s[i])
	{
		len = 0;
		while (s[i + len] != c && s[i + len] != '\0')
			len++;
		if (s[i + len] == c)
			len++;
		fstr[nword] = ft_substr(s, i, len);
		if (!fstr[nword])
		{
			free_split(fstr);
			return (NULL);
		}
		i += len;
		nword++;
	}
	return (fstr);
}

char	**ft_split_cub(char *s, char c)
{
	char	**fstr;
	int		nbword;

	if (s == NULL)
		return (NULL);
	nbword = nword_cub(s, c);
	fstr = (char **)malloc(sizeof (char *) * (nbword + 1));
	if (!fstr)
		return (NULL);
	fstr[nbword] = 0;
	putword_cub(fstr, s, c);
	return (fstr);
}
