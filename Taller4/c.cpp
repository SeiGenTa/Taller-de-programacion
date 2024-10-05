#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int longestUniqueSubsequence(const vector<int>& songs) {
    unordered_set<int> uniqueSongs;
    int maxLength = 0;
    int i = 0;
    
    for (int j = 0; j < songs.size(); ++j) {
        while (uniqueSongs.find(songs[j]) != uniqueSongs.end()) {
            uniqueSongs.erase(songs[i]);
            ++i;
        }
        uniqueSongs.insert(songs[j]);
        maxLength = max(maxLength, j - i + 1);
    }
    
    return maxLength;
}

int main() {
    int n;
    cin >> n;

    vector<int> songs(n);
    for (int i = 0; i < n; ++i) {
        cin >> songs[i];
    }

    cout << longestUniqueSubsequence(songs) << endl;

    return 0;
}
