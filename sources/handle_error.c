/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-oliv <hde-oliv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 13:23:37 by hde-oliv          #+#    #+#             */
/*   Updated: 2021/08/31 11:22:55 by hde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"

void	r_error(const char *function)
{
	if (!ft_memcmp(function, "parse_map", 10))
		printf("parse_map: %s", EINVM);
	if (!ft_memcmp(function, "main", 4))
		printf("main: %s", EINAR);
	if (!ft_memcmp(function, "is_map", 6))
		printf("is_map: %s", EINAM);
}

void	error(const char *err_func)
{
	printf("Error\n");
	if (errno == 0)
		r_error(err_func);
	else
		perror(err_func);
	exit(1);
}

void	invalid_map(t_list **rows, char *row)
{
	void	(*free_ptr)(void *);

	if (row)
		free(row);
	free_ptr = &free;
	ft_lstclear(rows, free_ptr);
	error("parse_map");
}
