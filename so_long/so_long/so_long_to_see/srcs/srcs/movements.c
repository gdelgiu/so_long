/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 02:57:18 by aperrone          #+#    #+#             */
/*   Updated: 2022/03/07 02:57:23 by aperrone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	circle_(t_tile *tile)
{
	static int	i;

	if (i < 1 && tile->illegals.left)
			tile->position.x -= 1;
	else if (i < 2 && tile->illegals.down)
		tile->position.y += 1;
	else if (i < 3 && tile->illegals.right)
		tile->position.x += 1;
	else if (i < 4 && tile->illegals.up)
		tile->position.y -= 1;
	else if (i < 5 && tile->illegals.left)
		tile->position.x -= 1;
	else if (i < 6 && tile->illegals.down)
		tile->position.y += 1;
	else if (i < 7 && tile->illegals.right)
		tile->position.x += 1;
	else if (i < 8 && tile->illegals.up)
		tile->position.y -= 1;
	i++;
	if (i >= 8)
		i = 0;
}
