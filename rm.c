#include <unistd.h>

int myrm(int argc, char *argv[])
{
	if(argc == 1) //If the input is not of the form rm filename1, then display error message.
	{
		printf("Invalid number of arguments\n");
		return ;
	}

	if(!access(argv[1],F_OK))//Check for existence of the file.
	{
		if(unlink(argv[1]))//Unlink the file.
		{
			perror("unlink");//Displaying the error occurred while trying to unlink the file.
		}
	}
	else
	{
		perror("access");//Display the error occurred while trying to access the file.
	}
	
	return 0;
}
