#include<iostream>

using namespace std;

int dp[100000][3];
int mod = 9901;

int main(){
    int n;
    cin >> n;
    dp[1][0] = 1;
    dp[1][1] = 1;
    dp[1][2] = 1;
    for(int i =2; i<=n; i++){
        //동물을 놓을 수 있는 방법은 o x, x o, x x 가 가능(한 행에 o는 사자를 넣고, x는 안넣는 것) 각각 0, 1, 2,라고 하면
        //마지막 행에 0이 오면 그 전 행에는 1, 2가 올 수 있음
        //마지막 행에 1이 오면 그 전 행에는 0, 2 과 올 수 있다.
        //마지막 행에 2가 오면 그 전 행에는 0, 1, 2 모두 가능하다. 
        //이 방법을 top down 방식으로 구현
        dp[i][0] = (dp[i-1][1] + dp[i-1][2]) % mod;
        dp[i][1] =  (dp[i-1][0] + dp[i-1][2])%mod ;
        dp[i][2] = (dp[i-1][0] + dp[i-1][1] + dp[i-1][2])%mod;
    }
    cout<< (dp[n][0] + dp[n][1] + dp[n][2])%mod;
    return 0;
};
