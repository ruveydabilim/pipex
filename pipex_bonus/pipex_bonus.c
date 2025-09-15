/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbilim <rbilim@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 0025/09/06 11:26:43 by bilim             #+#    #+#             */
/*   Updated: 2025/09/15 18:37:09 by rbilim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	heredoc_function(char *limiter)
{
	char	*line;
	int		fd[2];

	if (pipe(fd) == -1)
		errorandexit("pipe error!");
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

void	executer(char *cmd, char **env, int infile, int outfile)
{
	char	**command;
	char	*path;

	command = ft_split(cmd, ' ');
	path = find_path(env, command[0]);
	if (!path)
	{
		close(infile);
		close(outfile);
		free_all(command);
		errorandexit("path is not found");
	}
	dup2(infile, 0);
	close(infile);
	dup2(outfile, 1);
	close(outfile);
	execve(path, command, env);
	free(path);
	free_all(command);
	errorandexit("execve error!");
}

int	pipeandexec(int argc, char **env, char **argv, int infile)
{
	pid_t	pid;
	int		i;
	int		fd[2];

	i = 2;
	if (ft_strncmp(argv[1], "here_doc", 9) == 0)
		i = 3;
	while (i < argc - 2)
	{
		if (pipe(fd) == -1)
			errorandexit("pipe error!");
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
	return (infile);
}

int	main(int argc, char **argv, char **env)
{
	int		infile;
	int		outfile;
	pid_t	pid;

	if (argc < 5)
	{
		write(2, "invalid arguments count\n", 25);
		exit(EXIT_FAILURE);
	}
	if (ft_strncmp(argv[1], "here_doc", 9) == 0)
		infile = heredoc_function(argv[2]);
	else
		infile = open(argv[1], O_RDONLY);
	outfile = open(argv[argc - 1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (infile < 0 || outfile < 0)
		errorandexit("file error! infile\\outfile not exist or \
permission denied.");
	infile = pipeandexec(argc, env, argv, infile);
	pid = fork();
	if (pid == 0)
		executer(argv[argc - 2], env, infile, outfile);
	close(infile);
	close(outfile);
}
