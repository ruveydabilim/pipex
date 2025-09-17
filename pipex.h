/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbilim <rbilim@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 19:55:47 by rbilim            #+#    #+#             */
/*   Updated: 2025/09/17 15:03:54 by rbilim           ###   ########.fr       */
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

void	free_all(char **cmd, char *path, int file);
void	errorandexit(char *message);
char	*find_path(char **env, char **cmd);

#endif