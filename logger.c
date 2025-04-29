#include <stdio.h>
#include <time.h>
#include <string.h>

void log_action(const char *user, const char *action) {
    FILE *file = fopen("syscall.log", "a");
    if (!file) {
        perror("Failed to open syscall.log");
        return;
    }

    time_t now = time(NULL);
    char *timestamp = ctime(&now);
    timestamp[strcspn(timestamp, "\n")] = '\0';  // remove newline

    fprintf(file, "[%s] User: %s - %s\n", timestamp, user, action);
    fclose(file);
}
