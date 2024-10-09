#include<stdio.h>
#include<conio.h>
#include<string.h>
int top = -1, max = 25, stack[25];

push(int val){
    if (top >= max){
        printf("Overflow!");
    }
    else{
        top++;
        stack[top] == val;
    }
}

int pop(){
    int x;
    x = stack[top];
    top--;
    return x;
}

void main(){
    char *postfix;
    printf("Enter the postfix expression:"); scanf("%c", &postfix);
    int i, len, top=-1;
    len = strlen(postfix);
    for (i=0; i<len; i++){
        if (postfix[i] == '+' || postfix[i] == "-" || postfix[i] == "*" || postfix[i] == "/" ||
         postfix[i] == "//" || postfix[i] == "\%"){
            
        }
    }
}