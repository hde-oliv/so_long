/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-oliv <hde-oliv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 10:16:33 by hde-oliv          #+#    #+#             */
/*   Updated: 2021/08/31 10:31:54 by hde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"

void	create_game(t_game *game)
{
	game->mlx = mlx_init();
	game->mlx_win = mlx_new_window(game->mlx, game->map->width * 32, game->map->height * 32, "So Long!");
	allocate_sprites(game);
	create_images(game);
	make_map(game);
	mlx_loop(game->mlx);
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
	game->heroine->ptr = mlx_xpm_file_to_image(game->mlx, "./assets/heroine.xpm", &game->heroine->x, &game->heroine->y);
	game->heroine->pixels = mlx_get_data_addr(game->heroine->ptr, &game->heroine->bpp, &game->heroine->line_size, &game->heroine->endian);
	game->bg->ptr = mlx_xpm_file_to_image(game->mlx, "./assets/bg.xpm", &game->bg->x, &game->bg->y);
	game->bg->pixels = mlx_get_data_addr(game->bg->ptr, &game->bg->bpp, &game->bg->line_size, &game->bg->endian);
	game->wall->ptr = mlx_xpm_file_to_image(game->mlx, "./assets/wall.xpm", &game->wall->x, &game->wall->y);
	game->wall->pixels = mlx_get_data_addr(game->wall->ptr, &game->wall->bpp, &game->wall->line_size, &game->wall->endian);
	game->coin->ptr = mlx_xpm_file_to_image(game->mlx, "./assets/coin.xpm", &game->coin->x, &game->coin->y);
	game->coin->pixels = mlx_get_data_addr(game->coin->ptr, &game->coin->bpp, &game->coin->line_size, &game->coin->endian);
	game->exit->ptr = mlx_xpm_file_to_image(game->mlx, "./assets/exit.xpm", &game->exit->x, &game->exit->y);
	game->exit->pixels = mlx_get_data_addr(game->exit->ptr, &game->exit->bpp, &game->exit->line_size, &game->exit->endian);
}

void	put_image(t_game *game, char pos, int x, int y)
{
	if (pos == '1')
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->wall->ptr, x * 32, y * 32);
	else if (pos == '0')
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->bg->ptr, x * 32, y * 32);
	else if (pos == 'P')
	{
		game->heroine_x = x;
		game->heroine_y = y;
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->bg->ptr, x * 32, y * 32);
	}
	else if (pos == 'C')
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->coin->ptr, x * 32, y * 32);
	else if (pos == 'E')
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->exit->ptr, x * 32, y * 32);
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
