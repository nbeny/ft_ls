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
}				t_opt;

typedef struct	s_elem
{
	dev_t			st_dev;		/* ID of device containing file */
	mode_t			st_mode;	/* Mode of file (see below) */
	nlink_t			st_nlink;	/* Number of hard links */
	uid_t			st_uid;		/* User ID of the file */
	gid_t			st_gid;		/* Group ID of the file */
	dev_t			st_rdev;	/* Device ID */
	struct timespec	st_atimespec;		/* time of last access */
	struct timespec	st_mtimespec;		/* time of last data modification */
	struct timespec	st_ctimespec;		/* time of last status change */
	struct timespec	st_birthtimespec;	/* time of file creation(birth) */
	off_t			st_size;	/* file size, in bytes */
	blkcnt_t		st_blocks;	/* blocks allocated for file */	
	struct s_elem	*next;
}				t_elem;

/*
**Corp
*/
int		main(int ac, char **av);
int		ft_ls(char *str);
t_opt	*ft_init_opt(t_opt *opt);
int		ft_check_opt(char *str, t_opt *opt);
int		ft_memrep(struct dirent *d, DIR *dir, t_elem *elem);
/*
**mem_tri
*/


/*
**print
*/

#endif
