#include<unistd.h>
#include<sys/times.h>

int mytime(int argc,char *argv[])
{
	struct tms buf;
	float stime,realtime,utime;

	if(argc!=1) //checks for the number of arguments
	{
		printf("Invalid number of arguments\n"); 
		return ;
	}

	if(times(&buf)!=-1)
	{
		utime = buf.tms_utime + buf.tms_cutime; //calculates total user time
		stime = buf.tms_stime + buf.tms_cstime; //calculates total system time
		realtime =  utime + stime; //calculates real time
	

		printf("Real time =%lf\n",realtime); //prints real time
		printf("User time = %lf\n",utime); //prints user time
		printf("System time =%lf\n",stime); //prints system time
	}
	else
	{
		perror("times");
	}
	return 0;
}
