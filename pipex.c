/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbilim <rbilim@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 18:28:08 by rbilim            #+#    #+#             */
/*   Updated: 2025/09/22 18:55:54 by rbilim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	executer1(char **argv, char **env, int *fd, int i, int infile)
{
	char	**command1;
	char	*path;

	command1 = ft_split(argv[i], ' ');
	if (!command1 || !command1[0])
	{
		free_all(command1, NULL, infile);
		errorandexit("command not found", 0);
	}
	path = find_path(env, command1);
	close(fd[0]);
	dup2(infile, 0);
	dup2(fd[1], 1);
	close(fd[1]);
	execve(path, command1, env);
	free_all(command1, path, infile);
	errorandexit("execve error", 0);
}

void	executer2(char **argv, char **env, int *fd, int argc)
{
	int		outfile;
	char	**command2;
	char	*path;

	if (ft_strncmp(argv[1], "here_doc", 9) == 0)
		outfile = open(argv[argc - 1], O_CREAT | O_WRONLY | O_APPEND, 0644);
	else
		outfile = open(argv[argc - 1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (outfile < 0)
		errorandexit("outfile error!", 0);
	command2 = ft_split(argv[argc - 2], ' ');
	if (!command2 || !command2[0])
	{
		free_all(command2, NULL, outfile);
		errorandexit("command not found", 0);
	}
	path = find_path(env, command2);
	close(fd[1]);
	dup2(fd[0], 0);
	dup2(outfile, 1);
	close(fd[0]);
	execve(path, command2, env);
	free_all(command2, path, outfile);
	errorandexit("execve error", 0);
}

int	pipeandexec(int argc, char **env, char **argv, int *fd)
{
	pid_t	pid;
	int		i;
	int		infile;

	i = 2;
	if (ft_strncmp(argv[1], "here_doc", 9) == 0)
		i = 3;
	if (ft_strncmp(argv[1], "here_doc", 9) == 0)
		infile = heredoc_function(argv[2]);
	else
		infile = open(argv[1], O_RDONLY);
	while (i < argc - 2)
	{
		if (pipe(fd) == -1)
			errorandexit("pipe error!", 0);
		pid = fork();
		if (pid == 0)
			executer1(argv, env, fd, i, infile);
		else 
			waitpid(pid, NULL, 0);
		if (infile != -1)
			close(infile);
		infile = fd[0];
		i++;
	}
	return (infile);
}

int	main(int argc, char **argv, char **env)
{
	int		fd[2];
	pid_t	pid2;
	int		status;
	int		infile;

	if (argc == 1 || (ft_strncmp(argv[1], "here_doc", 9) != 0 && argc < 5)
		|| (ft_strncmp(argv[1], "here_doc", 9) == 0 && argc < 6))
		errorandexit("invalid arguments count\n", 1);
	infile = pipeandexec(argc, env, argv, fd);
	pid2 = fork();
	if (pid2 == 0)
		executer2(argv, env, fd, argc);
	close(fd[0]);
	close(fd[1]);
	waitpid(pid2, &status, 0);
	return (WEXITSTATUS(status));
}
