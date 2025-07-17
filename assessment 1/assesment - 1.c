#include <stdio.h>
#include <stdlib.h>

//  Function prototypes – business logic separated into functions
void display(int a, int b, char op, double result);
int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
double divide(int a, int b);

int main(void) {
    int choice;
    int num1, num2;
    
    do {
        //  Display menu
        printf("\n===== MENU =====\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("Enter your choice : ");
        if (scanf("%d", &choice) != 1) {
            // handle non-integer input
            while (getchar() != '\n');
            printf(" Invalid input. Please enter a number 1‑5.\n");
            continue;
        }
        
        if (choice < 1 || choice > 5) {
            printf(" Invalid choice. \n");
            continue;
        }
        
        //  Valid operation – ask for operands
        printf("Enter first Number: ");
        scanf("%d", &num1);
        printf("Enter second Number: ");
        scanf("%d", &num2);
        
        // Perform chosen operation
        switch (choice) {
            case 1:
                // result = a+b;
                // printf("result = %.2f\n", result);
                display(num1, num2, '+', add(num1, num2));
                break;
            case 2:
                display(num1, num2, '-', subtract(num1, num2));
                break;
            case 3:
                display(num1, num2, '*', multiply(num1, num2));
                break;
            case 4:
                if (num2 == 0) {
                    printf(" Cannot divide by zero.\n");
                } else {
                    display(num1, num2, '/', divide(num1, num2));
                }
                break;
        }
    } while (1);

    return 0;
}

//  Business logic: each arithmetic operation
int add(int a, int b)           { return a + b; }
int subtract(int a, int b)      { return a - b; }
int multiply(int a, int b)      { return a * b; }
double divide(int a, int b)     { return (double)a / b; }

//  Display function for clean, single‑point output
void display(int a, int b, char op, double result) {
    printf("%d %c %d = %.2f\n", a, op, b, result);
    // printf("Addition =%d",);
}
