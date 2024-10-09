#include <iostream>
#include <cstdlib>
using namespace std;

class SelectionSort{
    int *a;
    int n, i, j;
    public: 
        void insert(){
            cout<<"Enter the size of array"; cin>>n;
            a = new int[n];
            cout<<"Enter the elements into array:";
            for (i=0; i<n; i++){
                cout<<"\n"<<a[i];
            }
        }

        void display(){
            cout<<"\nSorted array is"<<endl;
            for (i=0; i<n; i++){
                cout<<" "<<a[i];
            }
        }

        void selectionSort(){
            int min, k, pos, temp;
            for(j=0; j<n-1; j++){
                min = a[j];
                i = j+1;
                pos = j;
                while (i<n){
                    if (a[i] < min){
                        min = a[i];
                        pos = 1;
                    }
                    i++;
                }
                a[pos] = a[j];
                a[j] = min;
                cout<<"\n Pass: "<<j+1;
                for (k = 0; k<n; k++){
                    cout<<" "<<a[k];
                }
            }
        }
};

int main(){
    SelectionSort SS;
    SS.insert();
    SS.selectionSort();
    SS.display();
    return 0;
}