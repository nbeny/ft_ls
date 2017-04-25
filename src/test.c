/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 16:55:48 by nbeny             #+#    #+#             */
/*   Updated: 2017/03/04 16:58:39 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include<dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>
#include <string.h>

#define couleur(param) fprintf(stderr,"\b \033[%sm",param)

void affiche_status (char * nom)
{
	struct stat status;
	struct passwd *pwd;
	struct group  *grp;
	DIR * ptdir;

	if(stat(nom,& status) >= 0)
	{
		if(strncmp(nom, "..", 2) != 0 && strncmp(nom, ".", 1) != 0)
		{

			if(S_ISBLK(status.st_mode))
				fprintf(stderr, "b" );
			else if(S_ISCHR(status.st_mode))
				fprintf(stderr, "c" );
			else if(S_ISDIR(status.st_mode))
				fprintf(stderr, "d" );
			else if(S_ISFIFO(status.st_mode))
				fprintf(stderr, "p" );
			else if(S_ISLNK(status.st_mode))
				fprintf(stderr, "l" );
			else if(S_ISREG(status.st_mode))
				fprintf(stderr, "-" );
			else if(S_ISSOCK(status.st_mode))
				fprintf(stderr, "s" );

			fprintf(stderr, status.st_mode & S_IRUSR ? "r" : "-" );
			fprintf(stderr, status.st_mode & S_IWUSR ? "w" : "-" );
			fprintf(stderr, status.st_mode & S_IXUSR ? "x" : "-" );
			fprintf(stderr, status.st_mode & S_IRGRP ? "r" : "-" );
			fprintf(stderr, status.st_mode & S_IWGRP ? "w" : "-" );
			fprintf(stderr, status.st_mode & S_IXGRP ? "x" : "-" );
			fprintf(stderr, status.st_mode & S_IROTH ? "r" : "-" );
			fprintf(stderr, status.st_mode & S_IWOTH ? "w" : "-" );
			fprintf(stderr, status.st_mode & S_IXOTH ? "x" : "-" );

			fprintf(stderr,"\t%hu",status.st_nlink);

			if ((pwd = getpwuid(status.st_uid)) != NULL)
				fprintf(stderr,"\t%s", pwd->pw_name);
			if ((grp = getgrgid(status.st_gid)) != NULL)
				fprintf(stderr,"\t%s", grp->gr_name);

			fprintf(stderr,"\t%lld",status.st_size);
			fflush(stdin);
			fprintf(stderr,"\t%-24.24s\t",ctime(&status.st_mtime));
			fflush(stdin);

			if((ptdir=opendir(nom)) != NULL)
			{
				couleur("34" );
				fprintf(stderr,"%s\n",nom);
				couleur("0" );
			}
			else if (S_ISREG(status.st_mode ) && status.st_mode & 0111)
			{
				couleur("32" );
				fprintf(stderr,"%s\n",nom);
				couleur("0" );
			}
			/* ((status.st_mode & S_IFMT) != S_IFREG) : .exe */

			else
				fprintf(stderr,"%s\n",nom);
		}
	}
	else perror("STAT" );
}

int main (int argc, char * argv[])
{

	DIR * ptdir;
	struct dirent * entree;
	int i;
	if(argc==1)
	{
		if ((ptdir = opendir("." )) != NULL)
		{
			while ((entree = readdir (ptdir)) != NULL)
			{
				affiche_status(entree->d_name);
			}
		}
	}
	else
	{
		for(i=1;i<argc; i++)
		{
			if ((ptdir = opendir(argv[i])) != NULL)
			{
				fprintf(stderr,"%s :\n",argv[i]);
				while ((entree = readdir (ptdir)) != NULL)
				{
				    affiche_status(entree->d_name);

				}
			}
		}
	}
	closedir(ptdir);
	return 0;
}
