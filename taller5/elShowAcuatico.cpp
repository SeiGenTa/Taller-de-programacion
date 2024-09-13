#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long calculateWater(const vector<int>& heights, int h) {
    long long water = 0;
    for (int height : heights) {
        if (height < h) {
            water += (h - height);
        }
    }
    return water;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        long long x;
        cin >> n >> x;
        vector<int> heights(n);
        for (int i = 0; i < n; ++i) {
            cin >> heights[i];
        }
        int low = 1;
        int high = *max_element(heights.begin(), heights.end()) + x;
        int result = 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (calculateWater(heights, mid) <= x) {
                result = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        cout << result << endl;
    }
    return 0;
}
