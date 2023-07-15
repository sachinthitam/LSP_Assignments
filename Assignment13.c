//Q. Write a program which accept file name and mode from user and open that file in specified mode.

#include<stdio.h>
#include<fcntl.h>
#include<string.h>

int main(int argc, char *argv[])
{
   int fd=0;
   int mode[20];
    char Fname[20];
	
	printf("Enter the file name which you have to open:\n);
	scanf("%s",Fname);
	
	printf("Enter the mode in which you have to open this file :\n);
	scanf("%s",mode);
	
   printf("Please provide inputs on terminal like: name_of_excutable name_of_file mode_of_open: \n");
   
   if(argc!=1)
   {
   
   printf("you have provided invalid arguments\n");
   return -1;
   }
   
   if(strcpy(Fname,"Read")==0)
   {
   
    mode = O_RDONLY;
	}
	 
   else if(strcmp(Fname, "write")==0)
   {
     mode =O_WRONLY;
   
   }
   
	fd= open(Fname, mode);
	if(fd==-1)
	{
	  printf("Not able to open file\n");
	  return -1;
	  }
	  
	 else
	 {
	    printf("File is opened successfully:%d\n", fd)
		return 0;
		
		}
		}
	  
	  
   