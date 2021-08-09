#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdbool.h>
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include "libft.h"

typedef struct s_map
{
	int		height;
	int		width;
	t_list	*rows;
}	t_map;

bool	is_map(char *arg);
bool	row_validator(char *row);

#endif
