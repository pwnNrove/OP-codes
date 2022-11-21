#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

void forkex()
{

if (fork()==0)
	printf("\nHello from child");
else
	printf("\nHello from parent");
	wait(NULL);//NULL denotes that it will not return the reason of termination
	prrintf("\nChild process terminated");
}
int main()
{
	forkex();
	return 0;
}
