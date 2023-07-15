Q. program which accept directory name from user and delete all such files whose size is greater than 100 bytes

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>

void delete_large_files(const char* directory_name) {
    DIR* directory = opendir(directory_name);
    if (directory == NULL) {
        printf("Error opening directory.\n");
        return;
    }

    struct dirent* entry;
    char file_path[512];

    while ((entry = readdir(directory)) != NULL) {

        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue;

        sprintf(file_path, "%s/%s", directory_name, entry->d_name);

        struct stat file_info;

        if (stat(file_path, &file_info) == -1)
 {

            printf("Error getting file information.\n");
            continue;
        }

        if (S_ISREG(file_info.st_mode) && file_info.st_size > 100) {
            if (remove(file_path) == 0) {

                printf("Deleted file: %s\n", file_path);
            } else {
                printf("Error deleting file: %s\n", file_path);
            }
        }
    }

    closedir(directory);
}

int main(int argc(), *argv[])
 {
    char directory_name[256];

    printf("Enter directory name: ");
    fgets(directory_name, sizeof(directory_name), stdin);
    directory_name[strcspn(directory_name, "\n")] = '\0'; // Remove trailing newline character

    if(argc!=1)
     {
        printf("Insufficient arguments\n");
        return -1;
     }

    delete_large_files(directory_name);

    return 0;
}
