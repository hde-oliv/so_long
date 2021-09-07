/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_minimize.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-oliv <hde-oliv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 12:39:23 by hde-oliv          #+#    #+#             */
/*   Updated: 2021/09/07 17:18:04 by hde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"

static void	put_image_m(t_game *game, char pos, int x, int y)
{
	if (pos == '1')
		mlx_put_image_to_window(game->mlx, game->mlx_win, \
								game->wall->ptr, x * 16, y * 16);
	else if (pos == '0' || pos == 'P')
		mlx_put_image_to_window(game->mlx, game->mlx_win, \
								game->bg->ptr, x * 16, y * 16);
	else if (pos == 'C')
		mlx_put_image_to_window(game->mlx, game->mlx_win, \
								game->coin->ptr, x * 16, y * 16);
	else if (pos == 'E')
		mlx_put_image_to_window(game->mlx, game->mlx_win, \
								game->exit->ptr, x * 16, y * 16);
}

int	handle_minimize(void *p)
{
	t_game	*game;

	game = (t_game *) p;
	make_map(game, &put_image_m);
	refresh_player(game);
	return (0);
}
