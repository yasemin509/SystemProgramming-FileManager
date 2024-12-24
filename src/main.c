#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "directory_ops.h"
#include "file_operations.h"
#include "permission.h"
#include "logger.h"

int main() {
    char command[256];
    char arg1[128], arg2[128];
    printf("Terminal Based File Manager\n");
    printf("Available commands: slist, scopy, sremove, schmod\n");

    while (1) {
        printf("\n> ");
        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\n")] = 0;

        if (strncmp(command, "slist", 5) == 0) {
            int result = 0;
            sscanf(command, "slist %s", arg1);
            list_directory(arg1);
            log_operation("slist", arg1, result);
        } else if (strncmp(command, "scopy", 5) == 0) {
            int result = 0;
            sscanf(command, "scopy %s %s", arg1, arg2);
            copy_file(arg1, arg2);
            log_operation("scopy", arg1, result);
        } else if (strncmp(command, "sremove", 7) == 0) {
            int result = 0;
            sscanf(command, "sremove %s", arg1);
            remove_file(arg1);
            log_operation("sremove", arg1, result);
        } else if (strncmp(command, "schmod", 6) == 0) {
            int result = 0;
            int permissions;
            sscanf(command, "schmod %s %o", arg1, &permissions);
            change_permissions(arg1, permissions);
            log_operation("schmod", arg1, result);
        } else if (strncmp(command, "exit", 4) == 0) {
            log_operation("exit", "-", 0); // Çıkışı logla
            break;
        } else {
            printf("Invalid command.\n");
            log_operation("invalid_command", command, -1); // Geçersiz komutu logla
        }
    }
    return 0;
}

