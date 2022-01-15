#include <iostream>
#include <climits>
#include <vector>
using namespace std;

class PriorityQueue {
    vector<int> pq;

   public:
    bool isEmpty() { 
        return pq.size() == 0; 
    }

    int getSize() { 
        return pq.size(); 
    }

    int getMin() {
        if (isEmpty()) {
            return 0;
        }

        return pq[0];
    }

    void insert(int element) {
        pq.push_back(element);

        int childIndex = pq.size() - 1;

        while (childIndex > 0) {
            int parentIndex = (childIndex - 1) / 2;

            if (pq[childIndex] < pq[parentIndex]) {
                int temp = pq[childIndex];
                pq[childIndex] = pq[parentIndex];
                pq[parentIndex] = temp;
            } else {
                break;
            }

            childIndex = parentIndex;
        }
    }

    int removeMin() {
        
        // Write your code here
        int temp1 = pq[0];
        pq[0] = pq[pq.size()-1];
        pq[pq.size()-1] = temp1;
        pq.pop_back();
        int parentIndex = 0;
        while(2*parentIndex+1<=pq.size()-1){
            int child1 = 2*parentIndex+1;
            int child2 = 2*parentIndex+2;
            int finalIndex = child1;
            if(child2 <= pq.size()-1){
                if(pq[child2]<pq[child1]){
                    finalIndex = child2;
                }
            }
            if(pq[finalIndex]<pq[parentIndex]){
                int temp = pq[parentIndex];
                pq[parentIndex] = pq[finalIndex];
                pq[finalIndex] = temp;
            }else{
                break;
            }
            parentIndex = finalIndex;
        }
        return temp1;
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
            case 2:  // getMin
                cout << pq.getMin() << "\n";
                break;
            case 3:  // removeMax
                cout << pq.removeMin() << "\n";
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