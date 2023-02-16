#include <iostream>
#define MAX 500

using namespace std;
int v[MAX][MAX] = {0,};
int dp[MAX][MAX] = {0,};

/*
 * 1932
 * 정수 삼각형
 *
 * 풀이 방법
 * buttom up 방식으로 해결
 */

int dp_func(int N){
    for(int i = 0; i<N;i++){
        dp[N-1][i] = v[N-1][i];
    }
    for(int j = N-2; j >= 0; j--){
        for(int k = 0; k <= j; k++){
            if(dp[j+1][k] > dp[j+1][k+1]){
                dp[j][k] = v[j][k] + dp[j+1][k];
            }else{
                dp[j][k] = v[j][k] + dp[j+1][k+1];
            }
        }
    }
    return dp[0][0];
}
int main(){
    int N;
    cin >> N;
    for(int i = 0; i<N;i++){
        for(int j = 0; j<=i; j++){
            cin >> v[i][j];
        }
    }
    cout<<dp_func(N);
    return 0;
}
