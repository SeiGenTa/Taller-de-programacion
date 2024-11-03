#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct FenwickTree {
    vector<int> bit;
    int n;

    FenwickTree(int size) : n(size) {
        bit.assign(n + 1, 0);
    }

    void update(int index, int value) {
        for (; index <= n; index += index & -index)
            bit[index] += value;
    }

    int query(int index) {
        int sum = 0;
        for (; index > 0; index -= index & -index)
            sum += bit[index];
        return sum;
    }
    
    int query(int left, int right) {
        return query(right) - query(left - 1);
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> sorted_a = a;
    sort(sorted_a.begin(), sorted_a.end());
    
    for (int i = 0; i < n; ++i) {
        a[i] = lower_bound(sorted_a.begin(), sorted_a.end(), a[i]) - sorted_a.begin() + 1;
    }

    FenwickTree left_tree(n), right_tree(n);
    vector<int> left_greater(n), right_smaller(n);

    for (int j = n - 1; j >= 0; --j) {
        right_smaller[j] = right_tree.query(a[j] - 1);
        right_tree.update(a[j], 1);
    }

    long long total_triplets = 0;
    for (int j = 0; j < n; ++j) {
        left_greater[j] = left_tree.query(n) - left_tree.query(a[j]);
        total_triplets += (long long)left_greater[j] * right_smaller[j];
        left_tree.update(a[j], 1);
    }

    cout << total_triplets << endl;

    return 0;
}
