#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

int mywc(int argc, char *argv[])
{
	FILE *file;
	int wordcount = 0, linecount = 0;
	char line[100];
	int count;	
	char *token;
	struct stat sb;

	if(argc != 2)
	{
		printf("Invalid number of arguments\n");
		return ;
	}

	file = fopen(argv[1], "r"); //open a file in read mode.
	if(file != NULL)
	{
		fseek(file, 0, SEEK_SET);
		while(fgets(line, sizeof(line), file)) //Extract a single line from the file.
		{
			linecount++; //Increment the linecount for every line.
			token = strtok(line, " "); //Extract the first token from the file seperated by space.
			if(token != NULL)
			{
				wordcount++; //Increment the wordcount for every the first token.
				while(token = strtok(NULL, " ")) //Extract all the tokens in the line till the end of the line is found. 
				{
					wordcount++; //Increment the wordcount for every new token.
				}
			}
			
		}
		if (stat(argv[1], &sb) == -1) //get file status.
		{
			perror("stat");
		}

		printf("%d\t%d\t%lld\t%s\n",linecount, wordcount, (long long) sb.st_size, argv[1]); //Display the number of lines, words, character and the file name.
	}
	else 
	{
		perror("fopen"); //Display the error occurred while trying to open the file.
	}
	
	return 0;
}
