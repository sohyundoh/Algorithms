#include <iostream>

using namespace std;
int N;
int map[100][100];
long long dp[100][100];

long long recursive(int x, int y) {
    if (x < 0 || x >= N || y < 0 || y >= N) return 0;
    if (x == N - 1 && y == N - 1) return 1;
    if (map[x][y] == 0) return 0;
    if (dp[x][y] != -1) return dp[x][y];
    return dp[x][y] = recursive(x + map[x][y], y) + recursive(x, y + map[x][y]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
            dp[i][j] = -1;
        }
    }
    cout << recursive(0, 0);
    return 0;
}
