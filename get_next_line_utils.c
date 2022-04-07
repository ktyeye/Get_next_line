/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taeykim <taeykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 16:30:12 by taeykim           #+#    #+#             */
/*   Updated: 2022/04/07 14:58:53 by taeykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int	index;

	index = 0;
	while (str[index])
		index++;
	return (index);
}

char	*ft_strdup(const char *str)
{
	char	*temp;
	size_t	index;

	temp = (char *)malloc((ft_strlen(str) + 1) * sizeof(char));
	if (!temp)
		return (0);
	index = 0;
	while (index < ft_strlen(str))
	{
		temp[index] = str[index];
		index++;
	}
	temp[index] = 0;
	return (temp);
}

char	*ft_strchr(char *str, int c)
{
	if (!str)
		return (0);
	while (*str)
	{
		if (*str == (unsigned char)c)
			return ((char *)str);
		str++;
	}
	if (*str == (unsigned char)c)
		return ((char *)str);
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	index;
	size_t	offset;
	char	*str;

	if (!s1)
		s1 = ft_strdup("");
	if (!s1 || !s2)
		return (0);
	str = (char *)malloc(sizeof(char) * ((ft_strlen(s1) + ft_strlen(s2)) + 1));
	if (!str)
		return (0);
	index = -1;
	offset = 0;
	while (s1[++index])
			str[index] = s1[index];
	while (s2[offset])
		str[index++] = s2[offset++];
	str[index] = 0;
	free(s1);
	return (str);
}
