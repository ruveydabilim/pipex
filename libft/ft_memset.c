/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbilim <rbilim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 19:16:58 by rbilim            #+#    #+#             */
/*   Updated: 2025/06/16 18:55:39 by rbilim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*m;
	size_t			i;

	m = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		m[i] = c;
		i++;
	}
	return (s);
}
