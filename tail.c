#include <unistd.h>
#include <fcntl.h>

void printLine(FILE *file, int startline)
{
	int fd;
	fd= fileno(file);
	int count;
	char buffer[100];
	lseek(fd,(startline + 1),SEEK_SET); //Set the file pointer to the nth line from the end of the file.
	while((count= read(fd,buffer,sizeof(buffer))) > 0) //Display all the lines till the end of the file.
	{
		write(1, buffer, count);
	}
}

void scanFile(int n, FILE *filename)
{
	int fposition;
	int index;
	int end;
	long countlines= 0;
	char cbyte;
	
	fseek(filename,0,SEEK_END); //Set the pointer to the end of the file.
	fposition= ftell(filename); //obtains the current value  of  the  file  position indicator for the file.
	index= fposition;
	end= fposition;
	for(index; index >= 0; index --) //Loop backward from the end of the file.
	{
		cbyte= fgetc(filename);
		if (cbyte == '\n' && (end - index) > 1) //If end of line is found 
		{
			countlines ++; //Increment the number of lines.
			if(countlines == n) //If countlines is equal to n, then break.
			{
				break;
			}
		}
		fposition--;
		fseek(filename,fposition,SEEK_SET); 
	}
	printLine(filename, fposition); //Print lines from the file
	fclose(filename); //Close the file.
}

int mytail(int argc, char *argv[])
{
	int n, i;
	FILE *file;

	if(argc<2)
	{
		printf("Invalid number of arguments\n");
		return ;
	}
	
	n=(int) strtol(argv[1],(char **)0,10); //Conver the -n in argv[1](if specified) to the corresponding integer value.
	
	if(n)//If -n option is specified by the user.
	{	
		for(i=2;i<argc;i++)//Loop over all the files in the argument list.
		{
			file= fopen(argv[i], "r"); //Open the file.
			if(file == NULL)
			{	
	  			perror("fopen");
			}
			scanFile(abs(n),file); //Call scanFile to display only n lines.
			printf("\n");
		}
	}
	else //Otherwise loop over all the files and display 10 lines.
	{
		for(i=1;i<argc;i++)
		{
			file= fopen(argv[i], "r"); //Open the file.
			if(file == NULL)
			{	
	  			perror("fopen");
			}
			scanFile(10,file);
			printf("\n");
		}
	}	
	return 0;

}
