#include <stdio.h>
#include <float.h>
#include <stdlib.h>
#include <math.h> // power function er jonno lagbe

#define HISTORY_FILE "history.txt"

// ei function console clear kore
void clearConsole() {
    system("cls");
}

// ei function file theke history show kore
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

// ei function history file e calculation save kore
void saveToHistory(double num1, char op, double num2, double res) {
    FILE *file = fopen(HISTORY_FILE, "a");
    if (!file) {
        printf("Error saving history.\n");
        return;
    }
    fprintf(file, "%.2lf %c %.2lf = %.2lf\n", num1, op, num2, res);
    fclose(file);
}

// ei function history file clear kore
void clearHistory() {
    FILE *file = fopen(HISTORY_FILE, "w");
    if (!file) {
        printf("Error clearing history.\n");
        return;
    }
    fclose(file);
    printf("\nHistory cleared successfully.\n");
}

// ei function menu show kore
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
        scanf(" %c", &choice); // space rakha hoyeche jate newline problem na hoy

        if (choice == 'C' || choice == 'c') {
            char op;
            double num1, num2, res;

            printf("\tEnter an operator (+, -, *, /, ^): ");
            scanf(" %c", &op);

            printf("\tEnter two operands: ");
            scanf("%lf %lf", &num1, &num2);

            // operator check kore calculation kore
            switch (op) {
                case '+':
                    res = num1 + num2;
                    break;
                case '-':
                    res = num1 - num2;
                    break;
                case '*':
                    res = num1 * num2;
                    break;
                case '/':
                    if (num2 == 0) {
                        printf("Error! Division by zero.\n");
                        continue;
                    }
                    res = num1 / num2;
                    break;
                case '^': // power calculation
                    res = pow(num1, num2);
                    break;
                default:
                    printf("Error! Incorrect Operator Value\n");
                    continue;
            }

            printf("\tResult: %.2lf\n", res);
            saveToHistory(num1, op, num2, res);

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
