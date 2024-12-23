#include "directory_ops.h"
#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <errno.h>
#include <string.h>

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

