/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbilim <rbilim@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 14:59:55 by rbilim            #+#    #+#             */
/*   Updated: 2025/08/26 19:02:52 by rbilim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countallword(const char *s, char c)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i])
		{
			counter++;
			while (s[i] != c && s[i])
				i++;
		}
	}
	return (counter);
}

static int	ft_wordlen(const char *s, char c, int i)
{
	int	len;

	len = 0;
	while (s[i] != c && s[i])
	{
		i++;
		len++;
	}
	return (len);
}

static void	freeall(char **s, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		free (s[j]);
		j++;
	}
	free (s);
}

static int	skipsep(const char *s, int c, int i)
{
	while (s[i] == c && s[i])
		i++;
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		i;
	int		m;

	i = 0;
	m = 0;
	arr = (char **)malloc((sizeof (char *)) * (ft_countallword(s, c) + 1));
	if (!arr)
		return (NULL);
	while (s[i])
	{
		i = skipsep(s, c, i);
		if (ft_wordlen(s, c, i) == 0)
			break ;
		arr[m] = ft_substr(s, i, ft_wordlen(s, c, i));
		if (!arr[m])
		{
			freeall(arr, m);
			return (NULL);
		}
		m++;
		i += ft_wordlen(s, c, i);
	}
	arr[m] = NULL;
	return (arr);
}
