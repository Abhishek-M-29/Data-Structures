#include <stdio.h>
#include <stdlib.h>
#define QSIZE 5
char q[QSIZE];
int r = -1, f = 0, count = 0;
void enqueue()
{
    if (count == QSIZE)
    {
        printf("Queue Overflow\n");
        return;
    }
    printf("Enter the item to be inserted\n");
    char item;
    scanf(" %c", &item);
    r = (r + 1) % QSIZE;
    q[r] = item;
    count++;
}
void dequeue()
{
    if (count == 0)
    {
        printf("Queue Underflow\n");
        return;
    }
    printf("The item deleted is: %c\n", q[f]);
    f = (f + 1) % QSIZE;
    count--;
}
void display()
{
    int i;

    if (count == 0)
    {
        printf("Queue is Empty\n");
        return;
    }
    printf("Contents of the queue\n");
    for (i = 0; i < count; i++)
    {
        printf("%c ", q[(f + i) % QSIZE]);
    }
    printf("\n");
}
void main()
{
    printf("Abhishek S\t USN-1AY23CS007\n");
    int choice;
    do
    {
        printf("\n");
        printf("Circular Queue Operations\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Quit\n");
        printf("Enter your choice:\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4: printf("exiting\n");
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    } while (choice != 4);
}