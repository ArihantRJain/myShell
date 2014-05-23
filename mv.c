#include <unistd.h>

int mymv(int argc,char *argv[])
{
	if(argc!=3) //If the input is not of the form mv filename1 filename2, then display error message.
	{
		printf("Invalid number of arguments\n");	
		return ;
	}

	if(access(argv[2],F_OK)==0) //Check for existence of the second file
	{
		printf("File %s exists",argv[2]); //If the file exists, then return the control to the main function.
		return ;	
	}
	else
	{
		if( !link(argv[1],argv[2]) ) //If the file doesn't exist, then link file1 and file2 and remove file1 to emulate the mv command.
		{	
			if( unlink(argv[1]) )
			{
				perror("unlink"); //Display the error occurred while trying to unlink the file.
			}
		}		
		else
		{
			perror("link"); //Display the error occurred while linking file1 and file2.
		}
	}

	return 0;
}				
