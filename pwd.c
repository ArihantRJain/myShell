#include <unistd.h>

int mypwd()
{
	char buffer[100];
	
	if(getcwd(buffer,sizeof(buffer)))//Get current working directory and store it in buffer.
	{
		printf("%s\n",buffer);
	}
	else
	{
		perror("getcwd");//Display the error occurred with getcwd.
	}
	
	return 0;
}
