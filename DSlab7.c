// Develop a program in C for the following stack application.
// a> Evaluation of siffix expression with single digit operand and operators: +,-,*,/,%
// b> Solving the Tower of Hanoi problem with n disks

#include<stdio.h>
#define MAX 10
int stack[MAX];
int top=-1;


void push(int val){
        if(top>=MAX-1){
            printf("\nStack Overflow");
        }
        else{
            top++;
            stack[top]=val;
        }
    }

int pop(){
    int x;
    if(top<=-1){
        printf("Stack Underflow");
        return -1;
    }
    else{
        x=stack[top];
        top--;
        return x;
    }
}


void suffixevaluation(){

    char exp[] = "123*=";
    int i,val1,val2;
    for(i=0; exp[i] != '\0' ;i++){
        printf("%c",exp[i]);
        if(exp[i]=='+'||exp[i]=='-'||exp[i]=='*'||exp[i]=='/'){
            val1=pop();
            val2=pop();
            if(exp[i]=='+'){
                push(val2+val1);
            }
            if(exp[i]=='-'){
                push(val2-val1);
            }
            if(exp[i]=='*'){
                push(val2*val1);
            }
            if(exp[i]=='/'){
                push(val2/val1);
            }
        }
        else{
            push(exp[i]-'0');
        }
    }
    printf("\n Answer=%d",stack[top]);
}

void towerOfHanoi(int n, char A, char B, char C) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", A, C);
        return;
    }
    towerOfHanoi(n - 1, A, C, B);
    //printf("Move disk %d from %c to %c\n", n, A, C);
    towerOfHanoi(1, A, B, C);
    towerOfHanoi(n - 1, B, A, C);
}

int main() {
    int choice;
    printf("\nAbhishek M- 1AY23CS006's program");
    printf("\n1.Suffix evaluation\n2. Solve Tower of Hanoi");
    printf("\nENter the choice: "); scanf("%d", &choice);
    if (choice == 1){
        suffixevaluation();
    }
    else if(choice == 2){
        int n;
        printf("Enter the number of disks: ");
        scanf("%d", &n);
        towerOfHanoi(n, 'S', 'A', 'D');
    }
    else{
        printf("\nInvalid Choice");
    }
    return 0;
}
