/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbilim <rbilim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 13:44:24 by rbilim            #+#    #+#             */
/*   Updated: 2025/06/14 17:16:04 by rbilim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	countnum(int n)
{
	unsigned int	counter;

	counter = 0;
	if (n <= 0)
		counter++;
	while (n)
	{
		n /= 10;
		counter++;
	}
	return (counter);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*result;
	int		i;

	len = countnum(n);
	i = len - 1;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	result = malloc(sizeof(char) * len + 1);
	if (!result)
		return (NULL);
	result[i] = '0';
	if (n < 0)
	{
		n = -n;
		result[0] = '-';
	}
	while (n > 0)
	{
		result[i] = n % 10 + '0';
		n /= 10;
		i--;
	}
	result[len] = '\0';
	return (result);
}
