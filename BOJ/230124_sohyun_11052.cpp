#include <iostream>

using namespace std;

int dp[1001];

int main() {
    int N;
    cin >> N;
    int *input = new int(N+1);

    for (int i = 1; i <= N; i++) {
        cin >> input[i];
    }
    dp[0] = input[0] = 0; // 초기화

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            dp[i] = max(dp[i], dp[i - j] + input[j]);
        }
    }
    cout << dp[N];
    return 0;
}
