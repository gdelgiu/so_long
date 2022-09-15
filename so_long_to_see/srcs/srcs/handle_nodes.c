/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_nodes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 08:33:36 by aperrone          #+#    #+#             */
/*   Updated: 2022/02/17 08:33:55 by aperrone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

char	ft_add_tiletype(char c, t_game *game)
{
	if (!(game->tiles))
		game->tiles = ft_newnode(WALL, game->coordinates);
	else if (c == EMPTY)
		add_empty(game);
	else if (c == WALL)
		add_wall(game);
	else if (c == PLAYER)
		add_player(game);
	else if (c == QUIT)
		add_quit(game);
	else if (c == COLLECTABLE)
	{
		ft_add_in_tail(ft_lstlast(game->tiles), EMPTY, game->coordinates);
		ft_add_in_tail(ft_lstlast(game->tiles), COLLECTABLE, game->coordinates);
		game->n_collectables++;
	}
	else if (c == ENEMY)
	{
		ft_add_in_tail(ft_lstlast(game->tiles), EMPTY, game->coordinates);
		ft_add_in_tail(ft_lstlast(game->tiles), ENEMY, game->coordinates);
		game->enemy++;
	}
	else
		ft_add_in_tail(ft_lstlast(game->tiles), EMPTY, game->coordinates);
	return (game->tiles->type);
}

t_tile	*ft_newnode(t_tiletype type, t_vector coordinates)
{
	t_tile	*new_tile;

	new_tile = malloc(sizeof(t_tile));
	if (new_tile)
	{
		new_tile->type = type;
		new_tile->position = coordinates;
		new_tile->next_tile = NULL;
	}
	return (new_tile);
}

t_tile	*ft_add_in_tail(t_tile *tail, t_tiletype t, t_vector v)
{
	t_tile	*new_node;

	if (!tail)
		return (NULL);
	new_node = ft_newnode(t, v);
	tail -> next_tile = new_node;
	tail = new_node;
	return (tail);
}

t_tile	*ft_lstlast(t_tile *tile)
{
	while (tile)
	{
		if (!tile->next_tile)
			return (tile);
		tile = tile->next_tile;
	}
	return (tile);
}
