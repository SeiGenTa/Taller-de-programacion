#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long figuresInTime(const vector<int>& times, long long T) {
    long long total = 0;
    for (int time : times) {
        total += T / time;
        if (total >= 1000000000)
            break;
    }
    return total;
}

int main() {
    int n;
    long long k;
    cin >> n >> k;
    vector<int> times(n);
    for (int i = 0; i < n; ++i) {
        cin >> times[i];
    }
    long long low = 1;
    long long high = *min_element(times.begin(), times.end()) * k;
    long long result = high;
    while (low <= high) {
        long long mid = low + (high - low) / 2;
        if (figuresInTime(times, mid) >= k) {
            result = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    cout << result << endl;
    return 0;
}
