/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbilim <rbilim@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 19:55:58 by rbilim            #+#    #+#             */
/*   Updated: 2025/08/30 19:59:09 by rbilim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

char	*find_path(char **env, char *cmd)
{
	char	**spl_path;
	char	*arr;
	char	*temp;
	int		i;

	i = 0;
	while (env[i] && !ft_strnstr(env[i], "PATH=", 5))
		i++;
	if (!env[i])
		return (NULL);
	spl_path = ft_split(env[i] + 5, ':');
	i = 0;
	temp = ft_strjoin(spl_path[i], "/");
	while (spl_path[i])
	{
		arr = ft_strjoin(temp, cmd);
		free(temp);
		if (!access(arr, F_OK | X_OK))
			return (arr);
		else
			return (free_all(spl_path), free(arr), NULL);
		free(arr);
		i++;
	}
	return (NULL);
}

void	*executer1(char **argv, char **env, int *fd)
{
	int		infile;
	char	**command1;
	char	*path;
	int		i;

	i = 0;
	infile = open(argv[1], O_RDONLY);
	if (infile < 0)
		perror("infile error");
	command1 = ft_split(argv[2], ' ');
	path = find_path(env, command1[0]);
	if (!path)
		return (free_all(command1), free(path), NULL);
	dup2(infile, 0);
	dup2(fd[1], 1);
	close(fd[0]);
	close(fd[1]);
	execv(path, command1);
	free_all(command1);
	free(path);
	perror("execv failed");
	exit(EXIT_FAILURE);
}

void	*executer2(char **argv, char **env, int *fd)
{
	int		outfile;
	char	**command2;
	char	*path;
	int		i;

	i = 0;
	outfile = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (outfile < 0)
		perror("outfile error");
	command2 = ft_split(argv[3], ' ');
	path = find_path(env, command2[0]);
	if (!path)
		return (free_all(command2), free(path), NULL);
	dup2(fd[0], 0);
	dup2(outfile, 1);
	close(fd[0]);
	close(fd[1]);
	execv(path, command2);
	perror("execv failed");
	free_all(command2);
	free(path);
	exit(EXIT_FAILURE);
}

int	main(int argc, char **argv, char **env)
{
	int		fd[2];
	pid_t	pid1;
	pid_t	pid2;

	if (argc != 5)
	{
		perror("invalid arguments count");
		exit(EXIT_FAILURE);
	}
	if (pipe(fd) == -1)
	{
		perror("pipe failed");
		exit(EXIT_FAILURE);
	}
	pid1 = fork();
	if (pid1 == 0)
		executer1(argv, env, fd);
	pid2 = fork();
	if (pid2 == 0)
		executer2(argv, env, fd);
	close(fd[0]);
	close(fd[1]);
	return (0);
}
