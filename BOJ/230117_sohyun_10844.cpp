#include <iostream>
#define MAX 100
using namespace std;

long long dp[MAX][10] = {{0,},
                         {0, 1, 1, 1, 1, 1, 1, 1, 1, 1}};

long long stairs_num(int N) {
    long long sum = 0;
    for (int i = 2; i <= N; i++) {
        dp[i][0] = dp[i - 1][1] % 1000000000;
        dp[i][9] = dp[i - 1][8] % 1000000000;
        for (int j = 1; j <= 8; j++) {
            dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1])% 1000000000;
        }
    }
    for (int i = 0; i < 10; i++) {
        sum += dp[N][i];
    }
    return sum;
}

int main() {
    int N;
    cin >> N;
    cout << stairs_num(N) % 1000000000;
    return 0;
}
