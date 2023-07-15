//Q. Write a program which accept file name and mode from user and open that file in specified mode.

#include<stdio.h>
#include<fcntl.h>
#include<string.h>

int main(int argc, char *argv[])
{
   int fd=0;
   int mode=0;
   
   printf("Please provide inputs on terminal like: name_of_excutable name_of_file mode_of_open: \n");
   
   if(argc!=3)
   {
   
   printf("you have provided invalid arguments\n");
   return -1;
   }
   
   if(strcpy(argv[2], "Read")==0)
   {
      mode= 0_RDONLY;
	  
	  }
	fd= open(argv[1], mode);
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
	  
	  
   