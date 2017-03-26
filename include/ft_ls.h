#ifndef FT_LS_H
# define FT_LS_H

# include "../libft/include/libft.h"
# include "../ft_printf/include/ft_printf.h"
# include <dirent.h>
# include <sys/stat.h>
# include <time.h>
# include <stdio.h>
# include <sys/types.h>
# include <pwd.h>
# include <uuid/uuid.h>
# include <grp.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <errno.h>

typedef struct	s_opt
{
	int	r;
	int	up_g;
	int	a;
	int	up_a;
	int	up_u;
	int	up_f;
	int	l;
	int	up_r;
}		t_opt;

typedef struct	s_elem
{
	char		*name;
	char		*path;
	time_t		date;
	mode_t		st_mode;
	nlink_t		st_nlink;
	uid_t		st_uid;
	gid_t		st_gid;
	dev_t		st_rdev;
	off_t		st_size;
	blkcnt_t	st_blocks;
	struct s_elem	*next;
}		t_elem;

/*
**Corp
*/
int		main(int ac, char **av);
int		ft_ls(char *str);
t_opt	ft_init_opt(t_opt opt);
int		ft_check_opt(char *str, t_opt *opt);
/*
**mem_tri
*/


/*
**print
*/

#endif
