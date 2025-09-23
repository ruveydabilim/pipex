/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbilim <rbilim@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 18:28:08 by rbilim            #+#    #+#             */
/*   Updated: 2025/09/23 15:41:33 by rbilim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	executer1(t_pipex args, int *fd, int i, int infile)
{
	char	**command1;
	char	*path;

	if (infile < 0)
		errorandexit("infile error", 0);
	command1 = ft_split(args.argv[i], ' ');
	if (!command1 || !command1[0])
	{
		free_all(command1, NULL, infile);
		errorandexit("command not found", 0);
	}
	path = find_path(args.env, command1);
	close(fd[0]);
	dup2(infile, 0);
	dup2(fd[1], 1);
	close(fd[1]);
	execve(path, command1, args.env);
	free_all(command1, path, infile);
	errorandexit("execve error", 0);
}

void	executer2(t_pipex arg, int *fd)
{
	int		file;
	char	**command2;
	char	*path;

	if (ft_strncmp(arg.argv[1], "here_doc", 9) == 0)
		file = open(arg.argv[arg.argc - 1], O_CREAT | O_RDWR | O_APPEND, 0644);
	else
		file = open(arg.argv[arg.argc - 1], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (file < 0)
		errorandexit("outfile error", 0);
	command2 = ft_split(arg.argv[arg.argc - 2], ' ');
	if (!command2 || !command2[0])
	{
		free_all(command2, NULL, file);
		errorandexit("command not found", 0);
	}
	path = find_path(arg.env, command2);
	close(fd[1]);
	dup2(fd[0], 0);
	dup2(file, 1);
	close(fd[0]);
	execve(path, command2, arg.env);
	free_all(command2, path, file);
	errorandexit("execve error", 0);
}

void	pipeandexec(t_pipex args, int *fd, int *infile)
{
	int		i;
	pid_t	pid;

	i = 1;
	if (ft_strncmp(args.argv[1], "here_doc", 9) == 0)
		i = 2;
	if (ft_strncmp(args.argv[1], "here_doc", 9) == 0)
		*infile = heredoc_function(args.argv[2]);
	else
		*infile = open(args.argv[1], O_RDONLY);
	while (++i < args.argc - 2)
	{
		if (pipe(fd) == -1)
			errorandexit("pipe error", 0);
		pid = fork();
		if (pid == 0)
			executer1(args, fd, i, *infile);
		else
			waitpid(pid, NULL, 0);
		close(fd[1]);
		if (*infile != -1)
			close(*infile);
		*infile = fd[0];
	}
}

int	main(int argc, char **argv, char **env)
{
	int		fd[2];
	pid_t	pid;
	int		status;
	t_pipex	args;
	int		infile;

	infile = -1;
	args.argc = argc;
	args.argv = argv;
	args.env = env;
	if (argc == 1 || (ft_strncmp(argv[1], "here_doc", 9) != 0 && argc < 5)
		|| (ft_strncmp(argv[1], "here_doc", 9) == 0 && argc < 6))
		errorandexit("invalid arguments count\n", 1);
	pipeandexec(args, fd, &infile);
	fd[0] = infile;
	fd[1] = -1;
	pid = fork();
	if (pid == 0)
		executer2(args, fd);
	close(fd[0]);
	waitpid(pid, &status, 0);
	return (WEXITSTATUS(status));
}
