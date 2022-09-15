/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_illegals.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 04:51:48 by aperrone          #+#    #+#             */
/*   Updated: 2022/03/14 04:51:59 by aperrone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	update_player_illegal(t_game *game)
{
	p_static_collisions(game);
	p_dinamic_collisions(game);
}

void	update_enemies_illegal(t_game *game, t_tile *enemy)
{
	e_static_collisions(game, enemy);
	e_dinamic_collisions(game, enemy);
}

void	last_drop(char **map, t_game *game, int i)
{
	if (map[game->coordinates.y - 1][i] == 'P'
		|| map[game->coordinates.y - 1][i] == 'C'
		|| map[game->coordinates.y - 1][i] == 'Q'
		|| map[game->coordinates.y - 1][i] == 'E'
		|| map[game->coordinates.y - 1][i - 2] == '0')
	{
		ft_putstr("Invalid Map\n");
		exit (0);
	}
}
