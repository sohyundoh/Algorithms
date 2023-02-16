#include <iostream>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long N;
    cin >> N;
    int *input = new int[N];
    int *dp = new int[N];
    int m;
    for (int i = 0; i < N; i++) {
        cin >> input[i];
        if (i != 0) {
            dp[i] = max(input[i] + input[i - 1], dp[i-1] + input[i]);
            dp[i] = max( input[i], dp[i]);
            m = max(m, dp[i]);
        }else{
            dp[0] = input[0];
            m = dp[0];
        }
    }
    m = max(m, input[N-1]);
    cout << m;
    return 0;
}
