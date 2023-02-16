#include <iostream>
#define MAX 90
using namespace std;

long long dp[MAX] ={1, 1,};
long long numOfOne[MAX] = {1, 0};
long long numOfZero[MAX] = {0, 1};
long long DP_FUNC(int N){
    for(int i = 2 ;i<N;i++){
        numOfOne[i] = numOfZero[i-1];
        numOfZero[i] = numOfOne[i-1] + numOfZero[i-1];
        dp[i] =  numOfOne[i] + numOfZero[i];
    }
    return dp[N-1];
}
int main(){
    int N;
    cin>>N;
    cout<< DP_FUNC(N);
    return 0;
}
