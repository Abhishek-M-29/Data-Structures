#include <stdio.h>
#define max 100;
int rear = -1, front = -1;
int queue[];
int enqueue(int n){
    if (rear+1 == front){
        printf("Overflow!");
    }
    if (front == -1){
        front++; rear++;
        queue[rear] = n;
    }
    else{
        rear = (rear+1)%max;
        queue[rear] = n;
    }
}