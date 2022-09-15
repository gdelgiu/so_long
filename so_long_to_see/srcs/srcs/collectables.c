/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectables.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 18:45:55 by aperrone          #+#    #+#             */
/*   Updated: 2022/03/09 18:46:11 by aperrone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	collectables_init(t_game *game)
{
	int	w;
	int	h;

	game->collectable = malloc(sizeof(t_collectables));
	game->collectable->current_img = mlx_xpm_file_to_image(game->mlx,
			"./sprites/collectables/collectable_0.xpm", &w, &h);
}

void	check_ultimate(t_game *game)
{
	if (!(game->n_player == 1 && game->n_walls > 0
			&& game->n_empty > 0 && game->n_quit >= 1
			&& game->n_collectables > 0))
	{
		ft_putstr("Map Error");
		exit (0);
	}
}
