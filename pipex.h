/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbilim <rbilim@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 19:55:47 by rbilim            #+#    #+#             */
/*   Updated: 2025/09/23 12:20:37 by rbilim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>
# include "./libft/libft.h"
# include "./get_next_line/get_next_line.h"

typedef struct s_pipex
{
	char	**env;
	char	**argv;
	int		argc;
}	t_pipex;

void	free_all(char **cmd, char *path, int file);
void	errorandexit(char *message, int errstatus);
char	*find_path(char **env, char **cmd);
int		heredoc_function(char *limiter);

#endif