#include<stdio.h>
#include<fcntl.h>
int main(int argc, char *argv[])
{

 char Fname[20];
 int fd=0;
 printf("Enter the file name which you have to open:\n);
 scanf("%s",Fname);
 
 fd= open(Fname,O_RDONLY);
 if(fd==-1)
 {
 
  printf("Not able to open file\n");
  return -1;
  }

   else{
   
   
   printf("File opened successfully using fd %d\n", fd);
   } 
   return 0;
   
   }
   
 