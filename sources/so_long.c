/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-oliv <hde-oliv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 13:23:37 by hde-oliv          #+#    #+#             */
/*   Updated: 2021/08/31 11:18:13 by hde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "mlx.h"
#include "so_long.h"

/*
** parse_map: OK
** create_game: OK
** run_game: TODO
** end_game: TODO
*/

int	main(int argc, char *argv[])
{
	t_game	game;
	int		map_fd;

	if (argc != 2)
		error("main");
	if (!is_map(argv[1]))
		error("is_map");
	map_fd = open(argv[1], O_RDONLY);
	if (map_fd == -1)
		error("open");
    game.map = parse_map(map_fd);
	create_game(&game);
	mlx_loop(game.mlx);
	return (0);
}
