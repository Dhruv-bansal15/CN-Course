#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

#include <bits/stdc++.h>
using namespace std;
vector<int> longestConsecutiveIncreasingSequence(int *arr, int n) {
    // Your Code goes here
    unordered_set<int> S;
    int ans = 0;
 	vector<int> output;
    for (int i = 0; i < n; i++)
        S.insert(arr[i]);
    for (int i = 0; i < n; i++){
        if (S.find(arr[i] - 1) == S.end())
        {
            // Then check for next elements
            // in the sequence
            int j = arr[i];
            while (S.find(j) != S.end())
                j++;
 
            // update  optimal length if
            // this length is more
            if(j - arr[i] > ans){
                ans = max(ans, j - arr[i]);
                output.clear();
                output.push_back(arr[i]);
                output.push_back(j-1);
            }
        }
    }
    return output;
}

int main() {
    int size;
    cin >> size;

    int* arr = new int[size];

    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    vector<int> ans = longestConsecutiveIncreasingSequence(arr, size);

    for (auto i = ans.begin(); i != ans.end(); ++i)
        cout << *i << " ";

    delete[] arr;
}
