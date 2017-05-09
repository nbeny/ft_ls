/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 01:43:46 by nbeny             #+#    #+#             */
/*   Updated: 2017/05/08 20:02:45 by nbeny            ###   ########.fr       */
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
	int				a;
	int				up_a;
	int				up_r;
	int				l;
	int				r;
	int				f;
	int				t;
	int				u;
	int				n;
	int				g;
	int				o;
	int				r_rep;
	size_t			i[4];
	size_t			j[3];
	size_t			z;
	int				isarg[2];
	int				is;
	int				norme;
}				t_opt;

typedef struct	s_elem
{
	char			*d_name;
	char			*lk_name;
	__uint8_t		d_namlen;
	char			*pw_name;
	char			*gr_name;
	dev_t			st_dev;
	mode_t			st_mode;
	nlink_t			st_nlink;
	uid_t			st_uid;
	gid_t			st_gid;
	dev_t			st_rdev;
	time_t			atime;
	time_t			mtime;
	char			*atime_c;
	char			*mtime_c;
	off_t			st_size;
	blkcnt_t		st_blocks;
	struct s_elem	*next;
}				t_elem;

/*
**Corp
*/
int				main(int ac, char **av);
t_opt			*ft_main_norme(int ac);
void			ft_main_norme2(t_elem *elem, t_opt *opt);
int				ft_ls(char *str, t_opt *opt);
void			ft_end(t_elem *el, DIR *dir, char *str);
t_opt			*ft_init_opt(t_opt *opt);
t_elem			*ft_is_source(char *str);
void			ft_print_source(t_elem *el, t_opt *opt);
void			ft_check_source(char **av, t_opt *opt, int i);
t_elem			*ft_check_source_norme(char **av, t_opt *opt, int i);
t_elem			*ft_check_source_norme2(char **av, t_opt *opt, \
										int i, t_elem *el);
t_elem			*ft_check_dir(char **av, t_opt *opt, int i);
t_elem			*ft_check_dir_norme(char **av, int i, t_opt *opt);
int				ft_is_dir(char *str);
int				ft_is_src(char *str);
DIR				*ft_dirdir(char *str);
/*
**memrep
*/
t_elem			*ft_memrep(DIR *dir, char *str);
t_elem			*ft_new_elem(struct dirent *d, char *str);
t_elem			*ft_lstcpy_inelem(t_elem *elem);
t_elem			*ft_getstat(t_elem *elem, char *str);
char			*ft_set_time(time_t st_tim);
void			ft_check_lnk(t_elem *elem, char *str, struct stat st);
/*
**trirep
*/
void			ft_trirep(t_elem *elem, t_opt *opt);
void			ft_trirep_ascii(t_elem *elem);
void			ft_trirep_u(t_elem *elem);
void			ft_trirep_tt(t_elem *elem);
void			ft_revlist(t_elem *elem);
void			ft_swap_char(t_elem *save, t_elem *elsa);
void			ft_swap_time(t_elem *save, t_elem *elsa);
void			ft_swap_st(t_elem *save, t_elem *elsa);
void			ft_swap_all(t_elem *save, t_elem *elsa);
/*
**print
*/
void			ft_print(t_elem *elem, t_opt *opt, char *str);
void			ft_lets_go(t_elem *elem, t_opt *opt);
void			ft_no_optprint(t_elem *elem, t_opt *opt);
void			ft_checkall_size(t_elem *elem, t_opt *opt);
void			ft_checkall_size_norme(t_elem *elem, t_opt *opt);
void			ft_lprint(t_elem *elem, t_opt *opt);
void			ft_lprint_norme(t_elem *elem, t_opt *opt);
void			ft_print_time(t_elem *elem, t_opt *opt);
void			ft_print_time_norme(t_elem *elem, t_opt *opt);
void			ft_check_str(char *str, t_opt *opt);
void			ft_checkdev_size(t_elem *elem, t_opt *opt);
void			ft_check_dev_size_norme(t_elem *elem, t_opt *opt);
/*
**tools
*/
int				ft_check_opt(char *str, t_opt *opt);
void			ft_check_error(void);
void			ft_freestyle(t_elem *elem);
char			*ft_newstr(char *str, t_elem *el);
char			*ft_newstr_inmem(char *str, t_elem *el);
int				ft_isrep(t_elem *el);
t_elem			*ft_first_source(void);
void			ft_free_arg(t_elem *el);
t_elem			*ft_free_firstone(t_elem *elem);
#endif
