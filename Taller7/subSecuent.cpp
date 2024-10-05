#include <iostream>
#include <vector>
#include <map>
#include <unordered_set>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    
    vector<int> s(n); 
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }
    
    unordered_set<int> allowed_diffs;  
    for (int i = 0; i < k; ++i) {
        int d;
        cin >> d;
        allowed_diffs.insert(d);
    }
    map<int, int> dp;
    int max_len = 1; 

    for (int i = 0; i < n; ++i) {
        int current_max = 1; 
        
        for (int d : allowed_diffs) {
            int prev_value = s[i] - d; 
            
            if (dp.count(prev_value)) {
                current_max = max(current_max, dp[prev_value] + 1);
            }
        }
        
        dp[s[i]] = current_max;
        
        max_len = max(max_len, current_max);
    }
    
    cout << max_len << endl;

    return 0;
}
