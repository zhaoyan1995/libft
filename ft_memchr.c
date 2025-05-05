/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanzhao <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 17:17:59 by yanzhao           #+#    #+#             */
/*   Updated: 2025/04/30 17:39:42 by yanzhao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*s2;

	i = 0;
	s2 = (const unsigned char *)s;
	while (i < n)
	{
		if (s2[i] == (unsigned char)c)
			return ((void *)(s2 + i));
		i++;
	}
	return (NULL);
}
