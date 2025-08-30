/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbilim <rbilim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 12:47:23 by rbilim            #+#    #+#             */
/*   Updated: 2025/06/21 13:07:25 by rbilim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*temp_s;
	int		i;

	i = 0;
	temp_s = (char *)s;
	while (temp_s[i] != (unsigned char)c && temp_s[i])
		i++;
	if ((unsigned char)c != '\0' && !temp_s[i])
		return (NULL);
	return ((char *)s + i);
}
