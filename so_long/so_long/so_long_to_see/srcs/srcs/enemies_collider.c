/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies_collider.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 10:58:09 by aperrone          #+#    #+#             */
/*   Updated: 2022/03/11 10:58:14 by aperrone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

char	up(t_game *game, t_tile *enemy)
{
	return (game->map[enemy->position.y - 1][enemy->position.x]);
}

char	down(t_game *game, t_tile *enemy)
{
	return (game->map[enemy->position.y + 1][enemy->position.x]);
}

char	left(t_game *game, t_tile *enemy)
{
	return (game->map[enemy->position.y][enemy->position.x - 1]);
}

char	right(t_game *game, t_tile *enemy)
{
	return (game->map[enemy->position.y][enemy->position.x + 1]);
}
