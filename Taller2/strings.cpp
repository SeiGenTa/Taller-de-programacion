#include <iostream>
#include <vector>
using namespace std;

int main() {
    string s, t;
    cin >> s >> t;

    if (s.length() != t.length()) {
        cout << "NO" << endl;
        return 0;
    }

    vector<int> diff_indices;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] != t[i]) {
            diff_indices.push_back(i);
        }
    }

    if (diff_indices.size() == 2 &&
        s[diff_indices[0]] == t[diff_indices[1]] &&
        s[diff_indices[1]] == t[diff_indices[0]]) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
