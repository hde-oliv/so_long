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

void	invalid_map(t_list **rows)
{
	void	(*free_ptr)(void *);

	free_ptr = &free;
	ft_lstclear(rows, free_ptr);
	error("parse_map");
}