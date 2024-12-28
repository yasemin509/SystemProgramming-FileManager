#include "directory_ops.h"  // Include custom header file for directory operations
#include <stdio.h>          // Include standard input/output library
#include <dirent.h>         // Include library for directory operations
#include <sys/stat.h>       // Include library for file status operations
#include <errno.h>          // Include library for error number definitions
#include <string.h>         // Include library for string operations

void list_directory(const char *path) {
    DIR *dir = opendir(path);
    if (!dir) {
        printf("Error opening directory: %s\n", strerror(errno));
        return;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        printf("%s\n", entry->d_name);
    }
    closedir(dir);
}

