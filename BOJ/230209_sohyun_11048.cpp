#include <iostream>

#define MAX 1000
using namespace std;
int dx[3] = {0, 1, 1};
int dy[3] = {1, 0, 1};
int map[MAX][MAX];
int dp[MAX][MAX] = {0,};
int main() {
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
        }
    }
    dp[N-1][M-1] = map[N - 1][M - 1];

    for(int i = N-1; i>=0; i--){
        for(int j = M-1; j>= 0; j--){
            for (int k = 0; k < 3; k++) {
                int nx = i + dx[k];
                int ny = j + dy[k];
                if (nx < N && ny < M) {
                    dp[i][j] = max(dp[i][j], map[i][j] + dp[nx][ny]);
                }
            }
        }
    }
    cout<< dp[0][0];
    return 0;
}
