#include <iostream>
#include <unordered_map>
using namespace std;

int pairSum(int *arr, int n) {
	// Write your code here
    unordered_map<int, int> m;
    int cnt=0;
    // Traverse through all elements
    for (int i = 0; i < n; i++) {
        int rem = 0 - arr[i];
        if (m.find(rem) != m.end()) {
            int count = m[rem];
            for (int j = 0; j < count; j++)
                cnt++;
        }
        m[arr[i]]++;
    }
    return cnt;
}

int main() {
    int n;
    cin >> n;

    int* arr = new int[n];

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << pairSum(arr, n);

    delete[] arr;
}