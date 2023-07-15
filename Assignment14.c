//Q.Write a program which accept file name from user and print all information about that file

#include<stdio.h> 
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<sys/stat.h>


int main(int argc,char *argv[])
{

    struct stat sobj;

    if(argc!=2)
 {
        printf("Insufficien arguments\n");
        return -1;

}

stat(argv[1],&sobj);

printf("File details as below: %ld\n",sobj);

return 0;
}
	