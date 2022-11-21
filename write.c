#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<stdio.h>

int main()
{
printf("\nName: Swagat Parida\nUID:21BCS3510\n");
int f;
char buff[70];
f = open("fd_test.txt", O_RDWR);
//printf("\nWriting in terminal...");
read(f,buff,20);
//write(1,buff,70);
printf("\nWriting in file...");
write(f,buff,70);
close(f);
return 0;
}

