/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbilim <rbilim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 15:25:36 by rbilim            #+#    #+#             */
/*   Updated: 2025/06/13 17:35:11 by rbilim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len_d;
	size_t	len_s;

	len_s = ft_strlen(src);
	len_d = ft_strlen(dst);
	i = 0;
	if (size == 0 || size <= len_d)
		return (len_s + size);
	while (i < size - len_d - 1 && src[i])
	{
		dst[len_d + i] = src[i];
		i++;
	}
	dst[len_d + i] = 0;
	return (len_d + len_s);
}
