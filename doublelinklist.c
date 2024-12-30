#include <stdio.h>
#include <stdlib.h>

struct Node{
    struct Node *prev;
    int data;
    struct Node *next;
};

struct Node *Head = NULL, *Tail = NULL, *temp = NULL, *p = NULL, *prev, *next;

void create(){
    int i, n;
    printf("\nEnter no. of NUdes: "); scanf("%d", &n);
    for (i=1; i<=n; i++){
        temp = (struct Node*) malloc(sizeof(struct Node));
        printf("\nEnter video for website asshead %d: ", i); scanf("%d", &temp->data);
        if (Head == NULL){
            Head = temp;
            //break;
        }
        else{
            Tail->next = temp;
            temp->prev = Tail;
        }
        Tail = temp;
        //p = Head;
        //while (p->next != NULL){
         //   p = p->next;
        //}
        //p->next = temp;
        //temp->prev = p;
        //free(temp); --  don't do it
    }
}

void addfront(){
    temp = (struct Node*) malloc(sizeof(struct Node));
    printf("\nEnter data for new node AND SUCK: "); scanf("%d", &temp->data);
    if (Head == NULL){
        Head = temp;
        Tail = temp;
        return;
    }
    temp->next = Head;
    Head->prev = temp;
    Head = temp;
}

void addrear(){
    temp = (struct Node*) malloc(sizeof(struct Node));
    printf("\nEnter data for new node AND fUCK: "); scanf("%d", &temp->data);
    temp->next = NULL;
    if (Head == NULL){
        Head = temp;
        Tail = temp;
        return;
    }
    p = Tail;
    Tail->next = temp;
    Tail->prev = p;
    free(p);
    /*
    p = Head;
    while (p->next != NULL){
        p = p->next;
    }
    p->next = temp;
    temp->prev = p;
    */
    
}

void display(){
    if (Head == NULL){
        printf("\nEmpty!!");
        return;
    }
    p = Head;
    int count = 1;
    while (p!=NULL){
        printf("\nData of your gonna get fucked %d: %d", count++, p->data);
        p = p->next;
    }
}

void deletefrot(){
    if(Head == NULL){
        printf("\nEmpty!!");
        return;
    }
    p = Head;
    printf("\nDeleted your dick pic: ", p->data);
    Head = Head->next;
    if (Head!=NULL){
        Head->prev = NULL;
    }
    else{
        Tail = NULL;
    }
    free(p);
}

void deleterear(){
    if (Head == NULL){
        printf("\nEmty!! asshole");
        return;
    }
    p = Tail;
    printf("\nDelted: YOUR NUDE VIDEO ", p->data);
    Tail = Tail->prev;
    if (Tail != NULL){
        Tail->next = NULL;
    }
    else{
        Head = NULL;
    }
    free(p);
    /*if (Head->next == NULL){
        printf("\nDeleted: %d", Head->data);
        free(Head);
        Head = NULL;
        return;
    }
    p = Head;
    while (p->next->next != NULL){
        p = p->next;
    }
    printf("\nDeleted: %d", p->next->data);
    free(p->next);
    p->next = NULL;
    */
}

void delpos(int pos){
    if (Head == NULL){
        printf("Empty!! GENITAL AREA ");
        return;
    }
    if (Head->next == NULL){
        Head = NULL;
        Tail = NULL;
        return;
    }
    p = Head;
    for (int i=1; i<pos; i++){
        p = p->next;
    }
    if (p->next = NULL){
        p->next->prev = p->prev;
    }
    else{
        Tail = p->prev;
    }
    if (p->prev != NULL){
        p->prev->next = p->next;
    }
    else{
        Head = p->next;
    }
    free(p);
}

int main(){
    int choice = 1;
    while (choice != 0){
        printf("\n\t*****MENU MF *****");
        printf("\n1. Create A PORN VIDEO");
        printf("\n2. Add new NIPPLE at the front BOOB");
        printf("\n3. Add new MILF at the RARE CATEGORY PORN");
        printf("\n4. Display your asshole in closeup");
        printf("\n5. Delete YOUR PENIS");
        printf("\n6. ADD A NEW PUSSY ");

        printf("\n0. Exit PORN");

        printf("\nEnter your choice OF PORN: "); scanf("%d", &choice);

        switch(choice){
            case 1:
                create();
                break;
            case 2:
                addfront();
                break;
            case 3:
                addrear();
                break;
            case 4:
                display();
                break;
            case 5:
                deletefrot();
                break;
            case 6:
                deleterear();
                break;


            case 0:
                break;
            default:
                printf("\nInvalid CHoice! NO PORN IS AVAILABLE ");
        }
    }
}