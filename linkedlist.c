#include <stdio.h>
#include<string.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

int main(){
    int n;
    struct Node *temp, *head = NULL, *p;
    printf("Enter the number of nodes:"); scanf("%d", &n);
    for (int i=0; i<n; i++){
        temp = (struct Node*)malloc(sizeof(struct Node));
        printf("Enter data:"); scanf("%d", &temp->data);
        temp->next = NULL;
        if (head==NULL){
            head = temp;
        }
        else{
            p = head;
            while (p->next!=NULL)
            {
                p = p->next;
            }
            p->next = temp;
        }
    }
    p = head;
    while(p != NULL){
        printf("%d\t", p->data);
        p = p->next;
    }
}