// KMP - Pattern Matcing
// knuth-morris-pratt
#include <stdio.h>
#include <string.h>

void main(){
    char str[25];// = "abababababababc";
    char pattern[5];// = "abc";
    printf("Enter the string :"); scanf("%s", &str);
    printf("\nEnter the pattern :"); scanf("%s", &pattern);
    char m = strlen(str), n = strlen(pattern);
    int i,j;
    for (i=0; i<m; i++){
        int len = 0;
        for (j=0; j<n; j++){
            if (str[i] != pattern[j]){
                break;
            }
            i++;
        }
        if (j==n){
            printf("The pattern is found at index %d.\n", i);
        }
    }
}