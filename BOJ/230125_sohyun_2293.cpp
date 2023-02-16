#include <iostream>
#define N_MAX 101
#define K_MAX 10001

using namespace std;

int dp[K_MAX] = {1,};
int arr[N_MAX] = {};
int N, K;
int dp_func(){
    for (int i = 0; i < N; i++) { //각 동전에 대해
        for (int j = arr[i]; j <= K; j++) {
            dp[j] +=dp[j - arr[i]];
        }
    }
    return dp[K];
}
int main() {
    cin >> N >> K;
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    cout<<dp_func() << "\n";
    return 0;
}
