/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanzhao <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 17:53:28 by yanzhao           #+#    #+#             */
/*   Updated: 2025/05/01 21:17:12 by yanzhao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strlen_set(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static	size_t	count_words(char const *s, char c)
{
	size_t	i;
	size_t	nbr_words;

	i = 0;
	nbr_words = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (!s[i])
			break ;
		while (s[i] && s[i] != c)
			i++;
		nbr_words++;
	}
	return (nbr_words);
}

static char	**free_result(char **result, size_t k)
{
	while (k > 0)
	{
		k--;
		if (result[k])
			free(result[k]);
	}
	free(result);
	return (NULL);
}

static	char	**fill_result(char **result, char const *s, char c,
			size_t count_words)
{
	size_t	k;
	size_t	j;
	size_t	len_str;

	k = 0;
	while (*s && k < count_words)
	{
		while (*s == c)
			s++;
		if (!*s)
			break ;
		len_str = ft_strlen_set(s, c);
		result[k] = malloc(len_str + 1);
		if (!result[k])
			return (free_result(result, k));
		j = 0;
		while (j < len_str)
			result[k][j++] = *s++;
		result[k][j] = '\0';
		k++;
	}
	result[k] = NULL;
	return (result);
}

char	**ft_split(char const *s, char c)
{
	size_t	nbr_words;
	char	**result;

	nbr_words = count_words(s, c);
	result = malloc(sizeof(char *) * (nbr_words + 1));
	if (!result)
		return (NULL);
	return (fill_result(result, s, c, nbr_words));
}
