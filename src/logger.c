#include "logger.h"
#include <stdio.h>
#include <time.h>
#include <string.h>

void log_operation(const char *operation, const char *path, int result) {
    FILE *logfile = fopen("log.txt", "a");
    if (!logfile) {
        perror("Error opening log file");
        return;
    }

    time_t now = time(NULL);
    fprintf(logfile, "[%s] Operation: %s, Path: %s, Result: %d\n", 
            ctime(&now), operation, path, result);
    fclose(logfile);
}

