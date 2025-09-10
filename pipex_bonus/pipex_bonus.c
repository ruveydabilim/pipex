/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbilim <rbilim@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 0025/09/06 11:26:43 by bilim             #+#    #+#             */
/*   Updated: 2025/09/10 17:34:50 by rbilim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	free_all(char **arr)
{
	int	i;

	i = 0;
	if (!arr)
		return ;
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
	if (!cmd)
		return (NULL);
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
		if (access(arr, F_OK | X_OK) == 0)
			return (free_all(spl_path), arr);
		free(arr);
		i++;
	}
	return (free_all(spl_path), NULL);
}

void	executer(char *cmd, char **env, int infile, int outfile)
{
	char	**command;
	char	*path;

	command = ft_split(cmd, ' ');
	path = find_path(env, command[0]);
	if (!path)
	{
		free_all(command);
		perror("command not found");
		exit(EXIT_FAILURE);
	}
	dup2(infile, 0);
	close(infile);
	dup2(outfile, 1);
	close(outfile);
	if (execve(path, command, env) == -1)
	{
		perror("execve failed");
		free(path);
		free_all(command);
		exit(EXIT_FAILURE);
	}
}

void	pipeandexec(int argc, char **env, char **argv, int infile)
{
	pid_t	pid;
	int		i;
	int		fd[2];

	i = 2;
	while (i < argc - 2)
	{
		if (pipe(fd) == -1)
		{
			perror("pipe failed");
			exit(EXIT_FAILURE);
		}
		pid = fork();
		if (pid == 0)
		{
			close(fd[0]);
			executer(argv[i], env, infile, fd[1]);
		}
		close(fd[1]);
		if (infile != -1)
			close(infile);
		infile = fd[0];
		i++;
	}
}

int	main(int argc, char **argv, char **env)
{
	int		infile;
	int		outfile;
	pid_t	pid;
	int		fd;

	if (argc < 5)
	{
		perror("invalid arguments count");
		exit(EXIT_FAILURE);
	}
	infile = open(argv[1], O_RDONLY);
	if (ft_strncmp(argv[1], "here_doc", 9) == 0)
		heredoc_function(argv[2], argv);
	if (infile < 0)
		perror("infile error");
	pipeandexec(argc, env, argv, infile);
	outfile = open(argv[argc - 1], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (outfile < 0)
		perror("outfile error");
	pid = fork();
	if (pid == 0)
		executer(argv[argc - 2], env, infile, outfile);
	close(infile);
	close(outfile);
}
