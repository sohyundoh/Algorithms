#include <iostream>
#define MAX 5001
#define MOD 1000000

using namespace std;

int arr[MAX];
int DP[MAX];
string s;

int dp_func() {
    if (s.length() == 1 && s[0] == '0') {
        cout << 0 << "\n";
        exit(0);
    }
    DP[0] = 1;
    for (int i = 1; i <= s.length(); i++) {
        if (arr[i] >= 1 && arr[i] <= 9) {
            DP[i] = (DP[i - 1] + DP[i]) % MOD;
        }
        if (i == 1) continue;
        int temp = arr[i] + arr[i - 1] * 10;
        if (temp >= 10 && temp <= 26) {
            DP[i] = (DP[i - 2] + DP[i]) % MOD;
        }
    }
    return DP[s.length()] % MOD;
}

int main() {
    cin >> s;
    for (int i = 1; i <= s.length(); i++) {
        arr[i] = s[i - 1] - '0';
    }
    cout << dp_func() << "\n";
}
