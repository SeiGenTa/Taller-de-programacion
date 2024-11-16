#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.length();

    vector<int> pi(n, 0);
    for (int i = 1; i < n; ++i) {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j]) {
            j = pi[j - 1];
        }
        if (s[i] == s[j]) {
            ++j;
        }
        pi[i] = j;
    }

    unordered_map<int, int> occurrences;
    
    int current = pi[n - 1];
    while (current > 0) {
        occurrences[current]++;
        current = pi[current - 1];
    }

    occurrences[n]++;  // El sufijo completo es siempre una ocurrencia.

    vector<pair<int, int>> result;
    for (const auto& entry : occurrences) {
        result.push_back(entry);
    }

    sort(result.begin(), result.end());

    cout << result.size() << endl;
    for (const auto& entry : result) {
        cout << entry.first << " " << entry.second << endl;
    }

    return 0;
}
