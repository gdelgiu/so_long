/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_collisions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdel-giu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 18:45:44 by gdel-giu          #+#    #+#             */
/*   Updated: 2022/03/24 11:03:36 by amaso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	p_static_collisions(t_game *game)
{
	p_wall_collisions(game);
	p_quit_collisions(game);
}

void	e_static_collisions(t_game *game, t_tile *enemy)
{
	if (up(game, enemy) == '1' || up(game, enemy) == 'E'
		|| up(game, enemy) == 'C')
		enemy->illegals.up = 0;
	else
		enemy->illegals.up = 1;
	if (down(game, enemy) == '1' || down(game, enemy) == 'E'
		|| down(game, enemy) == 'C')
		enemy->illegals.down = 0;
	else
		enemy->illegals.down = 1;
	if (left(game, enemy) == '1' || left(game, enemy) == 'E'
		|| left(game, enemy) == 'C')
		enemy->illegals.left = 0;
	else
		enemy->illegals.left = 1;
	if (right(game, enemy) == '1' || right(game, enemy) == 'E'
		|| right(game, enemy) == 'C')
		enemy->illegals.right = 0;
	else
		enemy->illegals.right = 1;
}

void	p_dinamic_collisions(t_game *game)
{
	t_tile		*tiles;
	t_vector	p_pos;

	tiles = game->tiles;
	p_pos = game->player->tile->position;
	while (tiles)
	{
		if (tiles->type == COLLECTABLE
			&& check_position(tiles->position, p_pos))
		{
			game->flag_collect = 1;
			game->n_collectables--;
			if (game->n_collectables == 0)
				game->flag_quit = 1;
			tiles->type = EMPTY;
		}
		if (tiles->type == QUIT && check_position(tiles->position, p_pos))
			if (game->flag_quit == 1)
				exit(0);
		if (tiles->type == ENEMY && check_position(tiles->position, p_pos))
			exit(0);
		tiles = tiles->next_tile;
	}
}

void	e_dinamic_collisions(t_game *game, t_tile *enemy)
{
	if (check_position(enemy->position, game->player->tile->position))
		exit(0);
}

void	p_wall_collisions(t_game *game)
{
	if (p_up(game) == '1')
		game->player->illegals.up = 0;
	else
		game->player->illegals.up = 1;
	if (p_down(game) == '1')
		game->player->illegals.down = 0;
	else
		game->player->illegals.down = 1;
	if (p_left(game) == '1')
		game->player->illegals.left = 0;
	else
		game->player->illegals.left = 1;
	if (p_right(game) == '1')
		game->player->illegals.right = 0;
	else
		game->player->illegals.right = 1;
}
