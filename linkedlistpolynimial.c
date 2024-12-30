#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Node{
    int coff;
    int exp;
    struct Node *Next;
};
struct Node *temp, *Head = NULL, *p;

void create(int n){
    for (int i=1; i<=n; i++){
        temp = (struct Node*) malloc(sizeof(struct Node));
        printf("Enter value for coefficient and exponent for term %d: ", i);
        scanf("%d %d", &temp->coff, &temp->exp);
        temp->Next = NULL;
        if (Head == NULL){
            Head = temp;
            return;
        }
        p = Head;
        while(p->Next != NULL){
            p = p->Next;
        }
        p->Next = temp;
    }
}

void display(){
    p = Head;
    printf("\n Polynomial = %dx^%d", p->coff, p->exp);
    p = p->Next;
    while(p != NULL){
        printf(" + %dx^%d", p->coff, p->exp);
        p = p->Next;
    }
}

void solve(){
    p = Head;
    int x;
    printf("\nEnter value for x: "); scanf("%d", &x);
    float res = 0;
    while (p != NULL){
        res += (p->coff * pow(x, p->exp));
        p = p->Next;
    }
    printf("The result is : %f", res);
}

int main(){
    int n;
    printf("\nEnter the number of terms : "); scanf("%d", &n);
    create(n);
    display();
    solve();
    return 0;
}