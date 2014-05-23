#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int mycat(int argc, char *argv[])
{
	int fd1, fd2;
	int count,i;
	char buffer[100];
	
	if(argc < 2)
	{
		printf("Invalid number of arguments\n");
		return ;
	}
	
	if(argc == 2)
	{
		if(!(access(argv[1],F_OK)))//Check for existence of the file.
		{
			fd1 = open(argv[1], O_RDONLY);//If the file exists, then open in read mode.
			if(fd1 > 0)
			{
				while((count = read(fd1, buffer, sizeof(buffer))) > 0)//Read data from the file into buffer.
				{
					write(1, buffer, count);//Write data from the buffer to standard output.
				}
				close(fd1); //Close file1
			}	
			else
			{
				perror("open");//Display the error occurred while trying to open the file.
			}
		}
		else
		{
			perror("access");//Display the corresponding error if the file does not exists.
		}

		printf("\n\n");
	}
	else if(!strcmp(argv[2],">"))
	{
		if(!access(argv[1],F_OK)) //Check for existence of file1.
		{
			fd1=open(argv[1],O_RDONLY); //If file1 exists, then open it in read mode
			if(fd1>0)
			{	
				fd2=open(argv[3],O_CREAT|O_WRONLY|O_TRUNC,0777); //If files to exists, then open in trunc mode otherwise create the file.
				if(fd2>0)
				{
					while((count=read(fd1,&buffer,sizeof(buffer)))>0) //Read data into buffer from file1 and write it to file2.
						write(fd2,&buffer,count);

					close(fd2); //Close file1
					close(fd1); //Close file2
				}
				else
					perror("open"); //Display the error occurred while opening file2.
			}
			else
				perror("open"); //Display the error occurred while opening file1.
		}
		else  
			perror("access"); //Display the error occurred while checking for existence of file1.
	}
	else if(!strcmp(argv[2],">>"))
	{
		if(!access(argv[1],F_OK)) //Check for existence of file1.
		{
			fd1=open(argv[1],O_RDONLY); //If file1 exists, then open it in read mode
			if(fd1>0)
			{	
				fd2=open(argv[3],O_CREAT|O_WRONLY|O_APPEND,0777); //If files to exists, then open in append mode otherwise create the file.
				if(fd2>0)
				{
					while((count=read(fd1,&buffer,sizeof(buffer)))>0) //Read data into buffer from file1 and write it to file2.
						write(fd2,&buffer,count);

					close(fd2); //Close file1
					close(fd1); //Close file2
				}
				else
					perror("open"); //Display the error occurred while opening file2.
			}
			else
				perror("open"); //Display the error occurred while opening file1.
		}
		else  
			perror("access"); //Display the error occurred while checking for existence of file1.
		
	
	}
	else if(!strcmp(argv[1],">"))
	{
		fd1 = open(argv[2],O_CREAT|O_WRONLY|O_TRUNC,0777);//If the file exists, then open in trunc mode otherwise create the file.
		if(fd1 > 0)
		{
			while((count=read(0,&buffer,sizeof(buffer)))>0) //Read data into buffer from standard input and write it to file2.
				write(fd1,&buffer,count);

					close(fd1); //Close file1
					
		}	 
	}
	else if(!strcmp(argv[1],">>"))
	{
		fd1 = open(argv[2],O_CREAT|O_WRONLY|O_APPEND,0777);//If the file exists, then open in append mode otherwise create the file.
		if(fd1 > 0)
		{
			while((count=read(0,&buffer,sizeof(buffer)))>0) //Read data into buffer from standard input and write it to file2.
				write(fd1,&buffer,count);

					close(fd1); //Close file1
					
		}
	}
	else
	{
		for(i=1;i<argc;i++) //Loop over all the argumemts to cat.
		{
			if(!(access(argv[i],F_OK)))//Check for existence of the file.
			{
				fd1 = open(argv[i], O_RDONLY);//If the file exists, then open in read mode.
				if(fd1 > 0)
				{
					while((count = read(fd1, buffer, sizeof(buffer))) > 0)//Read data from the file into buffer.
					{
						write(1, buffer, count);//Write data from the buffer to standard output.
					}
					close(fd1); //Close file1
				}	
				else
				{
					perror("open");//Display the error occurred while trying to open the file.
				}
			}
			else
			{
				perror("access");//Display the corresponding error if the file does not exists.
			}

			printf("\n");
		}

}
	return 0;
}
	
