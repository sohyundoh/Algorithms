#include <iostream>
#include <algorithm>
#include <cstring>
int arr[100000][3] = {{0,}};
int dp[100000][3] = {{0,}};
using namespace std;

int main() {
    int N, min_num, max_num;
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < 3; i++) {
        dp[0][i] = arr[0][i];
    }
    for (int i = 1; i < N; i++) {
        dp[i][0] = arr[i][0] + max(dp[i - 1][0], dp[i - 1][1]);
        dp[i][1] = arr[i][1] + max(max(dp[i - 1][1], dp[i - 1][0]), dp[i - 1][2]);
        dp[i][2] = arr[i][2] + max(dp[i - 1][1], dp[i - 1][2]);
    }
    max_num = max(max(dp[N - 1][0], dp[N - 1][1]), dp[N - 1][2]);

    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < 3; i++) {
        dp[0][i] = arr[0][i];
    }
    for (int i = 1; i < N; i++) {
        dp[i][0] = arr[i][0] + min(dp[i - 1][0], dp[i - 1][1]);
        dp[i][1] = arr[i][1] + min(min(dp[i - 1][1], dp[i - 1][0]), dp[i - 1][2]);
        dp[i][2] = arr[i][2] + min(dp[i - 1][1], dp[i - 1][2]);
    }
    min_num = min(min(dp[N - 1][1], dp[N - 1][0]), dp[N - 1][2]);
    cout << max_num << " "
         << min_num;
}
