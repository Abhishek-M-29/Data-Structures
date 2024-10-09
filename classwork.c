/*
#include<stdio.h>
#include<stdlib.h>
int main()
{
    int *ptr, num, i;
    printf("Enter the number of elements:"); scanf("%d", &num);
    ptr = (int *) malloc(num*sizeof(int));
    if (ptr == NULL){
        printf("Memory is not allocated\n");
    }
    else{
        printf("Memory allocated\n");
    }
    for (i=0; i<num; i++){
        scanf("%d", &ptr[i]);
    }
    printf("The elements in the memory are:");
    for(i=0; i<num; i++){
        printf(" %d ", ptr[i]);
    }
    free(ptr);
    return 0;
}
*/

#include <stdio.h>
#include <math.h>

void main(){
    int row = 0;
    printf("Enter the number of rows :"); scanf("%d", &row);
    if (row % 2 == 0){
        int poc = 1;
    }
    else{
        int poc = 2;
    }
    for (int i=0; i<row; i++){
        
    }
}