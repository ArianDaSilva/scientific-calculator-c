#include <stdbool.h>
#include <stdio.h>
void menu() {
    printf("\nCLI Calculator");
    printf("\n[ 1 ] Basic Arithmetics.");
    printf("\n[ 2 ] Advanced Options.");
    printf("\n[ 3 ] System Options.");
    printf("\n[ 4 ] Exit.");
    printf("\nPlease enter an option from the main menu:");
}
void basic() {
}
void advanced_option() {
}
void system_options() {
}
int main() {
    bool exit_calc = false;
    int input;
    while (!exit_calc) {
        printf("\n===========================\n");
        printf("WELCOME TO CLI CALCULATOR!");
        printf("\n===========================\n");
        printf("Press [ENTER] to access the main menu...");
        input = getchar();
        if (input == '\n') {
            menu();
            input = getchar();
            if (input == '1') {
                basic();
            } else if (input == '2') {
                advanced_option();
            } else if (input == '3') {
                system_options();
            } else if (input == '4') {
                exit_calc = true;
            } else {
                menu();
            }
        }
    }
    return 0;
}
