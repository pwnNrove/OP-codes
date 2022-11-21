#include<unistd.h>
#include<stdio.h>
#include<sys/types.h>

void forkex()
{
	if (fork()==0)
	printf("\nHello from child");
	else
	printf("\nHello from parent");
}
int main()
{
forkex();
pid_t parent_id, child_id;

child_id = getppid();
parent_id = getpid();

printf("\nThe process id is: %d",parent_id);
printf("\nThe p_process id is %d",child_id);

return 0;
}
