/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbilim <rbilim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 11:03:42 by rbilim            #+#    #+#             */
/*   Updated: 2025/06/15 16:36:41 by rbilim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	ctrlset(char const *set, int c)
{
	unsigned int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char			*t;
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;

	i = 0;
	j = ft_strlen(s1);
	k = 0;
	if (!s1)
		return (NULL);
	while (ctrlset(set, s1[i]) && s1[i])
		i++;
	while (j > 0 && ctrlset(set, s1[j - 1]))
		j--;
	if (i > j)
		return (ft_strdup(""));
	t = (char *)malloc(j - i + 1);
	if (!t)
		return (NULL);
	while (s1[i] && i < j)
		t[k++] = s1[i++];
	t[k] = '\0';
	return (t);
}
