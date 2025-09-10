/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbilim <rbilim@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 17:24:49 by rbilim            #+#    #+#             */
/*   Updated: 2025/09/10 17:32:30 by rbilim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	heredoc_function(char *limiter, char **argv)
{
	char	*line;
	int		fd;

	fd = open("heredoc.txt", O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (fd < 0)
	{
		perror("heredoc file open error");
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		write(1, "heredoc> ", 9);
		line = get_next_line(0);
		if (!line)
			break ;
		if (ft_strncmp(line, limiter, ft_strlen(limiter)) == 0
			&& line[ft_strlen(limiter)] == '\n')
		{
			free(line);
			break ;
		}
		ft_putstr_fd(line, fd);
		free(line);
	}
	close(fd);
}


