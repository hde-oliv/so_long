#include "so_long.h"
#include "libft.h"

void	my_error(const char *function)
{
	if (!ft_memcmp(function, "map_parser", 10))
		printf(EINVM);
}

void	error(const char *err_func)
{
	printf("Error\n");
	if (errno == 0)
		my_error(err_func);
	else
		perror(err_func);
	exit(1);
}

void	invalid_map(t_list **rows)
{
    void (*free_ptr)(void *);

	free_ptr = &free;
	ft_lstclear(rows, free_ptr);
	error("map_parser");
}
