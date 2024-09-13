#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> prices(n);
    for (int i = 0; i < n; ++i) {
        cin >> prices[i];
    }
    vector<int> sorted_prices = prices;
    sort(sorted_prices.begin(), sorted_prices.end());
    vector<int> result(n);
    int index = 0;
    for (int i = n / 2; i < n; ++i) {
        result[index] = sorted_prices[i];
        index += 2;
    }
    index = 1;
    for (int i = 0; i < n / 2; ++i) {
        result[index] = sorted_prices[i];
        index += 2;
    }
    int maxBaratas = 0;
    for (int i = 1; i < n - 1; ++i) {
        if (result[i] < result[i - 1] && result[i] < result[i + 1]) {
            maxBaratas++;
        }
    }
    cout << maxBaratas << endl;
    for (int i = 0; i < n; ++i) {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}

