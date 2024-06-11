#include <stdio.h>
#include <string.h>

void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);//i am using this because usually there is input buffer when we try to execute on console
}

void seats(char new_row[]) {
    printf("\nEnter the seat number you want to sit in (A to F) and (1 to 5): ");
    scanf("%s", new_row);
    clear_input_buffer();
}

int movie(int user) {
    int tickets, audi, audi1 = 30, audi2 = 40, flag;
    char movie[50], row[50], seat[10][50];
    
    for (int i = 0; i < user; i++) {
        printf("USER %d\n\n", i + 1);
        printf("Enter the Movie name: ");
        scanf("%s", movie);
        clear_input_buffer();
        printf("Enter the number of tickets: ");
        scanf("%d", &tickets);
        clear_input_buffer();
        printf("Enter the audi(1/2): ");
        scanf("%d", &audi);
        clear_input_buffer();
        
        if (audi == 1)
            audi = audi1;
        else
            audi = audi2;

        do {
            flag = 0; // Reset flag for each user
            printf("Enter the seat number you want to sit in (A to F) and (1 to 5): ");
            scanf("%s", row);
            clear_input_buffer();

            // Check if the seat is already taken
            for (int j = 0; j < i; j++) {
                if (strcmp(seat[j], row) == 0) {
                    printf("Seat is already taken.\n");
                    flag = 1;
                    break;
                }
            }
        } while (flag == 1);

        // Store the seat if not already taken
        strcpy(seat[i], row);
    }

    return 0;
}

int main() {
    int user;
    printf("Enter the number of users: ");
    scanf("%d", &user);
    clear_input_buffer();

    movie(user);
    printf("Successfully booked tickets!!!\n");
    return 0;
}

