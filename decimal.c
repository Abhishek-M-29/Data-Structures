#include <stdio.h>
#define MAX 32 
int stack[MAX];
int top = -1;

void push(int n) {
    if (top == MAX - 1) {
        printf("Stack overflow\n");
    } else {
        stack[++top] = n;
    }
}

int pop() {
    if (top == -1) {
        printf("Stack underflow\n");
        return -1; 
    } else {
        return stack[top--];
    }
}

void display() {
    if (top == -1) {
        printf("Stack is empty. No binary digits to display.\n");
        return;
    }
    printf("Binary: ");
    while (top != -1) {
        printf("%d", pop());
    }
    printf("\n");
}

void dectobin(int n) {
    while (n > 0) {
        push(n % 2);  
        n = n / 2;    
    }
    printf("Number converted to binary and stored in stack.\n");
}

int main() {
    int choice, n;
    printf("\nProgram of Anusha Govind - 1AY23CS032");
    while (1) {
        
        printf("\nMenu:\n");
        printf("1. Push Remainder\n");
        printf("2. Pop and Display Binary\n");
        printf("3. Convert Number to Binary and Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a decimal number to push remainders: ");
                scanf("%d", &n);
                while (n > 0) {
                    push(n % 2);  
                    n = n / 2;    
                }
                printf("Remainders pushed onto the stack.\n");
                break;

            case 2:
                printf("Displaying binary number: ");
                display(); 
                break;

            case 3:
                printf("Enter a decimal number to convert: ");
                scanf("%d", &n);
                dectobin(n);
                display();   
                break;

            case 4:
                printf("Exiting program.\n");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}