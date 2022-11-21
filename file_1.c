#include<stdio.h>
#include<sys/stat.h>
#include<fcntl.h>

int main()
{
printf("Name: Akshit Gupta\nUID: 21BCS3509\n");
char buffer[80];
char msg[10] = "os exp 3";
int fd = open("foo.txt", O_RDONLY | O_CREAT);
printf("fd = %d",fd);
if (fd!=-1)
{
printf("Opened file with read access");
write (fd, msg, sizeof(msg));
lseek(fd, 0, SEEK_SET);
read(fd, buffer, sizeof(msg));
printf("\n%s", buffer);
close(fd);
}
return 0;
}
