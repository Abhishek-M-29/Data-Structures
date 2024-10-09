#include<iostream>
#include<stdlib.h>
using namespace std;

class node{
    public:
        int info;
        node *next;
};

class Queue{
    private:
        node *rear;
        node *front;
    public:
        Queue(){
            rear = NULL;
            front = NULL;
        }
        void enqueue(){
            int ele;
            node *tempnode = new node;
            cout<<"Enter the element into Queue:"; cin>>ele;
            tempnode->info = ele;
            tempnode->next = NULL;
            if (front == NULL){
                front = tempnode;
            }
            else{
                rear->next = tempnode;
            }
            rear = tempnode;
        }
        void dequeue(){
            node *tempnode = new node;
            if (front == NULL){
                cout<<"\nQueue Underflow!";
            }
            else{
                tempnode = front;
                front = front->next;
                cout<<"The element deleted is"<<tempnode->info;
                delete tempnode;
            }
        }
        void display(){
            node *p = new node;
            p = front;
            if (front == NULL){
                cout<<"\nQueue Underflow\n";
            }
            else{
                cout<<"Contents of queue:";
                while (p != NULL){
                    cout<<p->info<<" ";
                    p = p->next;
                }
            }
        }
};

int main(){
    Queue queue;
    int c;
    while (true){
        cout<<"\n1.Insertion\n2.Deletion\n3.Display\n4.Exit\n";
        cout<<"\nEnter your choice: "; cin>>c;
        switch (c){
            case 1: queue.enqueue();
            break;
            case 2: queue.dequeue();
            break;
            case 3: queue.display();
            break;
            case 4: exit(0);
        }
    }
}