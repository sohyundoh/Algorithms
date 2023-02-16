#include <iostream>

#define N_MAX 1024
using namespace std;
int N;

int map[N_MAX + 1][N_MAX + 1];
long long dp[N_MAX + 1][N_MAX + 1];

void dp_func() {
    for (int i = 1; i <= N; i++) {
        int sum = 0;
        for (int j = 1; j <= N; j++) {
            sum += map[i][j];
            dp[i][j] = sum;
//            cout<< "i:"<< i <<" j: " << j<<" sum " << sum <<" ";
        }
//        cout<< "\n";
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> N;
    int M;
    cin >> M;
    map[0][0] = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> map[i][j];
        }
    }
    dp_func();
    for (int i = 0; i < M; i++) {
        int sx, sy;
        int ex, ey;
        cin >> sx >> sy >> ex >> ey;
        int sum = 0;
        for (int i = sx ; i <= ex; i++) {
//            cout<< dp[i][ey]<<" "<< dp[i][sy-1]<<"\n";
            sum += dp[i][ey] - dp[i][sy-1];
        }
        cout<< sum <<"\n";
    }
    return 0;
}
