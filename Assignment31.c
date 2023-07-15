//Q. Write a program which accept two file names from user and copy the contents of an existing file into newly created file.

#include<stdio.h>
#include<fcntl.h>
#include<unistl.h>
#include<string.h>

#define BLOCKSIZE 1024

int main(int argc, char *argv[])
{
     
     int fdSource=0;
     int fdDest=0;
    
       char Fname1[20]
       char Fname2[20]

       printf("Enter souce file name:\n")
       scanf("%s", Fname1);

	printf("Enter destination file name:\n")
        scanf("%s", Fname2);

     char Buffer[BLOCKSIZE]={'\0'};
      
     int Ret=0;

      if(argc!=1)

      {
        printf("Insufficient arguments\n");
         return -1;
       }


     fdSource= open(Fname1,O_RDONLY);
      if(fdSource==-1)
      {

        printf("Unable to open this file\n");
      	  return -1;
      }

     fdDest= creat(Fname2,0777);

       if(fdDest ==-1)
         {
          printf("unable to create destination file\n");
           close(fdSource);
           return -1;
           }


while((Ret =read(fdSource,Buffer,sizeof(Buffer)))!=0)
{
      write(fdDest,Buffer,Ret);
      memset(Buffer,0,sizeof(Buffer));
      
}
      close(fdSource);
      close(fdDest);
 
    return 0;

}

        