#include <stdio.h>
#include <string.h>
#define max 100
char infix[max], postfix[max], stack[max];

int precedence(char op) {
    switch (op) {
        case '+':
            return 1;
        case '-':
            return 1;
        case '*':
            return 2;
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}


int main(){
    printf("Enter the infix expression:"); scanf("%c", &infix);
    int i=0, j=0, s=0;
    for (i; infix[i] != "\0"; i++){
        char ch = infix[i];
        if (isnalnum(ch)){
            postfix[j++] = ch;
        }
        else if(ch == "("){
            stack[s++] = "(";
        }
        else if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^'){
            while (!isempty(postfix) || !isempty(stack) || precedence(ch) < precedence(infix[i-1])){}
            stack[s++] = ch;
        }
    }
}