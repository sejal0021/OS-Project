// main.c
#include <stdio.h>
#include <string.h>

extern int authenticate_user(const char *, const char *);
extern void secure_open(const char *, const char *);
extern void secure_fork(const char *);
extern void log_action(const char *, const char *);

int main() {
    char username[50], password[50];
    printf("Username: ");
    scanf("%s", username);
    printf("Password: ");
    scanf("%s", password);

    if (!authenticate_user(username, password)) {
        printf("Authentication failed!\n");
        return 1;
    }

    printf("Welcome, %s!\n", username);

    int choice;
    while (1) {
        printf("\n1. Open File\n2. Fork Process\n3. Exit\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: {
                char filename[100];
                printf("Enter filename to open: ");
                scanf("%s", filename);
                secure_open(filename, username);
                break;
            }
            case 2:
                secure_fork(username);
                break;
            case 3:
                return 0;
        }
    }
}
