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
	int	a;
	int	up_a;
	int	up_r;
	int	l;
	int	r;
	int	f;
	int	t;
	int	u;
	int	up_g;
	int	r_rep;
}				t_opt;

typedef struct	s_elem
{
	char		d_name[255];
	__uint8_t	d_namlen;
	char		*pw_name;
	char		*gr_name;
	dev_t		st_dev;			/* ID of device containing file */
	mode_t		st_mode;		/* Mode of file (see below) */
	nlink_t		st_nlink;		/* Number of hard links */
	uid_t		st_uid;			/* User ID of the file */
	gid_t		st_gid;			/* Group ID of the file */
	dev_t		st_rdev;		/* Device ID */
	time_t		atime;			/* time of last access */
	time_t		mtime;			/* time of last data modification */
	time_t		ctime;			/* time of last status change */
	time_t		birthtime;		/* time of file creation(birth) */
	off_t		st_size;		/* file size, in bytes */
	blkcnt_t	st_blocks;		/* blocks allocated for file */	
	size_t		i[4];
	struct s_elem	*next;
}				t_elem;

/*
**Corp
*/
int		main(int ac, char **av);
int		ft_ls(char *str, t_opt *opt);
t_opt	*ft_init_opt(t_opt *opt);
/*
**memrep
*/
t_elem	*ft_memrep(DIR *dir, char *str);
t_elem  *ft_new_elem(struct dirent *d, char *str);
t_elem	*ft_lstcpy_inelem(struct dirent *d, t_elem *elem);
t_elem	*ft_getstat(struct dirent *d, t_elem *elem, char *str);
/*
**trirep
*/
void	ft_trirep(t_elem *elem, t_opt *opt);
void	ft_trirep_ascii(t_elem *elem);
void	ft_trirep_u(t_elem *elem);
void	ft_trirep_t(t_elem *elem);
void	ft_reverse_order(t_elem *elem);
/*
**print
*/
void	ft_print(t_elem *elem, t_opt *opt, char *str);
void	ft_no_optprint(t_elem *elem, t_opt *opt);
void	ft_checkall_size(t_elem *elem);
void	ft_lprint(t_elem *elem, t_opt *opt);
/*
**usefull
*/
int		ft_check_opt(char *str, t_opt *opt);
void	ft_check_error(void);
void	ft_freestyle(t_elem *elem);
char	*ft_newstr(char *str, t_elem *el);
char	*ft_newstr_inmem(char *str, t_elem *el);
int		ft_isrep(t_elem *el);
#endif
