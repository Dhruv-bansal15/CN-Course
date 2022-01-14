// C++ implementation of De-queue using circular
// array
#include<iostream>
using namespace std;


// Driver program to test above function

class Deque {
    // Complete this class
    int *arr;
    int capacity,sz,next;
public:
    Deque(int x){
        arr = new int[x];
        capacity=x;
        sz=0;
        next=-1;
    }
    void insertFront(int ele){
        if(sz==0){
            next++;
            arr[next]= ele;
            sz++;
            return;
        }else if(sz==capacity){
            cout<<-1<<endl;
            return;
        }else{
            for(int i=next;i>=0;i--){
                arr[i+1] = arr[i];
            }
            arr[0]=ele;
            sz++;
            next++;
            return;
        }
    }
    void insertRear(int ele){
        if(sz==capacity){
			cout<<-1<<endl;
            return;
        }else{
            next++;
            arr[next]=ele;
            sz++;
        }
    }
    void deleteFront(){
        if(sz==0){
            cout<<-1<<endl;
            return;
        }else{
            for(int i=1;i<=next;i++){
                arr[i-1]= arr[i];
            }
            next--;
            sz--;
            return;
        }
    }
    void deleteRear(){
        if(sz==0){
            cout<<-1<<endl;
            return;
        }else{
            next--;
            sz--;
            return;
        }
    }
    int getFront(){
        if(sz==0){
            return -1;
        }else{
            return arr[0];
        }
    }
    int getRear(){
        if(sz==0){
            return -1;
        }else{
            return arr[sz-1];
        }
    }
    
};
int main()
{
    Deque dq(10);
    int choice,input;
    while(true) {
        cin >> choice;
        switch (choice) {
            case 1:
                cin >> input;
                dq.insertFront(input);
                break;
            case 2:
                cin >> input;
                dq.insertRear(input);
                break;
            case 3:
                dq.deleteFront();
                break;
            case 4:
                dq.deleteRear();
                break;
            case 5:
                cout << dq.getFront() << "\n";
                break;
            case 6:
                cout << dq.getRear() << "\n";
                break;
            default:
                return 0;
        }
    }
    
    return 0;
}
