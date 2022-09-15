/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   empty.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdel-giu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 19:11:56 by gdel-giu          #+#    #+#             */
/*   Updated: 2022/02/22 19:11:59 by gdel-giu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	empty_init(t_game *game)
{
	int	w;
	int	h;

	game->empty = malloc(sizeof(t_empty));
	game->empty->img = mlx_xpm_file_to_image(game->mlx,
			"./sprites/empty/empty.xpm", &w, &h);
}

void	add_empty(t_game *game)
{
	ft_add_in_tail(ft_lstlast(game->tiles), EMPTY, game->coordinates);
	game->n_empty++;
}
