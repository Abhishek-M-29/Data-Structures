#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;

class queueArray{
    public:
    int *Q;
    int front, rear, x, size, result;
    
    queueArray(){
        cout<<"\nEnter the size of Queue:"; cin>>size;
        Q = new int[size];
        front = -1;
        rear = -1;
    }

    bool isempty(){
        if (rear == front){
            cout<<"Queue Underflow";
            return true;
        }
        return false;
    }

    bool isfull(){
        if (rear >= size-1){
            cout<<"Queue Overflow";
            return true;
        }
        return false;
    }

    void enqueue(){
        if (not isfull()){
            cout<<"\nEnter the number to be listed: "; cin>>x;
            Q[++rear] = x;
            cout<<"\n Number pushed in the Queue: "<<Q[rear];
        }
    }

    void dequeue(){
        if (not isempty()){
            cout<<"\nDeleted element is:";
            result = Q[++front];
            cout<<result;
        }
    }

    void display(){
        if (not isempty()){
            cout<<"\n Content(s) of the Queue:";
            for (int i=front+1; i<=rear; i++){
                cout<<Q[i]<<"\t";
            }
        }
    }
};

int main(){
    int c;
    queueArray q1;
    while (true){
        cout<<"\n\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit";
        cout<<"\nEnter your choice:"; cin>>c;
        switch(c){
            case 1: 
            q1.enqueue();
            break;
            case 2:
            q1.dequeue();
            break;
            case 3:
            q1.display();
            break;
            case 4:
            exit(0);
        }
    }
}