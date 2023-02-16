#include <iostream>

#define MAX 1000000
#define MOD 15746

using namespace std;

int dp[MAX + 1];

int dp_func(int N) {
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    for (int i = 4; i <= N; i++) {
        dp[i] = (dp[i - 1] + dp[i - 2])%MOD;
    }

    return dp[N];
}

int main() {
    int N;
    cin >> N;
    cout << dp_func(N);
}
