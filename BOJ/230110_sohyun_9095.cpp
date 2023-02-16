#include <iostream>
/*
* 1,2,3 더하기 (silver3) - 동적게획법(다이나믹 프로그래밍)
*/
using namespace std;

int dp[10] = {0};

void print_func(int T){
    for(int i = 0; i < T ;i++){
        int n;
        cin >> n;
        cout << dp[n] << "\n";
    }
}
void dp_set(){
    int dp[10] = {0,1,2,4};
    for(int i = 4; i< 11; i++){
     dp[i] = dp[i-1]+dp[i-2]+dp[i-3];
    }
}
int main() {
    int T;
    cin >> T;
    dp_set();
    print_func(T);
    return 0;
}
