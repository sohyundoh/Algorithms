#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<string> v(n);
    vector<ll> answer;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        reverse(v[i].begin(), v[i].end());
        answer.push_back(stoll(v[i]));
    }
    sort(answer.begin(), answer.end());
    for (int i = 0; i < n; i++) {
        cout << answer[i] << "\n";
    }
}
