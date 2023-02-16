#include <iostream>

using namespace std;

int dp[31];

int tile(int N) {
    dp[0] = 1; // 이게 왜 1인거지.... 왜 맞은거지...
    dp[1] = 0;
    dp[2] = 3;
    dp[3] = 0;
    for (int i = 4; i <= N; i++) {
        if (i % 2 != 0) {
            dp[i] = 0;
            continue;
        }
        dp[i] = dp[i-2]*4-dp[i-4];
    }
    return dp[N];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;
    cout << tile(N);
    return 0;
}
