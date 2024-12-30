#include<stdio.h>
#include<stdlib.h>
 struct node
    {
        int sem;
        int phone_no;
        char name[20];
        char USN[20];
        char programe[10];
        struct node *next;
    };
    struct node *head=NULL,*temp=NULL,*p=NULL;
    void create()
    {
        temp=(struct node*)malloc(sizeof(struct node));
        if(!temp)
        {
          printf("\nMemory not allocated\n");
          exit(0);
        }
        printf("Enter USN:");
        getchar();
        scanf("%s",temp->USN);
        printf("Enter name:");
        getchar();
        scanf("%s",temp->name);
        printf("Enter programe:");
        getchar();
        scanf("%s",temp->programe);
        printf("Enter Sem:");
        scanf("%d",&temp->sem);
        getchar();
        printf("Enter phone no.:");
        scanf("%d",&temp->phone_no);
        getchar();
        temp->next=NULL;

        if(head==0)
          head=temp;
        else
        {//addition at front
            temp->next=head;
            head=temp;
        }
   }
   void display()
   {
    int count=0;
    p=head;
    printf("\n");
    printf("The Students details are:\n");
    while(p!=NULL)
    {
        
        printf("The USN is :%s\n",p->USN);
        printf("The name is:%s\n",p->name);
        printf("The programe enrolled is:%s\n",p->programe);
        printf("The current sem is:%d\n",p->sem);
        printf("The phone no. is:%d\n",p->phone_no);
        printf("\n");
        p=p->next;
        count++;
    }
    printf("\nThe total no of Students are:%d\n",count);
    printf("\n");
   }
   void addfront(){
	temp=(struct node*)malloc(sizeof(struct node));
	    printf("Enter usn:");
        getchar();
        scanf("%s",temp->USN);
        printf("Enter name:");
        getchar();
        scanf("%s",temp->name);
        printf("Enter programe:");
        getchar();
        scanf("%s",temp->programe);
        printf("Enter Sem:");
        scanf("%d",&temp->sem);
        getchar();
        printf("Enter phone no.:");
        scanf("%d",&temp->phone_no);
        getchar();
        temp->next=NULL;
	if(head==NULL){
			head=temp;
	}
	else{
			temp->next=head;
			head=temp;
		}
}
void addrear(){
	temp=(struct node*)malloc(sizeof(struct node));
	    printf("Enter usn:");
        getchar();
        scanf("%s",temp->USN);
        printf("Enter name:");
        getchar();
        scanf("%s",temp->name);
        printf("Enter programe:");
        getchar();
        scanf("%s",temp->programe);
        printf("Enter Sem:");
        scanf("%d",&temp->sem);
        getchar();
        printf("Enter phone no.:");
        scanf("%d",&temp->phone_no);
        getchar();
    temp->next=NULL;
	if(head==NULL){
			head=temp;
	}
	else{
			p=head;
			while(p->next!=NULL){
				p=p->next;
			}
			p->next=temp;
            
		}
}
void deletefront()
{
	if(head==NULL){
		printf("\nLink List is Empty ");
        return;
	}
	p=head;
	printf("\ndeleted %s",p->USN);
    printf("\ndeleted %s",p->name);
    printf("\ndeleted %s",p->programe);
    printf("\ndeleted %d",p->sem);
    printf("\ndeleted %d\n\n",p->phone_no);
	head=head->next;
	free(p);
}
void deleterear()
{
	if(head==NULL){
		printf("\nLink List is Empty ");
        return;
	}
	p=head;
	while(p->next->next!=NULL)
    {
		p=p->next;
	}
       printf("\ndeleted %s",p->USN);
       printf("\ndeleted %s",p->name);
       printf("\ndeleted %s",p->programe);
       printf("\ndeleted %d",p->sem);
       printf("\ndeleted %d",p->phone_no);
	free(p->next);
	p->next=NULL;
	//printf("\ndeleted\n\n");
}

int main() {
   
    while (1) {
        int choice;
        printf("Program by Abhishek S (1AY23CS007)");
        printf("\n*MENU*\n");
        printf("1.Create\n2.Display\n3.Add in front\n4.Add in end\n5.Delete in front\n6.Delete at end\n7.Exit\n");
        printf("Enter choice:");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                create(); 
                break;
            case 2:
                 display(); 
                break;
            case 3:
                 addfront(); 
                break;
            case 4:
                 addrear(); 
                break;
            case 5:
                 deletefront(); 
                break;
            case 6:
                 deleterear(); 
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice!\n");
               
        }
    }
    return 0;
}
