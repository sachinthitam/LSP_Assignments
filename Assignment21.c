#include<stdio.h> 
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>

#define BLOCKSIZE 1024

int main(int argc, char *argv[])
{


    int fd=0;
    int Ret=0;
    char Buffer[BLOCKSIZE];
     char Fname[20];

printf("Enter the file name which you have to read: %s\n");
	scanf("%s",Fname);


if(argc !=1)

{
    printf("inSuffucient Arguments\n");
    return -1;

}

//read data on terminal

fd =open(Fname,O_RDONLY);
if(fd==-1)
{
    printf("unable to open file\n");
    return -1;
}

while((Ret= read(fd,Buffer,sizeof(Buffer)))!=0)
{
    write(1,Buffer,Ret);
}

close(fd);

return 0;

}
