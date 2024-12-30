#include <stdio.h>
#include <stdlib.h>
int capacity=100;

struct Participant{
    char name[50];
    int age;
    int rgno;
    struct Participant *next;
};

struct Queue{
    struct Participant *front;
    struct Participant *rear;
    int count;
};


void enqueue(struct Queue *q, int rgno){
    struct Participant *new = (struct Participant *) malloc(sizeof(struct Participant));
    if (!new){
        printf("Memory allocation failed!\n");
        return;
    }

    printf("Participant's name: "); scanf("%s", new->name);
    printf("\nEnter participant's age: "); scanf("%d", &new->age);
    new->rgno = rgno;
    new->next = NULL;

    if (q->rear == NULL){
        q->front = q->rear = new;
    }
    else{
        q->rear->next = new;
        q->rear = new;
    }
    q->count++;
    printf("\nParticipant %s added to the queue!", new->name);
}

void dequeue(struct Queue *q){
    if (q->front == NULL){
        printf("\nQueue is empty! No participants to process.\n");
        return;
    }

    struct Participant *temp = q->front;
    printf("\nProcessing participant:%s", temp->name);
    printf("\nReg no:%d", temp->rgno);
    printf("\nAge:%d", temp->age);

    q->front = q->front->next;
    if (q->front == NULL){
        q->rear = NULL;
    }
    free(temp);
    q->count--;
}

void peek(struct Queue *q){
    if (q->front == NULL){
        printf("Queue is empty! No participants in line.\n");
        return;
    }
    printf("\nNext participant: %s", q->front->name);
    printf("\nReg no: %d", q->front->rgno);
    printf("\nAge: %d", q->front->age);
}

void displayQueue(struct Queue *q){
    if(q->front == NULL){
        printf("Queue is empty! No participants enlisted.\n");
        return;
    }

    struct Participant *temp = q->front;
    printf("Participants in the Queue are:-\n");
    while (temp != NULL){
        printf("Name: %s, Age: %d, Reg no: %d\n", temp->name, temp->age, temp->rgno);
        temp = temp->next;
    }
}

int main(){
    struct Queue eventQueue;
    eventQueue.front = NULL;
    eventQueue.rear = NULL;
    eventQueue.count = 0;
    int choice, rgno = 1;
    
    while (1){
        printf("\n\t\tEVENT MANAGEMENT SYSTEM\n");
        printf("\n1.Enqueue a participant\n2.Process a participant\
        \n3.Peek at the next participant\n4.Display all the participants\
        \n5. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1: enqueue(&eventQueue, rgno++); break;
            case 2: dequeue(&eventQueue); break;
            case 3: peek(&eventQueue); break;
            case 4: displayQueue(&eventQueue); break;
            case 5: printf("Exiting the system.\n");
            printf("All participant's data is cleared!");
            exit(0);
            default: printf("\nInvalid choice!\n");
        }
    }
    return 0;
}