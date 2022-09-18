/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movements.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 05:56:35 by aperrone          #+#    #+#             */
/*   Updated: 2022/03/14 05:56:40 by aperrone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	player_up(t_game *game)
{
	player_up_img(game);
	game->moves_count++;
	ft_putnbr2(game->moves_count);
	write(1, "\n", 1);
	game->player->tile->position.y -= 1;
}

void	player_down(t_game *game)
{
	player_down_img(game);
	game->moves_count++;
	ft_putnbr2(game->moves_count);
	write(1, "\n", 1);
	game->player->tile->position.y += 1;
}

void	player_left(t_game *game)
{
	player_left_img(game);
	game->moves_count++;
	ft_putnbr2(game->moves_count);
	write(1, "\n", 1);
	game->player->tile->position.x -= 1;
}

void	player_right(t_game *game)
{
	player_right_img(game);
	game->moves_count++;
	ft_putnbr2(game->moves_count);
	write(1, "\n", 1);
	game->player->tile->position.x += 1;
}

void	ft_putnbr2(int nbr)
{
	int	c;

	c = nbr + '0';
	if (nbr < 10)
		write (1, &c, 1);
	else
	{
		ft_putnbr2(nbr / 10);
		ft_putnbr2(nbr % 10);
	}
}
