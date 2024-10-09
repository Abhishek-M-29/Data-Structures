#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
	printf("Abhishek's program(1AY23CS006)\n\n");
	char *string = (char*)malloc(100 * sizeof(char));
    char *pattern = (char*)malloc(50 * sizeof(char));
    char *replace = (char*)malloc(50 * sizeof(char));

    if(string == NULL || pattern == NULL || replace == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
	//char *string="AAABCABBACAACAABCAABB";
	//char *pattern="AABCA";
    //char *replace = "CCABC";
	printf("Enter the string: "); scanf("%s", string);
	printf("Enter the pattern: "); scanf("%s", pattern);
	printf("Enter the replacing string: "); scanf("%s", replace);
	int m,n,o,i,j;
	m=strlen(string);
	n=strlen(pattern);
    o = strlen(replace);
	for(i=0;i<m-n;i++){
		for(j=0;j<n;j++){
			if(string[i+j]!=pattern[j]){
				break;
			}
		}
		if(j==n){
			printf("\nPattern Found at location %d ",i+1);
            for(j=0;j<o;j++){
                string[i+j] = replace[j];
            }
			printf("\nString replaced");
        	break;
		}  
	}
    printf("\nThe replaced string is: %s", string);
	return 0;
}