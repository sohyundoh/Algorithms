#include <iostream>
#define MAX 101

using namespace std;
long long dp[MAX] = {1,1,1,2,2,};

void wave_array(){
    for(int i = 5; i <100; i++){
        dp[i] = dp[i-1] + dp[i-5];
    }
}

int main(){
    int T;
    cin >> T;
    wave_array();
    for(int i = 0; i<T; i ++){
        int N;
        cin >> N;
        cout<< dp[N-1] << '\n';
    }
    return 0;
}
//줄 바꿈 안해서 틀렸습니다 나오는 것을... 화가 나서 포기할 뻔 했습니다.
