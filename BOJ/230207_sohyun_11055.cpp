#include <iostream>
#define MAX 1001

using namespace std;
int dp[MAX] = {0,};

int main(){
    int N;
    cin >> N;
    int* A = new int[N];
    for(int i = 0 ; i< N; i++){
        cin >> A[i];
    }
    dp[0] = A[0];
    for(int i = 1; i< N; i++){
        dp[i] = A[i]; // 왜 맞았는지 모르겠음. => dp[i]는 "마지막 원소가 A[i]인 증가 부분 수열 중에서 가장 합이 큰 것의 총합"을 의미하고, 말씀하신 16번째 줄은 원소가 1개인 증가 부분 수열을 고려하기 위해 필요합니다.
        for(int j = 0; j<i; j++){
            if(A[i]> A[j]){
                dp[i] = max(dp[i], dp[j] + A[i]);
            }
        }
    }
    int big = dp[0];
    for(int i = 1; i<N; i++){
        big = max(big, dp[i]);
    }
    cout<< big;
    return 0;
}
