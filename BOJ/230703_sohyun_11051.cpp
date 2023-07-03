#include <iostream>
#define MOD 10007

using namespace std;


long long DP[1001][1001];
void combination(int N){
    DP[0][0] = 1;
    DP[1][0] = 1;
    DP[1][1] = 1;

    for (int i = 2; i <= N; i++)
        for (int j = 0; j <= i; j++)
        {
            if (j == 0) DP[i][0] = 1;
            else if (j == i) DP[i][j] = 1;
            else DP[i][j] = (DP[i - 1][j - 1] + DP[i - 1][j]) % MOD;
        }
}
int main(){
    int N, K;
    cin >> N >> K;
    combination(N);
    cout << DP[N][K];
    return 0;
}
