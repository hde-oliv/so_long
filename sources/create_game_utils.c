/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_game_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-oliv <hde-oliv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 17:42/55 by hde-oliv          #+#    #+#             */
/*   Updated: 2021/09/02 17:42:55 by hde-oliv         ###   ########.fr       */
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

void	*wrap_xpm(t_game *game, char *filename, t_img *img)
{
	return (mlx_xpm_file_to_image(game->mlx, filename, &img->x, &img->y));
}

void	*wrap_data(t_img *img)
{
	return (mlx_get_data_addr(img->ptr, &img->bpp, \
							&img->line_size, &img->endian));
}
