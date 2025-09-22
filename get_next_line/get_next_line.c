/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbilim <rbilim@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 16:39:22 by rbilim            #+#    #+#             */
/*   Updated: 2025/09/10 14:00:08 by rbilim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*next_line(char *temp)
{
	char	*new_temp;
	int		i;

	i = 0;
	if (temp == NULL)
		return (NULL);
	while (temp[i] && temp[i] != '\n')
		i++;
	new_temp = ft_substr1(temp, i + 1, ft_strlen1(temp) - i);
	free(temp);
	return (new_temp);
}

static char	*get_line(char *temp)
{
	char	*line;
	int		i;

	i = 0;
	while (temp[i] && temp[i] != '\n')
		i++;
	line = ft_substr1(temp, 0, i + 1);
	return (line);
}

char	*read_and_join(int fd, char *temp, ssize_t readed)
{
	char	*buffer;

	while (!ft_strchr1(temp, '\n'))
	{
		buffer = malloc(BUFFER_SIZE + 1);
		if (!buffer)
			return (NULL);
		readed = read(fd, buffer, BUFFER_SIZE);
		if (readed == -1)
		{
			if (temp != NULL)
				free(temp);
			return (free(buffer), NULL);
		}
		if (readed == 0)
			return (free(buffer), temp);
		buffer[readed] = '\0';
		temp = ft_strjoin1(temp, buffer);
	}
	return (temp);
}

char	*get_next_line(int fd)
{
	char		*line;
	ssize_t		readed;
	static char	*temp;

	readed = 1;
	if (BUFFER_SIZE < 0 || fd < 0)
		return (free(temp), NULL);
	if (!temp)
		temp = ft_strdup1("");
	temp = read_and_join(fd, temp, readed);
	if (temp == NULL)
		return (NULL);
	line = get_line(temp);
	temp = next_line(temp);
	return (line);
}
