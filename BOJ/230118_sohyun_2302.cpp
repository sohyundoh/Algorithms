#include <iostream>
#define MAX 41
using namespace std;

int n, cnt_vip;
int dp[MAX];
int vip[MAX];

void DP_FUNC(){
    dp[0] = dp[1] = 1;

    for (int i = 2; i <= n; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
}

int case_cnt(){
    int res = 1;

    for (int i = 1; i <= cnt_vip; i++){
        res *= dp[vip[i] - vip[i-1] - 1];
    }

    return res *= dp[n - vip[cnt_vip]];
}
void solution(){

    cin >> n;

    DP_FUNC();	// n까지 피보나치 수열 미리 계산하기
    
    cin >> cnt_vip;

    for (int i = 1; i <= cnt_vip; i++){
        cin >> vip[i];
    }

    cout << case_cnt() << '\n';

}
int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solution();

    return 0;
}
