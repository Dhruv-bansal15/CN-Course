#include <iostream>
using namespace std;
#include <vector>
#include <bits/stdc++.h>
class PriorityQueue {
    vector<int> pq;
    // Declare the data members here

   public:
    PriorityQueue() {
        // Implement the constructor here
    }

    /**************** Implement all the public functions here ***************/

    void insert(int element) {
        // Implement the insert() function here
        pq.push_back(element);
        int childIndex = pq.size()-1;
        while(childIndex>0){
            int parentindex = (childIndex-1)/2;
            if(pq[childIndex]>pq[parentindex]){
                int temp = pq[childIndex];
                pq[childIndex] = pq[parentindex];
                pq[parentindex] = temp;
            }else{
                break;
            }
            childIndex = parentindex;
        }
    }

    int getMax() {
        // Implement the getMax() function here
        if(isEmpty()){
            return INT_MIN;
        }
        return pq[0];
    }

    int removeMax() {
        // Implement the removeMax() function here
        if(isEmpty()){
            return INT_MIN;
        }
        int temp = pq[0];
        pq[0] = pq[pq.size()-1];
        pq[pq.size()-1] = temp;
        pq.pop_back();
        
        int parentindex = 0;
        int leftchildIndex = 2*parentindex+1;
        int rightchildIndex = 2*parentindex+2;
        while(leftchildIndex<pq.size()){
            int minIndex = parentindex;
            if(pq[minIndex]<pq[leftchildIndex]){
                minIndex = leftchildIndex;
            }
            if(rightchildIndex<pq.size() & pq[minIndex]<pq[rightchildIndex]){
                minIndex = rightchildIndex;
            }
            if(minIndex==parentindex){
                break;
            }
            int temp = pq[parentindex];
            pq[parentindex] = pq[minIndex];
            pq[minIndex] = temp;
            
            parentindex = minIndex;
            leftchildIndex = 2*parentindex+1;
            rightchildIndex = 2*parentindex+2;
        }
        return temp;
    }

    int getSize() { 
        // Implement the getSize() function here
    	return pq.size();
    }

    bool isEmpty() {
        // Implement the isEmpty() function here
        return pq.size()==0;
    }
};

int main() {
    PriorityQueue pq;
    int choice;
    cin >> choice;

    while (choice != -1) {
        switch (choice) {
            case 1:  // insert
                int element;
                cin >> element;
                pq.insert(element);
                break;
            case 2:  // getMax
                cout << pq.getMax() << "\n";
                break;
            case 3:  // removeMax
                cout << pq.removeMax() << "\n";
                break;
            case 4:  // size
                cout << pq.getSize() << "\n";
                break;
            case 5:  // isEmpty
                cout << (pq.isEmpty() ? "true\n" : "false\n");
            default:
                return 0;
        }
        
        cin >> choice;
    }
}