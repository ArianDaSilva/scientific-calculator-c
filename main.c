#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
// Declaration of the functions
// void menu(void);
void menu()
{
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
    printf("\nCLI Calculator");
    printf("\n[ 1 ] Basic Arithmetics.");
    printf("\n[ 2 ] Advanced Options.");
    printf("\n[ 3 ] System Options.");
    printf("\n[ 4 ] Exit.");
    printf("\nPlease enter an option from the main menu:");
}

// Basic arithmetic operations menu
void basicArithmetic(void)
{
    char choice = 'y';
    int option;
    int x, y;
    do
    {
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif
        printf("\n%-22s %-16s %s\n", "Name", "Example", "Description");
        printf("%-22s %-16s %s\n", "[ 1 ] Addition", "x + y", "Adds together two values");
        printf("%-22s %-16s %s\n", "[ 2 ] Subtraction", "x - y", "Subtracts one value from another");
        printf("%-22s %-16s %s\n", "[ 3 ] Multiplication", "x * y", "Multiplies two values");
        printf("%-22s %-16s %s\n", "[ 4 ] Division", "x / y", "Divides one value by another");
        printf("[ 5 ] Return to the main menu..\n");
        printf("[ 6 ] Exit the program.\n");
        printf("Please select an option: ");
        scanf("%d", &option);
        if (option >= 1 && option <= 4)
        {
            printf("\nEnter first number: ");
            scanf("%d", &x);
            printf("Enter second number: ");
            scanf("%d", &y);
        }
        switch (option)
        {
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
            if (y != 0)
            {
                printf("%d / %d = %d\n", x, y, x / y);
            }
            else
            {
                printf("Error: Cannot divide by zero.\n");
            }
            break;

        case 5:
            return;

        case 6:
            printf("Exiting the program...\n");
            exit(0);

        default:
            printf("Error: Invalid option.\n");
            break;
        }
        if (option >= 1 && option <= 4)
        {
            printf("\nDo you want to perform another operation? (y/n): ");
            scanf(" %c", &choice);
        }

    } while (choice == 'y' || choice == 'Y');

    printf("Exiting the program...\n");
    exit(0);
}

//Advanced arithmetic operations menu
void advanced_option()
{
    int option;
    int x, y;
    bool exit_loop=false;
    while(!exit_loop)
    {
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif
        printf("\n%-22s %-16s %s\n", "Name", "Example", "Description");
        printf("%-22s %-16s %s\n", "[ 1 ] Exponentiation", "x^y", "Raises a base number to the power of an exponent");
        printf("%-22s %-18s %s\n", "[ 2 ] Square Root", "√x", "Finds the number equals to the input when multiplied by itself");
        printf("%-22s %-16s %s\n", "[ 3 ] Mudulus", "x % y", "Returns the remainder left over after integer division");
        printf("%-22s %-16s %s\n", "[ 4 ] Perecentage", "x%", "Calculate a specified portion out of a total of 100");
        printf("[ 5 ] Return to the main menu..\n");
        printf("[ 6 ] Exit the program.\n");
        printf("Please select an option: ");
        scanf("%d", &option);
        if(option==5) return;
        if(option==6)
        {
            printf("Exiting the program...\n");
            exit(0);
        }
        if(option == 1 || option == 3)
        {
            printf("\nEnter first number: ");
            scanf("%d", &x);
            printf("Enter second number: ");
            scanf("%d", &y);
        }
        switch (option)
        {
            case 1:
                printf("\n--- Result ---\n");
                printf("%d^%d = %d\n", x, y, pow(x,y));//2 decimales 
                break;
            case 2:
                printf("\nEnter a number: ");
                scanf("%d", &x);
                printf("\n--- Result ---\n");
                printf("√%d = %.2f\n",x,sqrt((double)x));
                break;
            case 3:
                printf("\n--- Result ---\n");
                printf("%d %% %d = %d\n",x,y,x%y);
                break;
            case 4:
                printf("\nEnter a number: ");
                scanf("%d", &x);
                printf("\n--- Result ---\n");
                printf("%d%% = %.2f\n",x,(double)x/100);
                break;
            default:
                printf("Error: Invalid option.\n");
                break;
        }
        printf("\nDo you want to perform another operation? (y/n): ");
        char choice;
        scanf(" %c", &choice);
        exit_loop = (choice == 'n' || choice == 'N');
    }
}
void system_options()
{
}
int main()
{
    bool exit_calc = false;
    int input;
    printf("\n===========================\n");
    printf("WELCOME TO CLI CALCULATOR!");
    printf("\n===========================\n");
    printf("Press [ENTER] to access the main menu...");
    while (!exit_calc)
    {
        input = getchar();
        if (input == '\n')
        {
            menu();
            input = getchar();
            if (input == '1')
            {
                basicArithmetic();
            }
            else if (input == '2')
            {
                advanced_option();
            }
            else if (input == '3')
            {
                system_options();
            }
            else if (input == '4')
            {
                exit_calc = true;
            }
            else
            {
                menu();
            }
        }
    }
    return 0;
}
