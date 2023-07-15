#include<stdio.h> 
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{


    int fd=0;
    char *Buffer=NULL;
    int Ret=0;
    char Fname[20];
    char Input[25];
    
    
 	printf("Enter the filename which you have to open:\n");
	scanf("%s", Fname);
        
        printf("Enter the string inputs needs to write in this file:\n");
        scanf("%s", Input);


if(argc !=2)

{
    printf("inSuffucient Arguments\n");
    return -1;


}

fd =open(Fname,O_WRONLY);
if(fd==-1)
{
    printf("unable to open file\n");
    return -1;
}

Input = atoi(argv[2]);
Buffer=(char *)malloc(Input);
Ret =write(fd, Buffer,atoi(argv[2]));

if(Ret==0)

{
    printf("Unable to write data to file\n");
    return -1;


}

printf("Data written in file :%s\n",Buffer);
return 0;

}
