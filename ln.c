#include <unistd.h>

int myln(int argc,char *argv[])
{
	if(argc<3 || argc>5) //If the input is not of the form ln file1 file2 or ln -s file1 file2, then display error message.
	{
		printf("Invalid Number Of Arguments\n");
		return 0;
	}

	if(strcmp(argv[1],"-s")==0) //Check if a soft link has to be created.
	{
		if(!symlink(argv[2],argv[3])) //Create a soft link.  
			printf("Soft link created\n");
		else
			perror("symlink"); //Display the error occurred while creating a soft link.

	}
	else if(argc==3)
	{
		if(!link(argv[1],argv[2])) //Create a hardlink
			printf("Hard link created\n");
		else
			perror("link"); //Display the error occurred while creating a hard link.
	}

	else
		printf("Syntax Error\n"); //Return a syntax error any other option apart from -s.

	return 0;
}
