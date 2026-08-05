#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int angle_unit = 1;//1-> degree 2 -> radians
int decimal_precision = 2;

// Declaration of the functions
void menu(void);
void basicArithmetic(void);
void advanced_option(void);
void system_options(void);
void clear_screen(void);

void clear_screen(void)
{
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void menu(void)
{
    int option;
    do {
    clear_screen();
    printf("\nCLI Calculator");
    printf("\n[ 1 ] Basic Arithmetics.");
    printf("\n[ 2 ] Advanced Options.");
    printf("\n[ 3 ] System Options.");
    printf("\n[ 4 ] Exit.");
    printf("\nPlease enter an option from the main menu:");
    scanf("%d", &option);
    switch (option)
    {
    case 1:
        basicArithmetic();
        break;
    case 2:
        advanced_option();
        break;
    case 3:
        system_options();
        break;
    case 4:
        exit(0);
    default:
        printf("Error: Invalid option.\n");
        break;
        }
    } while (option != 4);
}

// Basic arithmetic operations menu
void basicArithmetic(void)
{
    char choice = 'y';
    int option;
    double x, y;
    do
    {
        clear_screen();
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
            scanf("%lf", &x);
            printf("Enter second number: ");
            scanf("%lf", &y);
        }
        switch (option)
        {
        case 1:
            printf("\n--- Result ---\n");
            printf("%.*f + %.*f = %.*f\n", decimal_precision, x, decimal_precision, y, decimal_precision, x + y);
            break;

        case 2:
            printf("\n--- Result ---\n");
            printf("%.*f - %.*f = %.*f\n", decimal_precision, x, decimal_precision, y, decimal_precision, x - y);
            break;

        case 3:
            printf("\n--- Result ---\n");
            printf("%.*f * %.*f = %.*f\n", decimal_precision, x, decimal_precision, y, decimal_precision, x * y);
            break;

        case 4:
            printf("\n--- Result ---\n");
            if (y != 0)
            {
                printf("%.*f / %.*f = %.*f\n", decimal_precision, x, decimal_precision, y, decimal_precision, x / y);
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

    printf("Returning to main menu...\n");
    return;
}

//Advanced arithmetic operations menu
void advanced_option(void)
{
    int option;
    double x, y;
    bool exit_loop=false;
    char* angle_unit_name= (angle_unit==1) ? "degrees" : "radians";
    double result;
    while(!exit_loop)
    {
        clear_screen();
        printf("\n%-22s %-16s %s\n", "Name", "Example", "Description");
        printf("%-22s %-16s %s\n", "[ 1 ] Exponentiation", "x^y", "Raises a base number to the power of an exponent");
        printf("%-22s %-18s %s\n", "[ 2 ] Square Root", "√x", "Finds the number equals to the input when multiplied by itself");
        printf("%-22s %-16s %s\n", "[ 3 ] Modulus", "x % y", "Returns the remainder left over after integer division");
        printf("%-22s %-16s %s\n", "[ 4 ] Percentage", "x%", "Calculate a specified portion out of a total of 100");
        printf("%-22s %-16s %s %s\n", "[ 5 ] Cosine", "cos(x)", "Calculate the cosine of an angle in",angle_unit_name);
        printf("%-22s %-16s %s %s\n", "[ 6 ] Sine", "sin(x)", "Calculate the sine of an angle in",angle_unit_name);
        printf("%-22s %-16s %s %s\n", "[ 7 ] Tangent", "sin(x)", "Calculate the tangent of an angle in",angle_unit_name);
        printf("%-22s %-16s %s %s\n", "[ 8 ] Arc Sine", "asin(x)", "Calculate the inverse sine, result in",angle_unit_name);
        printf("%-22s %-16s %s %s\n", "[ 9 ] Arc Cosine", "acos(x)", "Calculate the inverse cosine, result in",angle_unit_name);
        printf("%-22s %-16s %s %s\n", "[ 10 ] Arc Tangent", "atan(x)", "Calculate the inverse tangent, result in ",angle_unit_name);
        printf("[ 11 ] Return to the main menu..\n");
        printf("[ 12 ] Exit the program.\n");
        printf("Please select an option: ");
        scanf("%d", &option);
        if(option == 1 || option == 3)
        {
            printf("\nEnter first number: ");
            scanf("%lf", &x);
            printf("Enter second number: ");
            scanf("%lf", &y);
        }
        switch (option)
        {
            case 1:
                printf("\n--- Result ---\n");
               printf("%.*f^%.*f = %.*f\n", decimal_precision, x, decimal_precision, y, decimal_precision, pow(x, y));
                break;
            case 2:
                printf("\nEnter a number: ");
                scanf("%lf", &x);
                printf("\n--- Result ---\n");
                if (x >= 0) {
                    printf("√%.*f = %.*f\n", decimal_precision, x, decimal_precision, sqrt((double)x));
                }else{
                    printf("Error: Cannot calculate the square root of a negative number.\n");
                }
                break;
            case 3:
                printf("\n--- Result ---\n");
                if (y != 0) {
                    printf("%.*f %% %.*f = %.*f\n", decimal_precision, x, decimal_precision, y, decimal_precision, fmod(x, y));
                }else{
                    printf("Error: Cannot perform modulus by zero.\n");
                }
                break;
            case 4:
                printf("\nEnter a number: ");
                scanf("%lf", &x);
                printf("\n--- Result ---\n");
                printf("%.*f%% = %.*f\n", decimal_precision, x, decimal_precision, (double)x/100);
                break;
            case 5:
                printf("\nEnter a number: ");
                scanf("%lf", &x);
                printf("\n--- Result ---\n");
                result=(angle_unit==1)?x*M_PI/180:x;
                printf("cos(%.*f) = %.*f\n", decimal_precision, x, decimal_precision, cos(result));
                break;
            case 6:
                printf("\nEnter a number: ");
                scanf("%lf", &x);
                printf("\n--- Result ---\n");
                result=(angle_unit==1)?x*M_PI/180:x;
                printf("sin(%.*f) = %.*f\n", decimal_precision, x, decimal_precision, sin(result));
                break;
            case 7:
                printf("\nEnter a number: ");
                scanf("%lf", &x);
                printf("\n--- Result ---\n");
                result=(angle_unit==1)?x*M_PI/180:x;
                printf("tan(%.*f) = %.*f\n", decimal_precision, x, decimal_precision, tan(result));
                break;
            case 8:
                printf("\nEnter a number: ");
                scanf("%lf", &x);
                printf("\n--- Result ---\n");
                if(x > 1 || x < -1 ){
                    printf("Domain error");
                    break;
                }
                result=acos(x);//Devuelve siempre radianes
                result=(angle_unit==1)?result*180/M_PI:result;
                printf("acos(%.*f) = %.*f\n", decimal_precision, x, decimal_precision, result);
                break;
            case 9:
                printf("\nEnter a number: ");
                scanf("%lf", &x);
                printf("\n--- Result ---\n");
                if(x > 1 || x < -1 ){
                    printf("Domain error");
                    break;
                }
                result=asin(x);
                result=(angle_unit==1)?result*180/M_PI:result;
                printf("asin(%.*f) = %.*f\n", decimal_precision, x, decimal_precision, result);
                break;
            case 10:
                printf("\nEnter a number: ");
                scanf("%lf", &x);
                printf("\n--- Result ---\n");
                if(x > 1 || x < -1 ){
                    printf("Domain error");
                    break;
                }
                result=atan(x);
                result=(angle_unit==1)?result*180/M_PI:result;
                printf("atan(%.*f) = %.*f\n", decimal_precision, x, decimal_precision, result);
                break;
            case 11:
                return;
            case 12:
                printf("Exiting the program...\n");
                exit(0);
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

void system_options(void) {
    int option1, option2, precision;
    clear_screen();
    printf("\n=== System Options ===\n");
    printf("[ 1 ] Set Angle Unit (Degrees/Radians)\n");
    printf("[ 2 ] Set Decimal Precision\n");
    printf("[ 3 ] Return to Main Menu\n");
    printf("Please select an option: ");
    scanf("%d", &option1);
    switch (option1) {
        case 1:
            printf("Angle Units:\n");
            printf("[ 1 ] Degrees\n");
            printf("[ 2 ] Radians\n");
            printf("[ 3 ] Return to Main Menu\n");
            printf("Please select an option: ");
            scanf("%d", &option2);
            if (option2 == 1 || option2 == 2) {
                angle_unit = option2;
            }else{
                printf("Error: Invalid selection\n");
            }
            break;
        case 2:
            printf("Decimal Precision:\n");
            printf("Enter the number of decimal places (0 to 6):");
            scanf("%d", &precision);
            if (precision >= 0 && precision <= 6) {
                decimal_precision = precision;
                printf("Decimal precision updated to: %d\n", decimal_precision);
            } else {
                printf("Error: Precision must be between 0 and 6.\n");
            }
            break;
        case 3:
            return;
        default:
            printf("Error: Invalid option.\n");
            break;
    }
    printf("\nPress [ENTER] to return...");
    getchar();
    getchar();
}

int main(void)
{
    printf("\n===========================\n");
    printf("WELCOME TO CLI CALCULATOR!");
    printf("\n===========================\n");
    printf("Press [ENTER] to access the main menu...");
    getchar(); // Wait for user to press Enter
    menu();
    return 0;
}
