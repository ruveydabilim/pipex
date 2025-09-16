/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbilim <rbilim@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 15:03:47 by rbilim            #+#    #+#             */
/*   Updated: 2025/09/16 12:57:29 by rbilim           ###   ########.fr       */
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

void	errorandexit(char *message)
{
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

