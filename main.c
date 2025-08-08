#include <stdio.h>
#include <float.h>
#include <stdlib.h>

#define HISTORY_FILE "history.txt"

// Clear console function
void clearConsole() {
    system("cls");
}

// Show all history from file
void showHistory() {
    FILE *file = fopen(HISTORY_FILE, "r");
    if (!file) {
        printf("\nNo history found.\n");
        return;
    }

    char line[256];
    printf("\n\t--- Calculation History ---\n");
    while (fgets(line, sizeof(line), file)) {
        printf("\t%s", line);
    }
    printf("\t---------------------------\n");
    fclose(file);
}
// Save calculation to history
void saveToHistory(double a, char op, double b, double res) {
    FILE *file = fopen(HISTORY_FILE, "a");
    if (!file) {
        printf("Error saving history.\n");
        return;
    }
    fprintf(file, "%.2lf %c %.2lf = %.2lf\n", a, op, b, res);
    fclose(file);
}

// Clear history file
void clearHistory() {
    FILE *file = fopen(HISTORY_FILE, "w");
    if (!file) {
        printf("Error clearing history.\n");
        return;
    }
    fclose(file);
    printf("\nHistory cleared successfully.\n");
}

// Display menu with tab spaces
void showMenu() {
    printf("\n\t===== Simple Calculator =====\n");
    printf("\t1. C - Calculate\n");
    printf("\t2. H - View History\n");
    printf("\t3. X - Clear History\n");
    printf("\t4. L - Clear Console\n");
    printf("\t5. E - Exit\n");
    printf("\t=============================\n");
    printf("\tEnter your choice: ");
}

int main() {
    char choice;
    do {
        showMenu();
        scanf(" %c", &choice); // space before %c to avoid newline issues

        if (choice == 'C' || choice == 'c') {
            char op;
            double a, b, res;

            printf("\tEnter an operator (+, -, *, /): ");
            scanf(" %c", &op);

            printf("\tEnter two operands: ");
            scanf("%lf %lf", &a, &b);

            switch (op) {
                case '+':
                    res = a + b;
                    break;
                case '-':
                    res = a - b;
                    break;
                case '*':
                    res = a * b;
                    break;
                case '/':
                    if (b == 0) {
                        printf("Error! Division by zero.\n");
                        continue;
                    }
                    res = a / b;
                    break;
                default:
                    printf("Error! Incorrect Operator Value\n");
                    continue;
            }

            printf("\tResult: %.2lf\n", res);
            saveToHistory(a, op, b, res);

        } else if (choice == 'H' || choice == 'h') {
            showHistory();

        } else if (choice == 'X' || choice == 'x') {
            clearHistory();

        } else if (choice == 'L' || choice == 'l') {
            clearConsole();

        } else if (choice == 'E' || choice == 'e') {
            printf("\nExiting...\n");

        } else {
            printf("\nInvalid option! Try again.\n");
        }

    } while (choice != 'E' && choice != 'e');

    return 0;
}
