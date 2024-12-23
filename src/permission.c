#include "permission.h"
#include <sys/stat.h>
#include <stdio.h>
#include <errno.h>

void change_permissions(const char *path, int permissions) {
    if (chmod(path, permissions) == 0) {
        printf("Permissions changed successfully.\n");
    } else {
        perror("Error changing permissions");
    }
}

