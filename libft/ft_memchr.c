/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbilim <rbilim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 17:22:38 by rbilim            #+#    #+#             */
/*   Updated: 2025/06/19 14:51:35 by rbilim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*temp_s;
	size_t			i;

	i = 0;
	temp_s = (unsigned char *)s;
	while (i < n)
	{
		if (temp_s[i] == (unsigned char)c)
			return ((void *)(temp_s + i));
		i++;
	}
	return ((void *)0);
}
