/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-oliv <hde-oliv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 13:23:37 by hde-oliv          #+#    #+#             */
/*   Updated: 2021/08/24 13:38:11 by hde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "mlx.h"
#include "so_long.h"

/*
** parse_map: OK
** create_game: TODO
** run_game: TODO
** end_game: TODO
*/

int	main(int argc, char *argv[])
{
	t_map	*game_map;
	int		map_fd;

	if (argc != 2)
		error("main");
	if (!is_map(argv[1]))
		error("is_map");
	map_fd = open(argv[1], O_RDONLY);
	if (map_fd == -1)
		error("open");
	game_map = parse_map(map_fd);
	return (0);
}
