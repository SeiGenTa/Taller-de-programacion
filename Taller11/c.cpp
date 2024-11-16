#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 2 * 100000 + 5;
const int ALPHABET_SIZE = 26;

// Segment tree structure
struct SegmentTree {
    vector<int> tree[MAX_N]; // store the frequency of each character in the range

    void build(int node, int start, int end, const string &s) {
        if (start == end) {
            // initialize the tree at leaf node
            tree[node] = vector<int>(ALPHABET_SIZE, 0);
            tree[node][s[start] - 'a'] = 1;
        } else {
            int mid = (start + end) / 2;
            build(2 * node, start, mid, s);
            build(2 * node + 1, mid + 1, end, s);
            // merge the results
            merge(tree[2 * node].begin(), tree[2 * node].end(),
                  tree[2 * node + 1].begin(), tree[2 * node + 1].end(),
                  tree[node].begin());
        }
    }

    void update(int node, int start, int end, int idx, char new_char, const string &s) {
        if (start == end) {
            // update leaf node
            tree[node][s[start] - 'a']--;
            tree[node][new_char - 'a']++;
        } else {
            int mid = (start + end) / 2;
            if (start <= idx && idx <= mid)
                update(2 * node, start, mid, idx, new_char, s);
            else
                update(2 * node + 1, mid + 1, end, idx, new_char, s);
            // merge the results
            merge(tree[2 * node].begin(), tree[2 * node].end(),
                  tree[2 * node + 1].begin(), tree[2 * node + 1].end(),
                  tree[node].begin());
        }
    }

    bool query(int node, int start, int end, int l, int r) {
        if (l > r) return true;
        if (l == start && r == end) {
            // check if the range is palindrome
            for (int i = 0; i < ALPHABET_SIZE; i++) {
                if (tree[node][i] % 2 != 0) {
                    return false;
                }
            }
            return true;
        }
        int mid = (start + end) / 2;
        bool left_query = query(2 * node, start, mid, l, min(r, mid));
        bool right_query = query(2 * node + 1, mid + 1, end, max(l, mid + 1), r);
        return left_query && right_query;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    string s;
    cin >> s;

    SegmentTree segTree;
    segTree.build(1, 0, n - 1, s);

    while (m--) {
        int type;
        cin >> type;
        
        if (type == 1) {
            int k;
            char x;
            cin >> k >> x;
            k--; // change to 0-indexed
            s[k] = x; // update the string
            segTree.update(1, 0, n - 1, k, x, s); // update segment tree
        } else if (type == 2) {
            int a, b;
            cin >> a >> b;
            a--; b--; // change to 0-indexed
            if (segTree.query(1, 0, n - 1, a, b)) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }

    return 0;
}
