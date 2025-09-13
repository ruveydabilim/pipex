/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbilim <rbilim@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 17:24:49 by rbilim            #+#    #+#             */
/*   Updated: 2025/09/13 18:44:31 by rbilim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	free_all(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	errorandexit(char *message)
{
	perror(message);
	exit(EXIT_FAILURE);
}

char	*find_path(char **env, char *cmd)
{
	char	**spl_path;
	char	*arr;
	char	*temp;
	int		i;

	if (!cmd)
		return (NULL);
	i = 0;
	while (env[i] && !ft_strnstr(env[i], "PATH=", 5))
		i++;
	if (!env[i])
		return (NULL);
	spl_path = ft_split(env[i] + 5, ':');
	i = 0;
	while (spl_path[i])
	{
		temp = ft_strjoin(spl_path[i], "/");
		arr = ft_strjoin(temp, cmd);
		free(temp);
		if (!access(arr, F_OK | X_OK))
			return (arr);
		free(arr);
		i++;
	}
	return (free_all(spl_path), NULL);
}
