/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanzhao <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 20:07:44 by yanzhao           #+#    #+#             */
/*   Updated: 2025/04/30 12:26:17 by yanzhao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t	len_src;
	size_t	len_dest;
	size_t	i;

	len_src = ft_strlen(src);
	len_dest = ft_strlen(dst);
	if (n < len_dest || n == 0)
		return (len_src + n);
	i = 0;
	while (i + len_dest < n - 1 && src[i])
	{
		dst[i + len_dest] = src[i];
		i++;
	}
	dst[i + len_dest] = '\0';
	return (len_src + len_dest);
}
