#include <sys/utsname.h>

int myuname()
{
	struct utsname buf;

	if(!uname(&buf))//Get name and information about current kernel.

		printf("%s\n",buf.sysname);//Display the system name.
	else
		perror("uname");//Display the error occurred while retrieving information about current kernel.

	return ;
}
