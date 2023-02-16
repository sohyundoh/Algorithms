#include <iostream>
#define MOD 1000000000
using namespace std;

long long dp[2000001];
void fibonacci_dp(int N) {
    dp[0] = 0;
    dp[1] = 1;
    dp[1000001] = 1;
    dp[1000002] = -1;
    if (N < 0) {
        for (int i = 3; i <= abs(N); i++) {
            dp[1000000 + i] = (dp[1000000 + i - 2] %MOD - dp[1000000 + i - 1]%MOD)%MOD;
        }
    }else if(N >= 0){
        for(int i = 2 ; i<= N; i++){
            dp[i] = (dp[i-1]%MOD + dp[i-2]%MOD)%MOD;
        }
    }
}

int main() {
    int N;
    cin >> N;
    fibonacci_dp(N);
    if(N<0) N = 1000000-N;
    if(dp[N] <0) {
        cout<<"-1"<<"\n";
        cout<<abs(dp[N]);
    }else{
        if(dp[N] == 0) cout<< "0"<<"\n";
        else cout<<"1"<<"\n";
        cout<< dp[N];
    }
    return 0;
}
