//Q. Write a program which accept directory name from user and print all files present from that directory.

#include <stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<sys/stat.h>
#include<dirent.h>

int main(int argc,char *argv[])
{


    char dirname[20];
   
    printf("Enter the directory name: ");
    scanf("%s", dirname);


     if(argc!=1)
     {
        printf("Insufficien arguments\n");
        return -1;
     }

    DIR *dir = opendir(dirname);

    if(dir==NULL)
    { 
        printf("Unable to open directory\n");
        return -1;
    }

    if (dir)
     {
        struct dirent *entry;

        while ((entry = readdir(dir)) != NULL)
 {
            printf("This files are present inside directory: %s\n", entry->d_name);
        }

        closedir(dir);

    return 0;
}

