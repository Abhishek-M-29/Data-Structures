#include<stdio.h>

void main(){
    int r, c;
    printf("Enter number of rows :"); scanf("%d", &r);
    printf("\nEnter the number of columns :"); scanf("%d", &c);
    int matrix[r][c];
    int count = 0;
    for (int i=0; i<r; i++){
        for (int j=0; j<c; j++){
            printf("Enter element for row %d and column %d :", i+1, j+1); scanf("%d", &matrix[i][j]);
            if (matrix[i][j] == 0){
                count += 1;
            }
        }
        printf("\n");
    }
    if (count >= (r*c)/2){
        printf("It is a Sparse Matrix!");
        return;
    }
    printf("It is not a Sparse matrix!");
    return;
}