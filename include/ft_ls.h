/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 01:43:46 by nbeny             #+#    #+#             */
/*   Updated: 2017/04/12 01:43:51 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	int		a;
	int		up_a;
	int		up_r;
	int		l;
	int		r;
	int		f;
	int		t;
	int		u;
	int		up_g;
	int		r_rep;
	size_t	i[4];
	size_t	z;
	int		isarg[2];
}				t_opt;

typedef struct	s_elem
{
	char		*d_name;
	char		*lk_name;
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
	char		*atime_c;
	char		*mtime_c;
	char		*ctime_c;
	char		*birthtime_c;
	off_t		st_size;		/* file size, in bytes */
	blkcnt_t	st_blocks;		/* blocks allocated for file */
	struct s_elem	*next;
	struct s_elem	*previous;
}				t_elem;

/*
**Corp
*/
int		main(int ac, char **av);
int		ft_ls(char *str, t_opt *opt);
t_opt	*ft_init_opt(t_opt *opt);
t_elem		*ft_is_source(char *str);
void		ft_print_source(t_elem *el, t_opt *opt);
void		ft_check_source(char **av, t_opt *opt, int i);
int		ft_is_dir(char *str);
int		ft_is_src(char *str);
/*
**memrep
*/
t_elem	*ft_memrep(DIR *dir, char *str);
t_elem  *ft_new_elem(struct dirent *d, char *str);
t_elem	*ft_lstcpy_inelem(t_elem *elem);
t_elem	*ft_getstat(t_elem *elem, char *str);
char	*ft_set_time(time_t st_tim);
void	ft_previous_print(t_elem *elem, t_opt *opt);
/*
**trirep
*/
void	ft_trirep(t_elem *elem, t_opt *opt);
void	ft_trirep_ascii(t_elem *elem);
void	ft_trirep_u(t_elem *elem);
void	ft_trirep_tt(t_elem *elem);
void	ft_tri_swap(t_elem *save, t_elem *elem);
void	ft_revtri_ascii(t_elem *elem);
void	ft_revtri_t(t_elem *elem);
void	ft_revtri_u(t_elem *elem);
void	ft_reverse_list(t_elem *elem);
/*
**print
*/
void	ft_print(t_elem *elem, t_opt *opt, char *str);
void	ft_no_optprint(t_elem *elem, t_opt *opt);
void	ft_checkall_size(t_elem *elem, t_opt *opt);
void	ft_lprint(t_elem *elem, t_opt *opt);
void	ft_print_time(t_elem *elem, t_opt *opt);
void	ft_previous_print(t_elem *elem, t_opt *opt);
void	ft_check_str(char *str, t_opt *opt);
/*
**tools
*/
int		ft_check_opt(char *str, t_opt *opt);
void	ft_check_error(void);
void	ft_freestyle(t_elem *elem, char *str);
char	*ft_newstr(char *str, t_elem *el);
char	*ft_newstr_inmem(char *str, t_elem *el);
int		ft_isrep(t_elem *el);
t_elem	*ft_first_source(void);
#endif
