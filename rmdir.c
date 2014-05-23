#include <unistd.h>

int myrmdir(int argc,char *argv[])
{
	if(argc!=2) //If the input is not of the form rmdir pathname, then display error message.
	{
		printf("Invalid number of arguments\n");
		return ;
	}

	if(!rmdir(argv[1])) //Remove the directory 
	{
		printf("%s was removed\n",argv[1]);
	}	
	else
	{
		perror("rmdir"); //Display the error occurred while removing the directory
	}
	
	return 0;
}
