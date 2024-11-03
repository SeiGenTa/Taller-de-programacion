#include <iostream>
#include <vector>

using namespace std;

class SegmentTree {
private:
    int n;
    vector<int> tree;

    void build(const string &s, int node, int start, int end) {
        if (start == end) {
            tree[node] = 1 << (s[start] - 'a');
        } else {
            int mid = (start + end) / 2;
            build(s, 2 * node, start, mid);
            build(s, 2 * node + 1, mid + 1, end);
            tree[node] = tree[2 * node] | tree[2 * node + 1];
        }
    }

    void update(int node, int start, int end, int pos, char oldChar, char newChar) {
        if (start == end) {
            tree[node] = 1 << (newChar - 'a');
        } else {
            int mid = (start + end) / 2;
            if (pos <= mid) {
                update(2 * node, start, mid, pos, oldChar, newChar);
            } else {
                update(2 * node + 1, mid + 1, end, pos, oldChar, newChar);
            }
            tree[node] = tree[2 * node] | tree[2 * node + 1];
        }
    }

    int query(int node, int start, int end, int l, int r) {
        if (r < start || end < l) {
            return 0;
        }
        if (l <= start && end <= r) {
            return tree[node];
        }
        int mid = (start + end) / 2;
        int left_query = query(2 * node, start, mid, l, r);
        int right_query = query(2 * node + 1, mid + 1, end, l, r);
        return left_query | right_query;
    }

public:
    SegmentTree(const string &s) {
        n = s.size();
        tree.resize(4 * n);
        build(s, 1, 0, n - 1);
    }

    void update(int pos, char oldChar, char newChar) {
        update(1, 0, n - 1, pos, oldChar, newChar);
    }

    int query(int l, int r) {
        int bitmask = query(1, 0, n - 1, l, r);
        return __builtin_popcount(bitmask);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    int q;
    cin >> s >> q;

    SegmentTree segTree(s);

    for (int i = 0; i < q; ++i) {
        int type;
        cin >> type;

        if (type == 1) {
            int pos;
            char c;
            cin >> pos >> c;
            pos--;
            if (s[pos] != c) {
                segTree.update(pos, s[pos], c);
                s[pos] = c;
            }
        } else if (type == 2) {
            int l, r;
            cin >> l >> r;
            l--; r--;
            cout << segTree.query(l, r) << '\n';
        }
    }

    return 0;
}
