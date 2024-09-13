#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool canPartition(const vector<int>& arr, int k, long long maxSum) {
    int count = 1;
    long long currentSum = 0;
    for (int num : arr) {
        if (currentSum + num > maxSum) {
            count++;
            currentSum = num;
            if (count > k) return false;
        } else {
            currentSum += num;
        }
    }
    return true;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    long long totalSum = 0;
    int maxValue = 0;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        totalSum += arr[i];
        maxValue = max(maxValue, arr[i]);
    }
    long long low = maxValue;
    long long high = totalSum;
    long long result = high;
    while (low <= high) {
        long long mid = low + (high - low) / 2;
        if (canPartition(arr, k, mid)) {
            result = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    cout << result << endl;
    return 0;
}
