/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbilim <rbilim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 14:13:18 by rbilim            #+#    #+#             */
/*   Updated: 2025/06/14 17:12:15 by rbilim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*t_dest;
	unsigned char	*t_src;
	size_t			i;

	t_dest = (unsigned char *)dest;
	t_src = (unsigned char *)src;
	i = 0;
	if (!t_dest && !t_src)
		return (t_dest);
	while (i < n)
	{
		t_dest[i] = t_src[i];
		i++;
	}
	return (dest);
}
