#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool map[10001][10001] = {false,};
bool visited[10001][10001] = {false,};
int N, M;
vector<int> v;
int cnt = 1;
void dfs(int c) {
    for (int i = 1; i <= N; i++) {
        if (map[c][i] == true && !visited[c][i]) {
            visited[c][i] = true;
            cnt ++;
            dfs(i);
            visited[c][i] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        map[b][a] = true;
    }
    int max = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (map[i][j] == true && !visited[i][j]) {
                visited[i][j] = true;
                dfs(j);
                visited[i][j] = false;
                int k = cnt;
                if (max <= k) {
                    max = k;
                    v.push_back(i);
                }
            }
            cnt = 1;
        }
    }
    sort(v.begin(), v.end());
    for (int j = 0; j < v.size(); j++) {
        cout << v[j] << " ";
    }
    return 0;
}
