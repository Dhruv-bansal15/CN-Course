#include <iostream>
#include <unordered_map>
#include<algorithm>
using namespace std;
using namespace std;
int lengthOfLongestSubsetWithZeroSum(int* arr, int n) {
    unordered_map<int, int> presum;
    int sum = 0; 
    int max_len = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
 
        if (arr[i] == 0 && max_len == 0)
            max_len = 1;
        if (sum == 0)
            max_len = i + 1;
        if (presum.find(sum) != presum.end()) {
            max_len = max(max_len, i - presum[sum]);
        }
        else {
            presum[sum] = i;
        }
    }
 
    return max_len;
}

int main() {
    int size;
    cin >> size;

    int* arr = new int[size];

    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    cout << lengthOfLongestSubsetWithZeroSum(arr, size);

    delete[] arr;
}