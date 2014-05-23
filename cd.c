#include <unistd.h>

int mycd(int argc, char *argv[])
{
	char cwd[100];

	if(argc!=2) //If the path of the directory is not specified, display a error message.
	{
		printf("Invalid number of arguments\n");
		return ; 
	}

	if(!chdir(argv[1])) //chdir successful, if zero is returned.
	{
		printf("Current working directory changed to ");
		if(getcwd(cwd,sizeof(cwd)) != NULL) // Stores the Current working directory in cwd if NULL is not returned.
		{
			puts(cwd);  //Display the current working directory.
		}
		else
		{
			perror("getcwd"); //Display the error occurred with getcwd.
		}
	}
	else
	{
		perror("chdir");  //Display the occur that occurred while trying to change the current working directory.
	}

	return 0;
}
