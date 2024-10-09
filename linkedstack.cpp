#include<iostream>
using namespace std;

class node{
    public:
    int info;
    node* next;
};

class LinkedStack{
    private:
    node *top;
    int count, stackData, size;
    public:
        LinkedStack(int x){
            top = NULL;
            size = x;
            count = 0;
        }
        void push(){
            if (count == size){
                cout<<"Stack Overflow!";
            }
            else{
                node *Ntop = new node;
                int element;
                cout<<"Enter the element:"; cin>>element;
                Ntop->info = element;
                if (top==NULL){
                    Ntop->next = NULL;
                    top = Ntop;
                    count ++;
                }
                else{
                    Ntop->next = top;
                    top = Ntop;
                    count ++;
                }
            }
        }
        void pop(){
            if (top = NULL){
                cout<<"Stack Underflow!";
            }
            else{
                cout<<"Deleted item is:"<<top->info;
                node *old = top;
                top = top->next;
                count--;
                delete(old);
            }
        }
        void display(){
            node *temp;
            temp = top;
            while (temp != NULL){
                cout<<temp->info<<",";
                temp = temp->next;
            }
        }
        void peek(){
            cout<<"Top element is:"<<top->info;
        }
};