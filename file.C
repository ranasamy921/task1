#include <stdio.h>
#include <string.h>

struct User {
    char username[50];
    char password[50];
};

void registerUser() {
    struct User newUser;
    FILE *file = fopen("users.txt", "a"); 

    if (file == NULL) {
        perror("Error opening file");
        // exit(1);
    }

    printf("Enter a username: ");
    scanf("%s", newUser.username);
    printf("Enter a password: ");
    scanf("%s", newUser.password);

    fprintf(file, "%s %s\n", newUser.username, newUser.password);
    fclose(file);
    printf("Registration successful!\n");
}

int checkUser(char *username, char *password) {
    struct User user;
    FILE *file = fopen("users.txt", "r");

    if (file == NULL) {
        perror("Error opening file");
        // exit(1);
    }

    while (fscanf(file, "%s %s", user.username, user.password) != EOF) {
        if (strcmp(username, user.username) == 0 && strcmp(password, user.password) == 0) {
            fclose(file);
            return 1;
        }
    }

    fclose(file);
    return 0;
}

int main() {
    int choice;
    char username[50];
    char password[50];

    while (1) {
        printf("1. Register\n2. Login\n3. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                registerUser();
                break;

            case 2:
                printf("Enter username: ");
                scanf("%s", username);
                printf("Enter password: ");
                scanf("%s", password);

                if (checkUser(username, password)) {
                    printf("Login successful!\n");
                } else {
                    printf("Login failed. Invalid username or password.\n");
                }
                break;

            case 3:
                printf("Exiting program.\n");
                // exit(0);

            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    }

    return 0;
}
