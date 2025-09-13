/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbilim <rbilim@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 17:29:17 by rbilim            #+#    #+#             */
/*   Updated: 2025/09/13 13:39:27 by rbilim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "./get_next_line/get_next_line.h"
# include <stdio.h>

int		heredoc_helper(int *fd, char **argv, char **env);
void	free_all(char **arr);
void	errorandexit(char *message);
char	*find_path(char **env, char *cmd);

#endif