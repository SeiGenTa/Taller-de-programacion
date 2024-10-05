#include <stdio.h>

#define MAXN 200000

long long flies[MAXN];
long long max_flies[MAXN];

long long max(long long a, long long b) {
    return a > b ? a : b;
}

int main() {
    int t;
    scanf("%d", &t);
    
    while (t--) {
        int n;
        scanf("%d", &n);
        
        for (int i = 0; i < n; ++i) {
            scanf("%lld", &flies[i]);
            max_flies[i] = 0;
        }

        for (int i = n - 1; i >= 0; --i) {
            if (i + flies[i] < n) {
                max_flies[i] = flies[i] + max_flies[i + flies[i]];
            } else {
                max_flies[i] = flies[i];
            }
        }
        
        long long result = 0;
        for (int i = 0; i < n; ++i) {
            result = max(result, max_flies[i]);
        }
        
        printf("%lld\n", result);
    }
    
    return 0;
}
