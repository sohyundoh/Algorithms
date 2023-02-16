#include <iostream>

#define MAX 300
using namespace std;
int stairs[MAX] = {0,};
int visited[MAX] = {0,};
int dp[MAX] = {0,};
int visit(int N) {
    dp[1] = stairs[1];
    dp[2] = stairs[2] + stairs[1];
    if(stairs[3] + stairs[2] > stairs[3] + stairs[1]){
        dp[3] = stairs[3] + stairs[2];
    }else{
        dp[3] = stairs[3] + stairs[1];
    }
    for (int i = 4; i <= N; i++) {
        dp[i] = dp[i-2]+stairs[i] > stairs[i-1]+stairs[i]+dp[i-3]? dp[i-2]+stairs[i]:stairs[i-1]+stairs[i]+dp[i-3] ;
    }
    return dp[N];
}
int main() {
    int N;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> stairs[i];
    }
    cout << visit(N);
}
