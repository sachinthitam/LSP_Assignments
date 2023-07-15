//Q.write a program which accept directory name and file name from user and create file in that directory

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc(), char *argv[])
 {
    char dir_name[25];
    char file_name[24];

    printf("Enter directory name: ");
    fgets(dir_name, sizeof(dir_name), stdin);
    dir_name[strcspn(dir_name, "\n")] = '\0'; 

    printf("Enter file name: ");
    fgets(file_name, sizeof(file_name), stdin);
    file_name[strcspn(file_name, "\n")] = '\0';


    if(argc!=1)
     {
        printf("Insufficient arguments\n");
        return -1;
     }

    if (creat(argv[1], 0777) == -1) 
{
        printf("Not able to create directory.\n");
        exit(1);
    } else {
        printf("Directory created successfully.\n");
    }

    // Create the file
    char file_path[200];
    sprintf(file_path, "%s/%s", directory_name, file_name);
    FILE* file = fopen(file_path, "w");
    if (file == NULL) {
        printf("Error creating file.\n");
        exit(1);
    } 
       else {
        printf("File created successfully.\n");
        fclose(file);
    }

    return 0;
}