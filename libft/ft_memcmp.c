/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbilim <rbilim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 17:23:32 by rbilim            #+#    #+#             */
/*   Updated: 2025/06/14 12:40:49 by rbilim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*temp_s1;
	unsigned char	*temp_s2;
	size_t			i;

	temp_s1 = (unsigned char *)s1;
	temp_s2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (temp_s1[i] == temp_s2[i])
			i++;
		else
			return ((temp_s1[i]) - (temp_s2[i]));
	}
	return (0);
}
