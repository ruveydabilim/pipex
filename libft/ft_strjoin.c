/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbilim <rbilim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 11:04:45 by rbilim            #+#    #+#             */
/*   Updated: 2025/06/14 12:43:02 by rbilim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char				*joined;
	unsigned int		t_len;
	unsigned int		i;
	unsigned int		j;

	t_len = ft_strlen(s1) + ft_strlen(s2);
	i = 0;
	j = 0;
	joined = (char *)malloc(t_len + 1);
	if (!joined)
		return (NULL);
	while (s1[i])
	{
		joined[j++] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		joined[j++] = s2[i];
		i++;
	}
	joined[j] = '\0';
	return (joined);
}
