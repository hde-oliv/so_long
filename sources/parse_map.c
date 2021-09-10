/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-oliv <hde-oliv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 13:23:37 by hde-oliv          #+#    #+#             */
/*   Updated: 2021/09/02 16:57:35 by hde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"

t_map	*parse_map(int fd)
{
	t_map	*game_map;
	char	*row;
	t_list	*rows;

	rows = NULL;
	while (get_next_line(fd, &row) == 1)
	{
		if (!row)
			err("malloc");
		ft_lstadd_back(&rows, ft_lstnew(row));
	}
	if (!validate_rows(rows) || !validate_map(rows))
		invalid_map(&rows, row);
	game_map = (t_map *) malloc(sizeof(t_map));
	if (!game_map)
		err("malloc");
	game_map->width = ft_strlen(rows->content);
	game_map->height = ft_lstsize(rows);
	game_map->rows = rows;
	free(row);
	return (game_map);
}

int	validate_rows(t_list *rows)
{
	while (rows)
	{
		if (!validate_row(rows->content))
			return (0);
		rows = rows->next;
	}
	return (1);
}

int	validate_row(char *row)
{
	static int	fixed_len;
	int			len;

	if (!fixed_len)
		fixed_len = ft_strlen(row);
	len = ft_strlen(row);
	if (len != fixed_len || fixed_len < 3)
		return (0);
	while (len--)
	{
		if (row[len] == 'C' || row[len] == 'E' || row[len] == 'P' || \
			row[len] == '0' || row[len] == '1')
			continue ;
		else
			return (0);
	}
	return (1);
}

int	validate_map(t_list *rows)
{
	static int	collectibles;
	static int	exits;
	static int	players;
	static int	walls;

	walls = validate_walls(rows);
	while (rows)
	{
		exits += count_exits(rows->content);
		players += count_players(rows->content);
		collectibles += count_collectibles(rows->content);
		rows = rows->next;
	}
	if (!collectibles)
		return (0);
	else if (!exits)
		return (0);
	else if (!players || players > 1)
		return (0);
	else if (!walls)
		return (0);
	return (1);
}

int	validate_walls(t_list *rows)
{
	int		row_quantity;
	int		row_size;
	int		counter;
	int	answer;

	counter = 0;
	row_quantity = ft_lstsize(rows);
	row_size = ft_strlen(rows->content);
	answer = 1;
	while (counter < row_quantity)
	{
		if (counter == 0 || counter == (row_quantity - 1))
			answer = strcchr(rows->content, '1');
		else
			answer = *((char *)rows->content) == '1' && \
				*((char *)rows->content + row_size - 1) == '1';
		if (answer == 0)
			return (0);
		rows = rows->next;
		counter++;
	}
	return (1);
}
