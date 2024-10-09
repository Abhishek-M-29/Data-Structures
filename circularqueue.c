#include<stdio.h>
#define max 100

int queue[max], front = -1, rear = -1;

void enqueue(int n) {
    if ((rear + 1) % max == front) {
        printf("Overflow!\n");
        return;
    }
    if (front == -1) {
        front = 0;
    }
    rear = (rear + 1) % max;
    queue[rear] = n;
    printf("%d enqueued to queue.\n", n);
}

void dequeue() {
    if (front == -1) {
        printf("Underflow!\n");
        return;
    }
    printf("%d dequeued from queue.\n", queue[front]);
    if (front == rear) {
        front = -1;
        rear = -1;
    }
    else {
        front = (front + 1) % max;
    }
}

void status() {
    if (front == -1 && rear == -1) {
        printf("Queue is empty!\n");
    } 
    else if ((rear + 1) % max == front) {
        printf("Queue is full!\n");
    } 
    else {
        printf("Queue is partially filled!\n");
    }
}

void display() {
    if (front == -1) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue elements: ");
    int i = front;
    while (i != rear) {
        printf("%d ", queue[i]);
        i = (i + 1) % max;
    }
    printf("%d\n", queue[rear]);
}

int main() {
    printf("Abhishek's Program (1AY23CS006)\n\n");
    while (1){
        int choice, n;
        printf("\n1.Enqueue\n2.Dequeue\n3.Status\n4.Display\n5.Exit\n");
        printf("Enter your choice : "); scanf("%d", &choice);
        switch (choice){
        case 1:
            printf("Enter digit to Enqueue :"); scanf("%d", &n);
            enqueue(n);
            break;
        
        case 2:
            dequeue();
            break;
        
        case 3:
            status();
            break;
        
        case 4:
            display();
            break;
        
        case 5:
            return 1;
        default:
            printf("Enter Valid Input!!\n");
            break;
        }
    }

	return 0;
}
