/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbilim <rbilim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 10:44:36 by rbilim            #+#    #+#             */
/*   Updated: 2025/06/13 17:34:37 by rbilim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*t;
	size_t			i;
	size_t			len_s;

	if (!s)
		return (NULL);
	len_s = ft_strlen(s);
	i = 0;
	if (len_s <= start)
		return (ft_strdup (""));
	if (len > len_s - start)
		len = len_s - start;
	t = (char *)malloc(len + 1);
	if (!t)
		return (NULL);
	while (s[start + i] && i < len)
	{
		t[i] = s[start + i];
		i++;
	}
	t[i] = '\0';
	return (t);
}
