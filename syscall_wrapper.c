#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include "logger.h"

void secure_open(const char *filename, const char *user) {
    if (strcmp(filename, "/etc/passwd") == 0 && strcmp(user, "admin") != 0) {
        printf("Access denied for user: %s\n", user);
        log_action(user, "DENIED open /etc/passwd");
        return;
    }

    int fd = open(filename, O_RDONLY);
    if (fd < 0) {
        perror("open failed");
        log_action(user, "FAILED open");
    } else {
        printf("File opened successfully!\n");
        log_action(user, "SUCCESS open");
        close(fd);
    }
}

void secure_fork(const char *user) {
    if (strcmp(user, "admin") != 0) {
        printf("Fork not allowed for non-admins\n");
        log_action(user, "DENIED fork");
        return;
    }

    pid_t pid = fork();
    if (pid == 0) {
        printf("Child process created\n");
        log_action(user, "SUCCESS fork");
    } else if (pid > 0) {
        printf("Parent continues\n");
    } else {
        perror("fork failed");
        log_action(user, "FAILED fork");
    }
}

