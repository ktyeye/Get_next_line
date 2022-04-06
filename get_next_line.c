/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taeykim <taeykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 13:37:22 by taeykim           #+#    #+#             */
/*   Updated: 2022/04/06 21:38:38 by taeykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	is_newline(char *buf)
{
	int	index;

	index = 0;
	while (buf[index])
	{
		if (buf[index] == '\n')
		{
			return (index);
		}
		index++;
	}
	return (-1);
}

char	*read_line(int fd, char *backup)
{
	char	*buf;
	int		len;

	len = 1;
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (0);
	while (!ft_strchr(backup, '\n') && len != 0)
	{
		len = read(fd, buf, BUFFER_SIZE);
		if (len == -1)
		{
			free(buf);
			return (0);
		}
		buf[len] = 0;
		backup = ft_strjoin(backup, buf);
	}
	free(buf);
	return (backup);
}

char	*return_line(char *backup)
{
	int		index;
	char	*result;

	if (!backup[0])
		return (0);
	index = 0;
	while (backup[index] && backup[index] != '\n')
		index++;
	result = (char *)malloc(sizeof(char) * (index + 2));
	if (!result)
		return (0);
	index = 0;
	while (backup[index] && backup[index] != '\n')
	{
		result[index] = backup[index];
		index++;
	}
	if (backup[index] == '\n')
	{
		result[index] = backup[index];
		index++;
	}
	result[index] = 0;
	return (result);
}

char	*set_left_line(char *backup)
{
	char	*temp;
	int		line_size;

	line_size = is_newline(backup);
	if (line_size == -1)
	{
		free(backup);
		return (0);
	}
	temp = ft_strdup(&backup[line_size + 1]);
	free(backup);
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	*backup;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	backup = read_line(fd, backup);
	if (!backup)
		return (0);
	line = return_line(backup);
	backup = set_left_line(backup);
	return (line);
}
