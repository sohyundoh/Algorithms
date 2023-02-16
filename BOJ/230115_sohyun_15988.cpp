#include <iostream>
#define MAX 1000001
using namespace std;

long long dp[MAX] = {0,1,2,4};
int idx = 4;
long long dp_func(int n){
    for(int i = idx; i<=n;i++) {
        dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3])%1000000009;
        idx++;
    }
    return (dp[n]);
}
int main() {
    int T;
    cin >> T;
    for(int i = 0; i < T ;i++){
        int n;
        cin >> n;
        cout<< dp_func(n) << "\n";
    }
    return 0;
}
