/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbilim <rbilim@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 16:39:04 by rbilim            #+#    #+#             */
/*   Updated: 2025/09/06 14:46:49 by rbilim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*ft_strchr1(const char *s, int c);
char	*ft_strjoin1(char *s1, char *s2);
size_t	ft_strlen1(const char *s);
char	*ft_strdup1(const char *src);
char	*ft_substr1(char *s, unsigned int start, size_t len);

#endif