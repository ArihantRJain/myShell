#include <fcntl.h>
#include <sys/types.h>
#include <utime.h>
#include <unistd.h>

int mytouch(int argc,char *argv[])
{
	int fd; //stores a pointer to an opened file.
	int i;	//Loop variable.
	
	if(argc<2) //If the input is of the form touch, then display error message.
	{
		printf("Invalid Number Of Arguments\n");	
		return ;
	}
	
	
	for(i=1;i<argc;i++) //Loop until all the arguments in argv are accessed.
	{	
		if(!access(argv[i],F_OK)) //Check if the file exists.
		{
			if( utime(argv[i],NULL)==0 ) //Change the modification and access times.
				printf("Access and Modification time for %s was changed\n",argv[i]);
			else
				perror("utime"); //Displays the error occurred while changing the modification and access times.
		}
		
		else
		{	
			fd=open(argv[i],O_CREAT|O_RDWR,0777); //If the file does not exist, then create the file.
			if( fd > 0 ) // If the file argv[i] was opened.
				printf("%s was created\n",argv[i]);
			
			else
				perror("open"); //Displays the error occurred during creation of the file.
		}
	}

	return 0;
}
