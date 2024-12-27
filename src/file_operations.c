#include "file_operations.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <libgen.h>
#include <sys/stat.h>

void copy_file(const char *source, const char *destination) {
    struct stat dest_stat;
    char new_destination[1024];

    // If the target path is a directory, include the filename
    if (stat(destination, &dest_stat) == 0 && S_ISDIR(dest_stat.st_mode)) {
        snprintf(new_destination, sizeof(new_destination), "%s/%s", destination, basename((char *)source));
        destination = new_destination;
    }

    int src_fd = open(source, O_RDONLY);
    if (src_fd < 0) {
        perror("Error opening source file");
        return;
    }

    int dest_fd = open(destination, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (dest_fd < 0) {
        perror("Error opening destination file");
        close(src_fd);
        return;
    }

    char buffer[1024];
    ssize_t bytes_read;
    while ((bytes_read = read(src_fd, buffer, sizeof(buffer))) > 0) {
        write(dest_fd, buffer, bytes_read);
    }

    close(src_fd);
    close(dest_fd);
    printf("File copied successfully to %s.\n", destination);
}

void remove_file(const char *path) {
    if (remove(path) == 0) {
        printf("File removed successfully.\n");
    } else {
        perror("Error removing file");
    }
}
