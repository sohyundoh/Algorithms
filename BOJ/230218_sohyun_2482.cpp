#include <iostream>

#define mod 1000000003
using namespace std;
int dp[1003][1003];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, k;
    cin >> N >> k;

    for (int i = 0; i <= N; i++) {
        dp[i][1] = i;
        dp[i][0] = 1;
    }
    dp[2][2] = 0;
    for (int i = 4; i <= N; i++) {
        for (int j = 2; j <= k; j++) {
            dp[i][j] = (dp[i - 2][j - 1] + dp[i - 1][j]) % mod;
        }
    }
    cout << dp[N][k];
    return 0;
}
