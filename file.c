#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>

int myfile(int argc, char *argv[])
{
	struct stat sb;

	if (argc != 2) 
	{
		printf("Invalid number of arguments\n");
		return ;
	}

	if (lstat(argv[1], &sb) == -1) //get file status
	{
		perror("stat"); //Display the error occurred while extracting file status.
		return ;
	}

	printf("File type: ");

	switch (sb.st_mode & S_IFMT) //bit mask for the file type bit fields
	{
		case S_IFBLK:  printf("block device\n"); //check if it is a block device file.           
			       break;
		case S_IFCHR:  printf("character device\n"); //check if it is a character device file.       
			       break;
		case S_IFDIR:  printf("directory\n"); //check if it is a directory.              
			       break;
		case S_IFIFO:  printf("FIFO/pipe\n"); //check if it is a fifo file.              
			       break;
		case S_IFLNK:  printf("symlink\n");  //check if it is symbolic link file.               
			       break;
		case S_IFREG:  printf("regular file\n"); // check if it is a regular file.       
			       break;
		case S_IFSOCK: printf("socket\n"); //check if it is a socket.                 
			       break;
		default:       printf("unknown?\n");                
			       break;
	}
	return 0;
}


