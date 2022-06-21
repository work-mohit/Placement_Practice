#include<bits/stdc++.h>
using namespace std;

// sources
//  https://www.programiz.com/dsa/heap-data-structure
// love babber
class Heap{
    public:
        int arr[100];
        int size;
        Heap(){
            arr[0] = -1;
            size = 0;
        }
        void insert(int val){
            
            size = size + 1;
            int index = size;
            arr[index] = val;

            while(index > 1){
                int parent = index / 2;
                if(arr[parent] < arr[index]){
                    swap(arr[parent], arr[index]);
                    index = parent;
                }else{
                    return;
                }
                
            }
            cout<<"Insertion complete!"<<endl;
        }
        void printHeap(){
            for(int i = 1; i <= size; i++){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
        void deleteFromHeap(){
            if(size == 0){
                cout<<"Nothing to delete";
                return;
            }
            int ele = arr[size];   // isko save krlo dikhane ke kaaam aaega
            arr[1] = arr[size];    // first me last ka data daal do 
            size--;
            
            int i = 1;
            while(i < size){
                int leftIndex = 2*i;
                int rightIndex = 2*i+1;

                if(leftIndex < size && arr[leftIndex] > arr[i]){
                    swap(arr[leftIndex], arr[i]);
                    i = leftIndex;
                }
                else if(rightIndex < size && arr[rightIndex] > arr[i]){
                    swap(arr[rightIndex], arr[i]);
                    i = rightIndex; 
                }else{
                    return;
                }
            }
            cout<<ele<<" is deleted from heap."<<endl;
        }
};
void heapify(int arr[], int n , int i){
    int largest = i;

    int left = 2*i;
    int right = 2*i + 1;

    if(left < n && arr[left] >arr[largest]){
        largest = left;
    }
    if(right < n && arr[right] > arr[largest])
        largest = right;

    if(largest != i){
        swap(arr[i] , arr[largest]);
        heapify(arr, n , largest);
    }
}

int main(){ 
    // Heap h;
    // h.insert(34);
    // h.insert(38);
    // h.insert(45);
    // h.insert(20);
    // h.insert(50);
    
    // h.printHeap();
    // h.deleteFromHeap();
    // h.printHeap();

    int arr[6] ={-1,55,53,59,60,23};
    int n = 5;
    for(int i = n/2; i> 0; i--){
        heapify(arr, n, i);
    }

    for(int i = 1; i <= n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}
