#include <iostream>

using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    long long dp[41][2];
    dp[0][0] = 1;
    dp[0][1] = 0;
    dp[1][0] = 0;
    dp[1][1] = 1;
    dp[2][0] = 1;
    dp[2][1] = 1;
    for (int i = 3; i < 41; i++) {
        dp[i][0] = dp[i - 1][0] + dp[i - 2][0];
        dp[i][1] = dp[i - 1][1] + dp[i - 2][1];
    }
    for (int i = 0; i < T; i++) {
        int N;
        cin >> N;
        cout << dp[N][0] << " " << dp[N][1] << "\n";
    }
    return 0;
}
