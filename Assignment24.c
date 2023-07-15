//Q. Write a program which accept directory name from user and print all files present and its types from that directory.

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
        struct stat file_stat;

        while ((entry = readdir(dir)) != NULL) {
        
            stat(entry->d_name, &file_stat);
            char *type = (S_ISDIR(file_stat.st_mode)) ? "Directory" : "File";

            printf("This files and its types inside directory: %s (%s)\n", entry->d_name, type);

}

        closedir(dir);

    return 0;
}

