/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 15:25:05 by aperrone          #+#    #+#             */
/*   Updated: 2022/01/24 19:48:44 by aperrone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *saved_str, char *buffer)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!saved_str)
	{
		saved_str = malloc(sizeof(char));
		saved_str[0] = '\0';
	}
	if (!saved_str || !buffer)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen(saved_str) + ft_strlen(buffer) + 1));
	if (!str)
		return (NULL);
	i = -1;
	while (saved_str[++i])
		str[i] = saved_str[i];
	j = 0;
	while (buffer[j])
		str[i++] = buffer[j++];
	str[i] = '\0';
	free(saved_str);
	return (str);
}

char	*ft_strchr(char *str, char c)
{
	size_t	i;

	if (!str)
		return (NULL);
	if (!c)
		return (&str[ft_strlen(str)]);
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (&str[i]);
		i++;
	}
	return (NULL);
}

char	*ft_res(int fd, char *saved_str)
{
	char	*buffer;
	int		i;

	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	i = 1;
	while (!ft_strchr(saved_str, '\n') && i)
	{
		i = read(fd, buffer, 1);
		if (i == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[i] = '\0';
		saved_str = ft_strjoin(saved_str, buffer);
	}
	free(buffer);
	return (saved_str);
}

char	*ft_save(char *saved_str)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	while (saved_str[i] && saved_str[i] != '\n')
		i++;
	if (!saved_str[i])
	{
		free(saved_str);
		return (NULL);
	}
	str = malloc(sizeof(char) * (ft_strlen(saved_str) - i + 1));
	if (!str)
		return (NULL);
	i++;
	while (saved_str[i])
		str[j++] = saved_str[i++];
	str[j] = '\0';
	free(saved_str);
	return (str);
}
