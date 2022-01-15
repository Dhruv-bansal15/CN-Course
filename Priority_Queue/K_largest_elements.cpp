#include <iostream>
using namespace std;
#include <bits/stdc++.h>
using namespace std;
vector<int> kLargest(int input[], int n, int k){
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i=0;i<k;i++){
        pq.push(input[i]);
    }
    int i=k;
    while(i<n){
        int ele = pq.top();
        if(ele<input[i]){
            pq.pop();
            pq.push(input[i]);
        }
        i++;
    }
    vector<int> v(k);
    i=0;
    while(i<k){
        int ele= pq.top();
        v[i]=ele;
        pq.pop();
        i++;
    }
    return v;

}


int main() {
	
	int size;
	cin >> size;
	int *input = new int[1 + size];
	
	for(int i = 0; i < size; i++)
		cin >> input[i];
    
    int k;
    cin >> k;
    
    vector<int> output = kLargest(input, size, k);
    for(int i = 0; i < output.size(); i++)
        cout << output[i] << endl;
	
	return 0;
}
