#include <iostream>
using namespace std;

#include <queue>
void findMedian(int *arr, int n)
{
    // Write your code here
    if(n==1){
        cout<<arr[0];
        return;
    }else if(n==0){
        return;
    }
    priority_queue<int> max_heap;
    priority_queue<int, vector<int>,greater<int>> min_heap;
    max_heap.push(arr[0]);
    cout<<arr[0]<<" ";
    for(int i=1;i<n;i++){
        if(max_heap.top() > arr[i]){
            max_heap.push(arr[i]);
        }else{
            min_heap.push(arr[i]);
        }
        int a = max_heap.size(),b= min_heap.size();
        if(a==b){
            int temp = (max_heap.top()+min_heap.top())/2;
            cout<<temp<<" ";
        }else if(a-b==1){
            cout<<max_heap.top()<<" ";
        }else if(b-a==1){
            cout<<min_heap.top()<<" ";
        }else{
            if(a-b==2){
                int temp = max_heap.top();
                max_heap.pop();
                min_heap.push(temp);
                int temp1 = (max_heap.top()+min_heap.top())/2;
            	cout<<temp1<<" ";
            }else{
                int temp = min_heap.top();
                min_heap.pop();
                max_heap.push(temp);
                int temp1 = (max_heap.top()+min_heap.top())/2;
            	cout<<temp1<<" ";
            }
        }
    }
    return;
}

int main() {
    int n;
    cin >> n;

    int* arr = new int[n];

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    findMedian(arr,n);

    delete[] arr;
}
