#include <stdio.h>
#define max 7

struct Queue{
    int taskid;
    char task;
};

int front = -1, rear = -1;
struct Queue queue[max];

void add_task(int id, char txt) {
    if ((rear + 1) % max == front) {
        printf("Overflow!\n");
        return;
    }
    if (front == -1) {
        front = 0;
    }
    rear = (rear + 1) % max;
    queue[rear].taskid = id;
    queue[rear].task = txt;
    printf("\nTask sucessfully Scheduled!\n");
}

void remove_task() {
    if (front == -1) { 
        printf("Underflow!\n");
        return;
    }
    printf("Task: %s - is done! \n", queue[front].task);
    if (front == rear) {
        front = -1;
        rear = -1;
    }
    else {
        front = (front + 1) % max;
    }
}


void display() {
    if (front == -1) {
        printf("No more tasks left!\n");
        return;
    }
    printf("Tasks Pending");
    int i = front;
    while (i != rear) {
        printf("Task ID: %d\nTask: %s\n\n ", queue[i].taskid, queue[i].task);
        i = (i + 1) % max;
    }
    printf("%d\n%s\n", queue[rear].taskid, queue[rear].task);
}


int main(){
    printf("Hello!!\n");
    while(1){
        int choice;
        printf("1. Add a Task\n2. Process a Task\n3. Display Task Queue Status\n4. Exit\nEnter your choice : ");
        scanf("%d", &choice);
        switch(choice){
            case 1: 
                int taskid; char task;
                printf("\nEnter the task id: "); scanf("%d", &taskid);
                printf("\nEnter the task: "); scanf(" %s", &task);
                add_task(taskid, task);
                break;
            case 2:
                remove_task();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("\nGoodbye!\n");
                return 1;
            default: printf("\nEnter a valid choice!\n");
        }
    }
}