/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taeykim <taeykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 13:37:52 by taeykim           #+#    #+#             */
/*   Updated: 2022/04/07 14:58:36 by taeykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

size_t	ft_strlen(const char *str);
char	*ft_strchr(char *str, int c);
char	*ft_strdup(const char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*read_line(int fd, char *backup);
char	*return_line(char *backup);
char	*set_left_line(char *backup);
char	*get_next_line(int fd);

#endif