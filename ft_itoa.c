/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanzhao <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 16:04:55 by yanzhao           #+#    #+#             */
/*   Updated: 2025/05/02 17:33:48 by yanzhao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	count_digit(int n)
{
	int	nbr_digit;

	if (n == 0)
		return (1);
	nbr_digit = 0;
	while (n != 0)
	{
		n = n / 10;
		nbr_digit++;
	}
	return (nbr_digit);
}

static	char	*fill_result(int final_index, int n,
			int is_negative, char *result)
{
	int	digit_abs;

	result[final_index--] = '\0';
	if (n == 0)
	{
		result[0] = 0 + '0';
		return (result);
	}
	if (is_negative)
		result[0] = '-';
	while (n != 0)
	{
		digit_abs = n % 10;
		if (digit_abs < 0)
			digit_abs *= -1;
		result[final_index--] = digit_abs + '0';
		n = n / 10;
	}
	return (result);
}

char	*ft_itoa(int n)
{
	int		is_negative;
	int		nbr_digit;
	int		final_index;
	char	*result;

	is_negative = 0;
	if (n < 0)
		is_negative = 1;
	nbr_digit = count_digit(n);
	result = malloc(nbr_digit + is_negative + 1);
	if (!result)
		return (NULL);
	final_index = nbr_digit + is_negative;
	return (fill_result(final_index, n, is_negative, result));
}
