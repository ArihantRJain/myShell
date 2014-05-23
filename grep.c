#include <unistd.h>
#include <sys/types.h> 
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>

void match_pattern(char *argv[])
{
	int fd,r,j=0;
	char temp,line[100];

	if((fd=open(argv[2],O_RDONLY)) != -1) //Open the file in read mode.
	{
		while((r=read(fd,&temp,sizeof(char)))!= 0) //Read each character from the file.
		{
			if(temp!='\n') //Store all the characters read from the file into line until the end of the line is found.
			{
				line[j]=temp;
				j++;
			}
			else
			{
				if(strstr(line,argv[1])!=NULL) //Search for a substring(represented by argv[1]) in a string(represented by line).
				    printf("%s\n",line);
				memset(line,0,sizeof(line)); //Fill memory with a constant character byte.
				j=0;
			}

		}
		close(fd); //close file.
	}
}

int mygrep(int argc,char *argv[])
{
	struct stat stt;

	if(argc==3)
	{
		if(stat(argv[2],&stt)==0) //Get file status.
		{
		    match_pattern(argv); 
		}
		else 
		{
		    perror("stat"); //Display the error occurred while trying to extract the file status.
		}
	}
	
	return 0;
}
