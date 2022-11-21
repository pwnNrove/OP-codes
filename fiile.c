#include<stdio.h>
#include<fcntl.h>
#include<errno.h>
extern int errno;
int main()
{
int fd = open("foo.txt", O_RDONLY | O_CREAT);
printf("fd = %d", fd);

if (fd == -1)
{
//print which type of error have in a code
printf("\nError no. is %d\n", errno);
perror("Program");
}
return 0;
}
//0  -->  Read
//1 -->  Write
//2 --> Error
// 0 1 and 2 are reserved
// 3 means opening a file descriptor
