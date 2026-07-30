#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char choice = 'y';
    int option;
    int x, y;
    do {
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif
        printf("Enter first number: ");
        scanf("%d", &x);
        printf("Enter second number: ");
        scanf("%d", &y);
        printf("\n%-22s %-16s %s\n", "Name", "Example", "Description");
        printf("%-22s %-16s %s\n", "[ 1 ] Addition", "x + y", "Adds together two values");
        printf("%-22s %-16s %s\n", "[ 2 ] Subtraction", "x - y", "Subtracts one value from another");
        printf("%-22s %-16s %s\n", "[ 3 ] Multiplication", "x * y", "Multiplies two values");
        printf("%-22s %-16s %s\n", "[ 4 ] Division", "x / y", "Divides one value by another");
        printf("[ 5 ] Clear screen.\n");
        printf("[ 6 ] Exit the program.\n");
        printf("Please select an option: ");
        scanf("%d", &option);
        switch (option) {
            case 1: 
                printf("\n--- Result ---\n");
                printf("%d + %d = %d\n", x, y, x + y);
                break;

            case 2: 
                printf("\n--- Result ---\n");
                printf("%d - %d = %d\n", x, y, x - y);
                break;

            case 3:
                printf("\n--- Result ---\n");
                printf("%d * %d = %d\n", x, y, x * y);
                break;

            case 4:
                printf("\n--- Result ---\n");
                if (y != 0) {
                    printf("%d / %d = %d\n", x, y, x / y);
                } else {
                    printf("Error: Cannot divide by zero.\n");
                }
                break;
                
            case 5:
                printf("Returning to main menu.\n");
                break;

            case 6:
                printf("Exiting the program...\n");
                return 0; // Sale del programa directamente

            default:
                printf("Invalid option!\n");
                break;
        }
        printf("\nDo you want to perform another operation? (y/n): ");
        scanf(" %c", &choice);

    } while (choice == 'y' || choice == 'Y');

    printf("Exiting the program...\n");
    return 0;
}