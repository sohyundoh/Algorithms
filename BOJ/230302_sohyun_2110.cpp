#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> router;

int main() {
    int N, C;
    cin >> N >> C;
    for (int i = 0; i < N; i++) {
        int input;
        cin >> input;
        router.push_back(input);
    }
    sort(router.begin(), router.end());
    int low = 1, high = router[N - 1] - router[0];
    int result = 0;
    while (low <= high) {
        int num = 1;
        int mid = (low + high) / 2;
        int start = router[0];

        for (int i = 1; i < N; i++) {
            int end = router[i];

            if (end - start >= mid) {
                num++;
                start = end;
            }
        }
        if (num >= C) {
            low = mid + 1;
            result = max(result, mid);
        } else {
            high = mid - 1;
        }
    }
    cout << result;
    return 0;
}
