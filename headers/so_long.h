#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdbool.h>
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_map
{
	int		height;
	int		width;
	char	**rows;
}	t_map;

bool	is_map(char *arg);

#endif
