/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdel-giu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 07:41:46 by gdel-giu          #+#    #+#             */
/*   Updated: 2022/08/12 07:41:49 by gdel-giu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_solong.h"

int	borders_ok(t_map m)
{
	int	x;
	int	y;

	y = 0;
	while ((m.data_matrix)[y])
	{
		x = 0;
		while (m.data_matrix[y][x])
		{
			if (m.data_matrix[y][x] != '1')
			{
				if ((y == 0 || y == m.height - 1))
					return (0);
				if ((x == 0 || x == m.width - 1))
					return (0);
			}
			x++;
		}
		y++;
	}
	return (1);
}

int	has_mandatory(t_map m)
{
	int		i;
	char	at_least_value;

	i = 0;
	at_least_value = 0;
	while (++i < m.height - 1)
	{
		if (ft_strchr(m.data_matrix[i], 'C'))
			at_least_value = at_least_value | 0B00000001;
		if (ft_strchr(m.data_matrix[i], 'P'))
			at_least_value = at_least_value | 0B00000010;
		if (ft_strchr(m.data_matrix[i], 'E'))
			at_least_value = at_least_value | 0B00000100;
	}
	if (at_least_value < 7)
		return (0);
	return (1);
}

int	char_is_legal(t_map map)
{
	char	**chars;
	int		x;
	int		y;

	y = 0;
	chars = map.data_matrix;
	while (chars[y])
	{
		x = 0;
		while (x < map.width - 1 && chars[y][x] != '\n')
		{
			if (!ft_strchr("01CPE", chars[y][x]))
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

int	precheck(t_map m)
{
	if (!has_mandatory(m))
		return (0);
	if (!borders_ok(m))
		return (0);
	if (!char_is_legal(m))
		return (0);
	return (1);
}
