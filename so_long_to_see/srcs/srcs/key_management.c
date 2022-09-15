/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_management.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 09:28:59 by aperrone          #+#    #+#             */
/*   Updated: 2022/02/22 09:29:02 by aperrone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	ft_dokey(int key, t_game *game)
{
	t_tile	*tile;

	update_map(game, game->player->tile, EMPTY);
	tile = game->tiles;
	if (key == 13 && game->player->illegals.up)
		player_up(game);
	if (key == 1 && game->player->illegals.down)
		player_down(game);
	if (key == 2 && game->player->illegals.right)
		player_right(game);
	if (key == 0 && game->player->illegals.left)
		player_left(game);
	if (key == 53)
	{
		mlx_destroy_window(game->mlx, game->win->win);
		exit (0);
	}
	update_map(game, game->player->tile, PLAYER);
	update_player_illegal(game);
}

int	ft_iskey(int key)
{
	return (key == 13 || key == 1 || key == 0 || key == 2 || key == 53);
}

int	deal_key(int key, t_game *game)
{
	if (ft_iskey(key))
		ft_dokey(key, game);
	return (0);
}
