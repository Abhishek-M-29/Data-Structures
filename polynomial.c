#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct poly{
    int n;
    struct term *t;
};
struct term{
    int coff;
    int expo;
};

int main(){
    struct poly p;
    printf("Enter number of terms :"); scanf("%d", &p.n);
    p.t = (struct term*) malloc(p.n* sizeof(struct term));
    for (int i=0; i<p.n; i++){
        printf("Enter the Coefficient and Exponent : "); scanf("%d %d", &p.t[i].coff, &p.t[i].expo);
    }
    for (int i=0; i<p.n; i++){
        printf(" %d x**%d ", p.t[i].coff, p.t[i].expo);
        if ( i != p.n-1){
            printf(" +");
        }
    }
    int val = 0, x;
    printf("\nEnter the value for x:"); scanf("%d", &x);
    for (int i=0; i<p.n; i++){
        val += (p.t[i].coff * pow(x, p.t[i].expo));
    }
    printf("The result is : %d", &val);
}