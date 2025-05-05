/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanzhao <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 14:34:44 by yanzhao           #+#    #+#             */
/*   Updated: 2025/05/01 17:46:23 by yanzhao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strtrim2(char const *s1, char const *set)
{
	size_t	j;

	while (*s1)
	{
		j = 0;
		while (*(set + j))
		{
			if (*s1 == *(set + j))
				break ;
			j++;
		}
		if (*(set + j) == '\0')
			break ;
		s1++;
	}
	return ((char *)s1);
}

static	int	find_final_index(char *str1, char const *set, size_t len_str1)
{
	size_t	final_index;
	size_t	j;

	j = 0;
	final_index = len_str1 - 1;
	while (1)
	{
		j = 0;
		while (set[j])
		{
			if (str1[final_index] == set[j])
				break ;
			j++;
		}
		if (set[j] == '\0' || final_index == 0)
			break ;
		final_index--;
	}
	return (final_index);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str1;
	char	*result;
	size_t	i;
	size_t	len_str1;
	size_t	final_index;

	str1 = ft_strtrim2(s1, set);
	len_str1 = ft_strlen(str1);
	if (len_str1 == 0)
		return ((char *)ft_calloc(1, 1));
	final_index = find_final_index(str1, set, len_str1);
	result = malloc(final_index + 2);
	if (!result)
		return (NULL);
	i = 0;
	while (str1[i] && i <= final_index)
	{
		result[i] = str1[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}
