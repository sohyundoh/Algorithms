#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int M, N;
    cin >> M >> N;
    int snack[1000010];
    int high = 0;
    for (int i = 0; i < N; i++) {
        cin >> snack[i];
        high = max(high, snack[i]);
    }
    int low = 1;

    long long caneat = 0;
    while (low < high) {
        int mid = (low + high + 1) / 2;
        for (int i = 0; i < N; i++) {
            caneat += snack[i] / mid;
        }
        if (caneat >= M) {
            low = mid;
        } else if (caneat < M) {
            high = mid - 1;
        }
        caneat = 0;
    }
    int length = (low + high) / 2;
    for (int i = 0; i < N; i++) {
        caneat += snack[i] / length;
    }
    if(caneat >= M) cout<<length <<"\n";
    else cout << 0 << "\n";
    return 0;
}
