#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <limits.h>
#include <string.h>

int main() {
    char dirname[PATH_MAX];

    printf("Enter the directory name: ");

    fgets(dirname, sizeof(dirname), stdin);

    dirname[strcspn(dirname, "\n")] = '\0'; 


    DIR *dir = opendir(dirname);


    if (dir) {
        struct dirent *entry;
        struct stat file_stat;
        off_t max_size = 0;
        char largest_file[PATH_MAX];

        while ((entry = readdir(dir)) != NULL) {

            char filepath[PATH_MAX];
            snprintf(filepath, sizeof(filepath), "%s/%s", dirname, entry->d_name);

            if (stat(filepath, &file_stat) == 0 && S_ISREG(file_stat.st_mode) && file_stat.st_size > max_size) {
                max_size = file_stat.st_size;

                strncpy(largest_file, entry->d_name, sizeof(largest_file));
                largest_file[sizeof(largest_file) - 1] = '\0';
            }
        }

        if (max_size > 0) {
            printf("File with largest size: %s\n", largest_file);
        } else {
            printf("No files found in the directory.\n");
        }

        closedir(dir);
    } else {
        printf("Could not open the directory.\n");
        return 1;
    }

    return 0;
}
