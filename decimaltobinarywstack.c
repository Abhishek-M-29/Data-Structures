#include <stdio.h>
#include <stdlib.h>

int top = -1;
int capacity = 32;
int *stack;

void push(int value) {
    if (top == capacity - 1) {
        printf("Stack Overflow!\n");
        return;
    }
    stack[++top] = value;
}

int pop() {
    if (top == -1) {
        printf("Stack Underflow!\n");
        return -1;
    }
    return stack[top--];
}

int main() {
    stack = (int *)malloc(capacity * sizeof(int));
    if (stack == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    int decimal;
    printf("Enter a decimal number: ");
    scanf("%d", &decimal);
    while (decimal > 0) {
        push(decimal % 2);
        decimal /= 2;
    }

    printf("Binary Representation: ");
    while (top != -1) {
        printf("%d", pop());
    }
    printf("\n");
    free(stack);
    return 0;
}
