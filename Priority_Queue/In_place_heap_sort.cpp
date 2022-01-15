#include <iostream>
void heapSort(int arr[], int n) {
    // Write your code
    if(n==1){
        return;
    }
    for(int i=1;i<n;i++){
        int j=i;
        while(j>0 & arr[j]<arr[(j-1)/2]){
            int parent = (j-1)/2;
            int temp = arr[j];
            arr[j] = arr[parent];
            arr[parent]=temp;
            j=parent;
        }
    }
    int start=0,end=n-1;
    while(start<end){
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end]=temp;
        end--;
        int parentIndex = start;
        while(2*parentIndex+1<=end){
            int child1 = 2*parentIndex+1;
            int child2 = 2*parentIndex+2;
            int finalIndex = child1;
            if(child2 <= end){
                if(arr[child2]<arr[child1]){
                    finalIndex = child2;
                }
            }
            if(arr[finalIndex]<arr[parentIndex]){
                int temp = arr[parentIndex];
                arr[parentIndex] = arr[finalIndex];
                arr[finalIndex] = temp;
            }else{
                break;
            }
            parentIndex = finalIndex;
        }
        
        
    }
    return;
    
}

using namespace std;

int main() {
    int size;
    cin >> size;

    int *input = new int[size];

    for (int i = 0; i < size; i++) {
        cin >> input[i];
    } 

    heapSort(input, size);

    for (int i = 0; i < size; i++) {
        cout << input[i] << " ";
    } 

    delete[] input;
}