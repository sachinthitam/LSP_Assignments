//Q. Write a program which accept file name and number of bytes from user and read that number of bytes from the file

#include<stdio.h> 
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{


    int fd=0;
    char *Buffer=NULL;
    int Ret=0;
     int Size=0;
	  char Fname[20];
     
     
  	printf("Enter the file name which you have to read: %s\n");
	scanf("%s",Fname);

       
        printf("Enter the number of byte need to read from file: %d\n");
        scanf("%d",Size);
        
        

if(argc !=3)

{
    printf("inSuffucient Arguments\n");
    return -1;


}

fd =open(argv[1],O_RDONLY);
if(fd==-1)
{
    printf("unable to open file\n");
    return -1;
}

Size = atoi(argv[2]);

Buffer=(char *)malloc(Size);

Ret =read(fd, Buffer,Size);
if(Ret==0)

{
    printf("Unable to read data from file\n");
    return -1;


}

printf("Read data from file for specific number of bytes:\n");
write(1,Buffer,Ret);

return 0;

}
