/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbilim <rbilim@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 19:55:58 by rbilim            #+#    #+#             */
/*   Updated: 2025/09/12 16:17:51 by rbilim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	*executer1(char **argv, char **env, int *fd)
{
	int		infile;
	char	**command1;
	char	*path;
	int		i;

	i = 0;
	infile = open(argv[1], O_RDONLY);
	if (infile < 0)
		errorandexit("infile error");
	command1 = ft_split(argv[2], ' ');
	path = find_path(env, command1[0]);
	if (!path)
		return (close(infile), free_all(command1), NULL);
	close(fd[0]);
	dup2(infile, 0);
	dup2(fd[1], 1);
	close(fd[1]);
	execve(path, command1, env);
	perror("execve failed");
	close(infile);
	free_all(command1);
	free(path);
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
		errorandexit("outfile error!");
	command2 = ft_split(argv[3], ' ');
	path = find_path(env, command2[0]);
	if (!path)
		return (close(outfile), free_all(command2), NULL);
	close(fd[1]);
	dup2(fd[0], 0);
	dup2(outfile, 1);
	close(fd[0]);
	execve(path, command2, env);
	perror("execve failed");
	close(outfile);
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
		write(2, "invalid arguments count\n", 25);
		exit(EXIT_FAILURE);
	}
	if (pipe(fd) == -1)
		errorandexit("pipe error.");
	pid1 = fork();
	if (pid1 == 0)
		executer1(argv, env, fd);
	pid2 = fork();
	if (pid2 == 0)
		executer2(argv, env, fd);
	close(fd[0]);
	close(fd[1]);
	waitpid(pid2, NULL, 0);
	waitpid(pid1, NULL, 0);
	exit(EXIT_SUCCESS);
}
