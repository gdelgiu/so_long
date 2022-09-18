/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_collider.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 11:00:45 by aperrone          #+#    #+#             */
/*   Updated: 2022/03/11 11:00:46 by aperrone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

char	p_up(t_game *game)
{
	t_vector	p_pos;

	p_pos = game->player->tile->position;
	return (game->map[p_pos.y - 1][p_pos.x]);
}

char	p_down(t_game *game)
{
	t_vector	p_pos;

	p_pos = game->player->tile->position;
	return (game->map[p_pos.y + 1][p_pos.x]);
}

char	p_left(t_game *game)
{
	t_vector	p_pos;

	p_pos = game->player->tile->position;
	return (game->map[p_pos.y][p_pos.x - 1]);
}

char	p_right(t_game *game)
{
	t_vector	p_pos;

	p_pos = game->player->tile->position;
	return (game->map[p_pos.y][p_pos.x + 1]);
}

void	add_player(t_game *game)
{
	ft_add_in_tail(ft_lstlast(game->tiles), PLAYER, game->coordinates);
	game->n_player++;
}
