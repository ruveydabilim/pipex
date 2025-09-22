/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbilim <rbilim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 11:01:33 by rbilim            #+#    #+#             */
/*   Updated: 2025/07/07 18:33:23 by rbilim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*next_line(char *temp)
{
	char	*new_temp;
	int		i;

	i = 0;
	if (temp == NULL)
		return (NULL);
	while (temp[i] && temp[i] != '\n')
		i++;
	new_temp = ft_substr(temp, i + 1, ft_strlen(temp) - i);
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
	line = ft_substr(temp, 0, i + 1);
	return (line);
}

char	*read_and_join(int fd, char *temp, ssize_t readed)
{
	char	*buffer;

	while (!ft_strchr(temp, '\n'))
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
		temp = ft_strjoin(temp, buffer);
	}
	return (temp);
}

char	*get_next_line(int fd)
{
	char		*line;
	ssize_t		readed;
	static char	*temp[2048];

	readed = 1;
	if (!temp[fd])
		temp[fd] = ft_strdup("");
	if (!BUFFER_SIZE || fd == -1)
		return (NULL);
	temp[fd] = read_and_join(fd, temp[fd], readed);
	if (temp[fd] == NULL)
		return (NULL);
	line = get_line(temp[fd]);
	temp[fd] = next_line(temp[fd]);
	return (line);
}
