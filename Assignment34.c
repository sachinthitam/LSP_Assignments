//Q.write a program which accept directory name from user and delete all empty files from that directory

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>

void delete_empty_files(const char* directory) {
    DIR* dir = opendir(directory);

    if (dir == NULL) {
        perror("Error opening directory");
        return;
    }

    struct dirent* entry;
    char file_path[PATH_MAX];

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_REG) {  // Check if it's a regular file
            snprintf(file_path, sizeof(file_path), "%s/%s", directory, entry->d_name);

            struct stat st;
            if (stat(file_path, &st) == 0) {
                if (st.st_size == 0) {  // Check if the file is empty
                    if (unlink(file_path) == -1) {
                        perror("Error deleting file");
                    } else {
                        printf("Deleted file: %s\n", file_path);
                    }
                }
            } else {
                perror("Error getting file information");
            }
        }
    }

    closedir(dir);
    printf("Empty files deleted successfully!\n");
}

int main() {
    char directory[PATH_MAX];

    printf("Enter the directory name: ");
    scanf("%s", directory);

    delete_empty_files(directory);

    return 0;
}
