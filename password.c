#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 10
#define MAX_USERNAME_LENGTH 20
#define MAX_PASSWORD_LENGTH 20

typedef struct {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    float bank_balance;
} User;

User users[MAX_USERS];
int num_users = 0;
void clearScreen();
void signUp();
void login();

int main() {
    int choice;

    do {
        clearScreen();
        printf("Password Manager\n");
        printf("1. Sign Up\n");
        printf("2. Login\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                signUp();
                break;
            case 2:
                login();
                break;
            case 3:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    } while (choice != 3);

    return 0;
}
void clearScreen() {
    system("cls");//clearscreen is needed because it makes the console look clean
}

void signUp() {
    if (num_users == MAX_USERS) {
        printf("Maximum number of users reached!\n");//to limit the num of users that can access
        return;
    }

    clearScreen();
    printf("Sign Up\n");

    printf("Enter username: ");
    scanf("%s", users[num_users].username);

    printf("Enter password: ");
    scanf("%s", users[num_users].password);

    users[num_users].bank_balance = 0.0;

    num_users++;
    printf("User signed up successfully!\n");
    printf("Press any key to continue...");
    getchar();
    getchar(); //getting new user input
}
void login() {
    clearScreen();
    printf("Login\n");

    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    int i;
    for (i = 0; i < num_users; i++) {
        if (strcmp(username, users[i].username) == 0 && strcmp(password, users[i].password) == 0) {
            printf("Login successful!\n");
            printf("Your bank balance: $%.2f\n", users[i].bank_balance);
            printf("Press any key to continue...");
            getchar(); 
            getchar(); // getting the new input of user
            return;
        }
    }

    printf("Invalid username or password!\n");
    printf("Press any key to continue...");
    getchar(); 
    getchar(); //Getting new user input
}
