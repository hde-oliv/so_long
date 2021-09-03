/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-oliv <hde-oliv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 10:16:33 by hde-oliv          #+#    #+#             */
/*   Updated: 2021/09/02 17:26:19 by hde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"

void	create_game(t_game *game)
{
	game->mlx = mlx_init();
	game->mlx_win = mlx_new_window(game->mlx, game->map->width * 16, \
								   game->map->height * 16, "So Long!");
	set_collectibles_quantity(game);
	allocate_sprites(game);
	create_images(game);
	make_map(game);
}

void	allocate_sprites(t_game *game)
{
	game->heroine = (t_img *) malloc(sizeof(t_img));
	if (!game->heroine)
		error("malloc");
	game->wall = (t_img *) malloc(sizeof(t_img));
	if (!game->heroine)
		error("malloc");
	game->bg = (t_img *) malloc(sizeof(t_img));
	if (!game->heroine)
		error("malloc");
	game->coin = (t_img *) malloc(sizeof(t_img));
	if (!game->heroine)
		error("malloc");
	game->exit = (t_img *) malloc(sizeof(t_img));
	if (!game->heroine)
		error("malloc");
}

void	create_images(t_game *game)
{
	game->heroine->ptr = wrap_xpm(game, "./assets/heroine.xpm", game->heroine);
	game->bg->ptr = wrap_xpm(game, "./assets/bg.xpm", game->bg);
	game->wall->ptr = wrap_xpm(game, "./assets/wall.xpm", game->wall);
	game->coin->ptr = wrap_xpm(game, "./assets/coin.xpm", game->coin);
	game->exit->ptr = wrap_xpm(game, "./assets/exit.xpm", game->exit);
	game->heroine->pixels = wrap_data(game->heroine);
	game->bg->pixels = wrap_data(game->bg);
	game->wall->pixels = wrap_data(game->wall);
	game->coin->pixels = wrap_data(game->coin);
	game->exit->pixels = wrap_data(game->exit);
}

void	put_image(t_game *game, char pos, int x, int y)
{
	if (pos == '1')
		mlx_put_image_to_window(game->mlx, game->mlx_win, \
								game->wall->ptr, x * 16, y * 16);
	else if (pos == '0')
		mlx_put_image_to_window(game->mlx, game->mlx_win, \
								game->bg->ptr, x * 16, y * 16);
	else if (pos == 'P')
	{
		game->heroine_x = x;
		game->heroine_y = y;
		mlx_put_image_to_window(game->mlx, game->mlx_win, \
								game->bg->ptr, x * 16, y * 16);
	}
	else if (pos == 'C')
		mlx_put_image_to_window(game->mlx, game->mlx_win, \
								game->coin->ptr, x * 16, y * 16);
	else if (pos == 'E')
		mlx_put_image_to_window(game->mlx, game->mlx_win, \
								game->exit->ptr, x * 16, y * 16);
}

void	make_map(t_game *game)
{
	int		i;
	int		j;
	t_list	*tmp;

	i = -1;
	tmp = game->map->rows;
	while (i++ < game->map->height && tmp)
	{
		j = -1;
		while (j++ < game->map->width)
		{
			put_image(game, ((char *)(tmp->content))[j], j, i);
		}
		tmp = tmp->next;
	}
}
