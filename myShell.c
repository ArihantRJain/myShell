#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functionHeaders.h"

int main()
{
	char getCommand[100]; 
	char *tokens[50];
	int i;
	
	while(1) //Run the loop until the user wants to exit the Mini Shell.
 	{
		i=0; 
		printf("myShell> ");

		gets(getCommand);

		tokens[i++]=strtok(getCommand," "); //Extract the first token from getcommand.
			
		while((tokens[i++] = strtok(NULL," "))); //Extract all the arguments to the command and store them in tokens.
						
		
		if(!strcmp(tokens[0],"exit")) //The user wishes to exit the Mini Shell.
		{
			exit(0); //Terminate the Mini Shell.	
		}

		else if(!strcmp(tokens[0],"cd")) //The user wishes to execute the change directory(cd) commmand.
		{
			mycd(i-1,tokens); //Call mycd function with parameters as number of argumemts and the argument list.
		}

		else if(!strcmp(tokens[0],"cp")) //The user wishes to execute the copy(cp) command..
		{
			mycp(i-1,tokens); //Call mycp function with number of argumemts and the argument list as parameters.
		}

		else if(!strcmp(tokens[0],"ln")) //The user wishes to execute the ln commmand.
		{
			myln(i-1,tokens); //Call myln function with number of argumemts and the argument list as parameters.
		}

		else if(!strcmp(tokens[0],"mv")) //The user wishes to execute the my command.
		{
			mymv(i-1,tokens); //Call mymv function with number of arguments and the argument list as paramaters.
		}

		else if(!strcmp(tokens[0],"head")) //The user wishes to execute the head command.
		{
			myhead(i-1,tokens); //Call myhead function with number of arguments and the argument list as parameters.
		}

		else if(!strcmp(tokens[0], "touch")) //The user wishes to execute the touch command.
		{
			mytouch(i-1,tokens); //Call mytouch function with number of arguments and the argument list as parameters.
		}

		else if(!strcmp(tokens[0], "mkdir")) //The user wishes to execute the mkdir command.
		{
			mymkdir(i-1,tokens); //Call mymkdir function with number of arguments and the argument list as parameters.
		}

		else if(!strcmp(tokens[0], "rmdir")) //The user wishes to execute the rmdir command.
		{
			myrmdir(i-1,tokens); //Call myrmdir function with number of arguments and the argument list as parameters.
		}

		else if(!strcmp(tokens[0], "uname")) //The user wishes to execute the uname command.
		{
			myuname(); //Call myuname function.
		}
		
		else if(!strcmp(tokens[0], "file")) //The user wishes to execute the file command.
		{
			myfile(i-1,tokens); //Call myfile function with number of arguments and the argument list as parameters.
		}

		else if(!strcmp(tokens[0], "tail")) //The user wishes to execute the tail command.
		{
			mytail(i-1, tokens); //Call mytail function with number of arguments and the argument list as parameters.
		}

		else if(!strcmp(tokens[0], "ls")) //The user wishes to execute the ls command.
		{
			myls(i-1, tokens); //Call myls function with number of arguments and the argument list as parameters.
		}

		else if(!strcmp(tokens[0], "cat")) //The user wishes to execute the cat command.
		{
			mycat(i-1, tokens); //Call mycat function with number of arguments and the argument list as parameters.
		}

		else if(!strcmp(tokens[0], "pwd")) //The user wishes to execute the pwd command.
		{
			mypwd(); //Call mypwd function.
		}

		else if(!strcmp(tokens[0], "rm")) //The user wishes to execute the rm command.
		{
			myrm(i-1, tokens); //Call the myrm function with the number of aruguments and the argument list as parameters.
		}

		else if(!strcmp(tokens[0], "bc")) //The user wishes to execute the bc command.
		{
			mybc(); //Call the mybc function.
		}	
		
		else if(!strcmp(tokens[0], "grep")) //The user wishes to execute the grep command.
		{
			mygrep(i-1, tokens); //Call the mygrep function with the number of arguments and the argument list as parameters.
		}

		else if(!strcmp(tokens[0], "date")) //The user wishes to execute the date command.
		{
			mydate(); //Call the mydate function.
		}
	
		else if(!strcmp(tokens[0], "time")) //The user wishes to execute the time command.
		{
			mytime(i-1,tokens); //Call the mytime function with the number of arguments and the argument list as parameters.
		}
		
		else if(!strcmp(tokens[0], "wc")) //The user wishes to execute the wc command.
		{
			mywc(i-1, tokens); //Call the mywc function with the number of arguments and the argument list as parameters.
		}
		
		else if(!strcmp(tokens[0], "clear")) //The user wishes to execute the clear command.
		{
			system("clear");
		}
	}
	return 0;
}
