#include <stdio.h>

#define MAXN 5000

int n;
int a[MAXN];
long long dp[MAXN][MAXN];

long long max(long long x, long long y) {
    return x > y ? x : y;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }

    for (int len = 1; len <= n; ++len) {
        for (int l = 0; l + len - 1 < n; ++l) {
            int r = l + len - 1;
            int turn = n - (r - l);  // Número de vaso que se está tomando
            if (len == 1) {
                dp[l][r] = turn * a[l];
            } else {
                dp[l][r] = max(turn * a[l] + dp[l + 1][r], turn * a[r] + dp[l][r - 1]);
            }
        }
    }

    printf("%lld\n", dp[0][n - 1]);
    return 0;
}
