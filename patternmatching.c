#include<stdio.h>
#include<string.h>

int main(){
    char *STR, *PAT;
    int i, j;
    //char *string = "AABCABCAABAB", *pattern = "AABA";
    printf("Enter a string:"); scanf("%s", STR);
    printf("\nEnter pattern:"); scanf("%s", PAT);
    char m,n;
    m = strlen(STR);
    n = strlen(PAT);
    for (i=0; i<m-n; i++)
    {
        for (j=0; j<n; j++)
        {
            if (STR[i+j] != PAT[j]){
                break;
            }
        }
            if (j == n){
            printf("\nPattern matched at %d index", i+1);
            
            }
        
    }
   
}