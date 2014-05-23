#include<sys/time.h>
#include<unistd.h>

int mydate()
{
	long now, time();
	char *ctime();

	time (&now); //The value of time in seconds since the Epoch is returned.
	printf("%s", ctime (&now)); //It  converts the calendar time t into a null-terminated string of the form "Wed Jun 30 21:49:08 1993\n"


	return 0;
}

