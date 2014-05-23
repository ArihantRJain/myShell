#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <dirent.h>
#include <fcntl.h>
#include <pwd.h>
#include <grp.h>

int myls(int argc, char *argv[])
{	
	DIR *directory; //Stores a pointer to the directory
	struct dirent *file;
	int i;
	struct stat sb;
	struct passwd *pwd;
	struct group *grp;
	if(!strcmp(argv[1], "-l"))
	{
		for(i=2; i<argc; i++)
		{
			if(!access(argv[i],F_OK)) //Check if the directory specified by argv[i] exists.
			{
				directory=opendir(argv[i]); //If it exists, then open the directory.

				if(directory!=NULL)
				{
					while((file=readdir(directory))!=NULL) //Read each entry in the directory.
					{
	
						if (stat(file->d_name, &sb) == -1) 
						{
							perror("stat");
						}
						//Display the type of file.
						switch (sb.st_mode & S_IFMT) 
						{
							case S_IFBLK:  printf("b");            
								       break;
							case S_IFCHR:  printf("c");        
								       break;
							case S_IFDIR:  printf("d");               
								       break;
							case S_IFIFO:  printf("p");               
								       break;
							case S_IFLNK:  printf("l");                 
								       break;
							case S_IFREG:  printf("-");            
								       break;
							case S_IFSOCK: printf("s");                  
								       break;
							default:       printf("u");                
								       break;
						}
						//Display the permissions for user, group and others.
						(sb.st_mode & S_IRUSR)? printf("r"):printf("-");
						(sb.st_mode & S_IWUSR)? printf("w"):printf("-");
						(sb.st_mode & S_IXUSR)? printf("x"):printf("-");
						(sb.st_mode & S_IRGRP)? printf("r"):printf("-");
						(sb.st_mode & S_IWGRP)? printf("w"):printf("-");
						(sb.st_mode & S_IXGRP)? printf("x"):printf("-");
						(sb.st_mode & S_IROTH)? printf("r"):printf("-");
						(sb.st_mode & S_IWOTH)? printf("w"):printf("-");
						(sb.st_mode & S_IXOTH)? printf("x"):printf("-");
	
						printf("%3ld ", (long) sb.st_nlink);//Display the number of links.
						grp = getgrgid(sb.st_gid);
						pwd = getpwuid(sb.st_uid);
						printf("%11s %11s ", pwd->pw_name,grp->gr_name);//Display the username and group name.
						printf("%4lld ",(long long) sb.st_size);//Display the size of the file.
						printf("%s ",file->d_name);//Display the file name.
						printf("%s",ctime(&sb.st_atime)); //Display the last access time of the file.
					}
				}
			}
		}	
	}
	else if(!strcmp(argv[1], "-li"))
	{
		for(i=2; i<argc; i++)
		{
			if(!access(argv[i],F_OK)) //Check if the directory specified by argv[i] exists.
			{
				directory=opendir(argv[i]); //If it exists, then open the directory.

				if(directory!=NULL)
				{
					while((file=readdir(directory))!=NULL) //Read each entry in the directory.
					{
	
						if (lstat(file->d_name, &sb) == -1) 
						{
							perror("stat");
						}
						
						 printf("%6ld ", (long) sb.st_ino);
						//Display the type of file.
						switch (sb.st_mode & S_IFMT) 
						{
							case S_IFBLK:  printf("b");            
								       break;
							case S_IFCHR:  printf("c");        
								       break;
							case S_IFDIR:  printf("d");               
								       break;
							case S_IFIFO:  printf("p");               
								       break;
							case S_IFLNK:  printf("l");                 
								       break;
							case S_IFREG:  printf("-");            
								       break;
							case S_IFSOCK: printf("s");                  
								       break;
							default:       printf("u");                
								       break;
						}
						//Display the permissions for user, group and others.
						(sb.st_mode & S_IRUSR)? printf("r"):printf("-");
						(sb.st_mode & S_IWUSR)? printf("w"):printf("-");
						(sb.st_mode & S_IXUSR)? printf("x"):printf("-");
						(sb.st_mode & S_IRGRP)? printf("r"):printf("-");
						(sb.st_mode & S_IWGRP)? printf("w"):printf("-");
						(sb.st_mode & S_IXGRP)? printf("x"):printf("-");
						(sb.st_mode & S_IROTH)? printf("r"):printf("-");
						(sb.st_mode & S_IWOTH)? printf("w"):printf("-");
						(sb.st_mode & S_IXOTH)? printf("x"):printf("-");
	
						printf("%3ld ", (long) sb.st_nlink);//Display the number of links.
						grp = getgrgid(sb.st_gid);
						pwd = getpwuid(sb.st_uid);
						printf("%11s %11s ", pwd->pw_name,grp->gr_name);//Display the username and group name.
						printf("%4lld ",(long long) sb.st_size);//Display the size of the file.
						printf("%s ",file->d_name);//Display the file name.
						printf("%s",ctime(&sb.st_atime)); //Display the last access time of the file.
					}
				}
			}
		}	
	}
	else
	{
		for(i=1;i<=argc-1;i++)
		{
			if(!access(argv[i],F_OK)) //Check if the directory specified by argv[i] exists.
			{
				directory=opendir(argv[i]); //If it exists, then open the directory.

				if(directory!=NULL)
				{
					while((file=readdir(directory))!=NULL) //Read each entry in the directory.
						printf("%-5s\t",file->d_name);
					printf("\n");
				}
				else
					perror("opendir"); //Display the error occurred while opening the directory.
			}
			else
					perror("access"); //Display an error if the directory does not exists.
		}

	}	
	return 0;
}


