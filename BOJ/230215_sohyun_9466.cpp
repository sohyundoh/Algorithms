#include <iostream>
#include <cstring>

using namespace std;


bool visited[100001];
bool hasCycle[100001];
int partner[100001];
int cnt;

void dfs(int k) {
    visited[k] = true;

    int next = partner[k];

    if (!visited[next]) {
        dfs(next);
    } else if (!hasCycle[next]) {
        for (int i = next; i != k; i = partner[i]) {
            cnt++;
        }
        cnt++;
    }
    hasCycle[k] = true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {

        int N;
        cin >> N;

        memset(visited, false, N+1);
        memset(hasCycle, false, N+1);

        for (int j = 1; j <= N; j++) {
            cin >> partner[j];
        }
        for (int k = 1; k <= N; k++) {
            if (!visited[k]) {
                dfs(k);
            }
        }
        cout << N - cnt << "\n";
        cnt = 0;
    }
    return 0;
}
