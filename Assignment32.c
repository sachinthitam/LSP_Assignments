//Q. Write a program which accept directory name and file name from user and check wheather this file is present in that directory or not

#include <stdio.h>
#include <dirent.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char dirname[25];
    char filename[30];


    printf("Enter the directory name: ");
    scanf("%s", dirname);

    printf("Enter the file name: ");
    scanf("%s", filename);

  if(argc!=1)

      {
        printf("Insufficient arguments\n");
         return -1;
       }

    DIR *dir = opendir(dirname);


    if (dir) {
        struct dirent *entry;
        int found = 0;

  
        while ((entry = readdir(dir)) != NULL) {
            if (strcmp(entry->d_name, filename) == 0) {
                found = 1;
                break;
            }
        }

        if (found) {
            printf("The file '%s' is present in the directory '%s'.\n", filename, dirname);
        } else {
            printf("The file '%s' is not found in the directory '%s'.\n", filename, dirname);
        }

    
        closedir(dir);

    return 0;
}
