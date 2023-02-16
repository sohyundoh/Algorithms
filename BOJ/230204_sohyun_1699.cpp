#include <iostream>

using namespace std;
#define MAX 100001
int dp[MAX];

int dp_func(int n) {
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    for (int i = 4; i < n + 1; i++) {
        dp[i] = dp[i - 1] + 1;
        for (int j = 1; j * j <= i; j++) {
            dp[i] = min(dp[i], dp[i - j * j] + 1);
        }
    }
    return dp[n];
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    cout << dp_func(n);
}
