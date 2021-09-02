/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-oliv <hde-oliv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 13:23:37 by hde-oliv          #+#    #+#             */
/*   Updated: 2021/08/31 17:34:19 by hde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"

int	count_exits(char *row)
{
	int	answer;

	answer = 0;
	while (*row)
	{
		if (*row == 'E')
			answer++;
		row++;
	}
	return (answer);
}

int	count_players(char *row)
{
	int	answer;

	answer = 0;
	while (*row)
	{
		if (*row == 'P')
			answer++;
		row++;
	}
	return (answer);
}

int	count_collectibles(char *row)
{
	int	answer;

	answer = 0;
	while (*row)
	{
		if (*row == 'C')
			answer++;
		row++;
	}
	return (answer);
}

bool	is_map(char *arg)
{
	char	*dot_location;

	dot_location = ft_strrchr(arg, '.');
	if (dot_location)
		return (!ft_strncmp(dot_location, ".ber", 4));
	return (false);
}

bool	strcchr(char *s, char c)
{
	while (*s)
	{
		if (*s != c)
			return (false);
		s++;
	}
	return (true);
}
