#include <stdbool.h>
#include <stdio.h>
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
            exit_calc = true;
        }
    }
    return 0;
}
