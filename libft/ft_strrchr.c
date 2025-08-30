/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbilim <rbilim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 13:49:04 by rbilim            #+#    #+#             */
/*   Updated: 2025/06/16 17:11:24 by rbilim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;

	i = ft_strlen(s) - 1;
	if ((unsigned char)c == 0)
		return ((char *)s + i + 1);
	while (s[i] != (unsigned char)c && i >= 0)
		i--;
	if (s[i] == (unsigned char)c)
		return ((char *)s + i);
	return (NULL);
}
