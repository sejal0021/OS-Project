// auth.c
#include <stdio.h>
#include <string.h>

int authenticate_user(const char *username, const char *password) {
    FILE *file = fopen("users.txt", "r");
    if (!file) {
        perror("Error opening users file");
        return 0;
    }

    char u[50], p[50];
    while (fscanf(file, "%s %s", u, p) != EOF) {
        if (strcmp(u, username) == 0 && strcmp(p, password) == 0) {
            fclose(file);
            return 1;
        }
    }

    fclose(file);
    return 0;
}

