#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdbool.h>
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include "libft.h"

/* map parsing functions */
typedef struct s_map
{
	int		height;
	int		width;
	t_list	*rows;
}	t_map;

bool	is_map(char *arg);
bool	validate_row(char *row);
t_map	*parse_map(int fd);

/* error functions */
# define EINVM "Invalid map.\n"

void	error(const char *err_func);
void	r_error(const char *function);
void	invalid_map(t_list **rows);

#endif
