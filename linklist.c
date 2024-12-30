#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *Next;
};

struct Node *Head = NULL, *temp = NULL, *p = NULL, *prev, *next;


void create(){
    int i, n;
    printf("\nEnter no. of Nodes: "); scanf("%d", &n);
    for (i=1; i<=n; i++){
        temp = (struct Node*) malloc(sizeof(struct Node));
        printf("\nEnter data for node %d : ", i); scanf("%d", &temp->data);
        if (Head == NULL){
            Head = temp;
        }
        else{
            temp->Next = Head;
            Head = temp;
        }
    }
}


void addfront(){
    temp = (struct Node*) malloc(sizeof(struct Node));
    printf("\nEnter data for New node : "); scanf("%d", &temp->data);
    temp->Next = NULL;
    if (Head == NULL){
        Head = temp;
    }
    else{
        temp->Next = Head;
        Head = temp;
    }
}


void add_rear(){
    temp = (struct Node*) malloc(sizeof(struct Node));
    printf("\nEnter data for New mode: "); scanf("%d", &temp->data);
    temp->Next = NULL;
    if (Head == NULL){
        Head = temp;
    }
    else{
        p = Head;
        while (p->Next != NULL){
            p = p->Next;
        }
        p->Next = temp;
    }
}


void display(){
	if(Head==NULL){
		printf("\nNo Link List Available ");
        return;
	}
	p=Head;
    int count = 1;
	while(p!=NULL){
		printf("\nData %d: %d ",count++, p->data);
		p=p->Next;
	}
    return;
}


void deletefront(){
	if(Head==NULL){
		printf("\nLink List is Empty ");
        return;
	}
	p=Head;
	printf("\ndeleted %d",p->data);
	Head=Head->Next;
	free(p);
}


void deleterear(){
	if(Head==NULL){
		printf("\nLink List is Empty ");
        return;
	}
    if (Head->Next == NULL) {
        printf("\nDeleted: %d", Head->data);
        free(Head);
        Head = NULL;
        return;
    }
	p=Head;
	while(p->Next->Next!=NULL){
		p=p->Next;
	}
	printf("\ndeleted %d",p->Next->data);
	free(p->Next);
	p->Next=NULL;
	printf("\ndeleted");
}


void delete(int pos){
    int count = 1;
    if (Head == NULL){
        printf("\n The list is empty!");
        return;
    }
    if (pos == 1){
        p = Head;
        Head = Head->Next;
        printf("\nDeleted: %d", p->data);
        free(p);
        return;
    }
    p = Head;
    while (count<pos-1){
        if (p->Next != NULL){
            p = p->Next;
            count ++;
        }
        else{
            printf("\nInvalid Position");
            return;
        }
    }
    temp = p->Next;
    if (temp = NULL){
        printf("\nInvalid Position");
        return;
    }
    printf("Deleted: %d", temp->data);
    p->Next = p->Next->Next;
    free(temp);
}


void reverse(){
    if (Head == NULL){
        printf("\nList is Empty!");
        return;
    }

    //temp = (struct Node*) malloc(sizeof(struct Node));
    p = Head;
    prev = NULL;

    while (p != NULL){
        next = p->Next;
        p->Next = prev;
        prev = p;
        p = next;

    }
    Head = prev;
    printf("\nList Reversed!");
}


int main(){
	
	int choice = 1;
	while(choice != 0){
		printf("\n\t*****Menu********");
		printf("\n1. Create Link List");
		printf("\n2. Add New Node at the front");
		printf("\n3. Add New Node at the rear");
        printf("\n4. Add New Node at pos");
		printf("\n5. Delete Node from the front");
		printf("\n6. Delete Node from the End");
        printf("\n7. Delete Node from pos");
		printf("\n8. Display status of SLL");
        printf("\n9. Reverse");
		printf("\n0. Exit");

		printf("\nEnter your Choice: "); scanf("%d",&choice);

		switch(choice){
			case 1:
				create();
				break;
			case 2:
				addfront();
				break;
			case 3:
				add_rear();
				break;
			case 5:
				deletefront();
				break;
			case 6:
				deleterear();
				break;
            case 7:
                int a;
                printf("\nEnter position:"); scanf("%d", &a);
                delete(a);
                break;
			case 8: 
				display();
				break;
            case 9:
                reverse();
                break;
			case 0: 
				break;
			default:
				printf("Invalid Choice");
		}
	}
	printf("\nEnd of Program");
	return 0;
}