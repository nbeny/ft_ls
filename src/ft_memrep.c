#include "../include/ft_ls.h"

t_elem	*ft_lstcpy_inelem(t_elem *elem)
{
	struct passwd	*pwd;
	struct group	*grp;

	pwd = getpwuid(elem->st_uid);
	if (pwd == NULL)
	{
		perror("error ! Unable to malloc structure pwd.\n");
		exit(EXIT_FAILURE);
	}
	grp = getgrgid(elem->st_gid);
	if(grp == NULL)
	{
		perror("error ! Unable to malloc structure grp.\n");
		exit(EXIT_FAILURE);
	}
	elem->pw_name = pwd->pw_name;
	elem->gr_name = grp->gr_name;
	return (elem);
}

t_elem	*ft_getstat(struct dirent *d, t_elem *elem, char *str)
{
	struct stat	st;
	char		*s;

	elem->d_namlen = d->d_namlen;
	elem->d_name = ft_strdup(d->d_name);
	s = ft_newstr_inmem(str, elem);
	if (lstat(s, &st) == -1)
	{
		perror("error stat fonction !\n");
		exit(EXIT_FAILURE);
	}
	elem->mtime = st.st_mtimespec.tv_sec;
	elem->atime = st.st_atimespec.tv_sec;
	elem->st_dev = st.st_dev;
	elem->st_mode = st.st_mode;
	elem->st_nlink = st.st_nlink;
	elem->st_uid = st.st_uid;
	elem->st_gid = st.st_gid;
	elem->st_rdev = st.st_rdev;
	elem->mtime_c = ft_set_time(elem->mtime);
	elem->atime_c = ft_set_time(elem->atime);
	elem->st_size = st.st_size;
	elem->st_blocks = st.st_blocks;
	if (S_ISLNK(elem->st_mode))
		elem->st_lkname = s;
	return (elem);
}

t_elem	*ft_new_elem(struct dirent *d, char *str)
{
	t_elem *elem;

	if (d == NULL)
	{
		perror("error ! Unable to read file.\n");
		exit(EXIT_FAILURE);
	}
	if (!(elem = (t_elem *)malloc(sizeof(t_elem))))
	{
		perror("error ! unable to malloc structure elem.\n");
		exit(EXIT_FAILURE);
	}
	elem = ft_getstat(d, elem, str);
	elem = ft_lstcpy_inelem(elem);
	return (elem);
}

t_elem	*ft_memrep(DIR *dir, char *str)
{
	struct dirent	*d;
	t_elem		*elem;
	t_elem		*save;

	d = readdir(dir);
	elem = ft_new_elem(d, str);
	save = elem;
	while ((d = readdir(dir)) != NULL)
	{
		elem->next = ft_new_elem(d, str);
		elem = elem->next;
	}
	elem->next = NULL;
	elem = save;
	return (elem);
}
