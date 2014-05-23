#include <unistd.h>
#include <fcntl.h>

int mycp(int argc,char *argv[])
{
	int fd1,fd2;
	char *buffer;
	int count;

	if(argc!=3) // If the input is not of the form cp filename1 filename2, then display an error message.
	{
		printf("Invalid number of arguments\n");
		return ;
	}

	if(!access(argv[1],F_OK)) //Check for existence of file1.
	{
		fd1=open(argv[1],O_RDONLY); //If file1 exists, then open it in read mode
		if(fd1 > 0)
		{	
			fd2=open(argv[2],O_CREAT|O_WRONLY,0777); //If files to exists, then open in write mode otherwise create the file.
			if(fd2 > 0)
			{
				while((count=read(fd1,&buffer,sizeof(buffer)))>0) //Read data into buffer from file1 and write it to file2.
					write(fd2,&buffer,count);

				close(fd2); //Close file1
				close(fd1); //Close file2
			}
			else
			{
				perror("open"); //Display the error occurred while opening file2.
			}
		}
		else
		{
			perror("open"); //Display the error occurred while opening file1.
		}
	}
	else
	{  
		perror("access"); //Display the error occurred while checking for existence of file1.
	}
	
	return 0;
}
