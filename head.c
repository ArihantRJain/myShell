#include <unistd.h>
#include <fcntl.h>
#include <math.h>

void display(int n, char *filename)
{
	FILE *file; 
	char buffer[100];
	int j;

	if(!access(filename,F_OK)) //Check for existence of the file.
	{
		if((file=fopen(filename,"r"))!=0) //If the file exists, then open in read mode.
		{
			printf("%s\n",filename); //Display the name of the file, so as to distinguish between contents of several files.
		 
			for(j=0;j<n;j++) //If no option is specified to the head command, print the first 10 lines of the file.
			{
				if(fgets(buffer,sizeof(buffer),file))//fgets extracts individual lines from the file and stores them into buffer
				{
					printf("%s",buffer); //Write the line onto the standard output.
				}
	
				else
				{
					perror("fgets"); //Display the error occurred reading data from the file.
					break;	
				}

			}
			fclose(file); //Close the file.
		}
		else
			perror("fopen"); //Display the error occurred while trying to open the file.

	}
	else
		perror("access"); //Display the error occurred while trying to check for existence of the file.

	printf("\n\n");	
	
}

int myhead(int argc, char *argv[])
{
	int i, n;
	

	if(argc<2)
	{
		printf("Invalid number of arguments\n");
		return ; 
	}
	
	n=(int) strtol(argv[1],(char **)0,10); //Conver the -n in argv[1](if specified) to the corresponding integer value.
	
	if(n) //If -n option is specified by the user.
	{
		for(i=2;i<argc;i++) //Loop over all the files in the argument list.
			display(abs(n),argv[i]); //Call display to display only n lines.
	}
	else //Otherwise loop over all the files and display 10 lines.
	{
		for(i=1;i<argc;i++)
			display(10,argv[i]);
	}	
	return 0;
}		
