/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbilim <rbilim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 10:55:11 by rbilim            #+#    #+#             */
/*   Updated: 2025/06/14 17:12:27 by rbilim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*t_dest;
	unsigned char	*t_src;
	size_t			i;

	t_dest = (unsigned char *)dest;
	t_src = (unsigned char *)src;
	i = 0;
	if (!t_dest && !t_src)
		return (t_dest);
	if (t_src < t_dest)
	{
		i = n;
		while (i > 0)
		{
			t_dest[i - 1] = t_src[i - 1];
			i--;
		}
		return (dest);
	}
	while (i < n)
	{
		t_dest[i] = t_src[i];
		i++;
	}
	return (dest);
}
