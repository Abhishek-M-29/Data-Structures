#include<iostream>
#include<cstdlib>
using namespace std;

class Bubblesort{
    int *a;
    int n, i, j;
    public:
        void insert(){
            cout<<"Enter the size of array:"; cin>>n;
            a = new int[n];
            cout<<"ENter the elements into the array\n";
            for (i=0; i<n; i++){
                cin>>a[i];
            }
        }
        void display(){
            cout<<"\nSorted array is"<<endl;
            for (i=0; i<n; i++){
                cout<<" "<<a[i];
            }
        }
        void bubblesort(){
            int temp, k;
            for (i=0; i<n-1; i++){
                for (j=0; j<n-1; j++){
                    if (a[j+1] < a[j]){
                        temp = a[j];
                        a[j] = a[j+1];
                        a[j+1] = temp;
                    }
                }
            }
           // cout<<"\n Pass :"<< i+1;
            for (k=0; k<n; k++){
                cout<<" "<<a[k];
            }
        }
};

int main(){
    Bubblesort bs;
    bs.insert();
    bs.bubblesort();
    bs.display();
    return 0;
}