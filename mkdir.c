#include <sys/stat.h>
#include <sys/types.h>

int mymkdir(int argc,char *argv[])
{

	if(argc!=2) //If the input is not of the form mkdir pathname, then display error message.
	{
		printf("Invalid number of arguments\n");
		return ;
	}

	if(!mkdir(argv[1],0775)) //Create a directory with the name specified in the argument.
		printf("%s was created\n",argv[1]);
	else
		perror("mkdir");//Display the error occurred while trying to create the directory. 

	return 0;
}
