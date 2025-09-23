/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbilim <rbilim@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 15:03:47 by rbilim            #+#    #+#             */
/*   Updated: 2025/09/23 13:17:55 by rbilim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_all(char **cmd, char *path, int file)
{
	int	i;

	i = 0;
	while (cmd[i])
	{
		free(cmd[i]);
		i++;
	}
	free(cmd);
	free(path);
	close(file);
}

void	errorandexit(char *message, int errstatus)
{
	if (errstatus)
		write(2, message, 25);
	else
		perror(message);
	exit(EXIT_FAILURE);
}

char	*find_path(char **env, char **cmd)
{
	char	**spl_path;
	char	*arr;
	char	*temp;
	int		i;

	i = 0;
	while (env[i] && !ft_strnstr(env[i], "PATH=", 5))
		i++;
	if (!env[i] || !cmd)
		return (NULL);
	spl_path = ft_split(env[i] + 5, ':');
	i = -1;
	while (spl_path[++i])
	{
		temp = ft_strjoin(spl_path[i], "/");
		arr = ft_strjoin(temp, cmd[0]);
		free(temp);
		if (!access(arr, F_OK | X_OK))
			return (arr);
		free(arr);
	}
	free_all(spl_path, NULL, -1);
	free_all(cmd, NULL, -1);
	exit(127);
}

int	heredoc_function(char *limiter)
{
	char	*line;
	int		fd[2];

	if (pipe(fd) == -1)
		errorandexit("pipe error!", 0);
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
		write(fd[1], line, ft_strlen(line));
		free(line);
	}
	close(fd[1]);
	return (fd[0]);
}
