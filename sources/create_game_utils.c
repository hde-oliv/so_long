/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_game_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-oliv <hde-oliv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 17:23/28 by hde-oliv          #+#    #+#             */
/*   Updated: 2021/09/02 17:23:28 by hde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long.h"
#include "mlx.h"

void	set_collectibles_quantity(t_game *game)
{
    t_list	*rows;

	game->coins = 0;
    rows = game->map->rows;
	while (rows)
	{
		game->coins += count_collectibles(rows->content);
		rows = rows->next;
	}
}
